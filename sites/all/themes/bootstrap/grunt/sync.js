module.exports = function (grunt) {
  'use strict';

  // Register the 'sync' task.
  grunt.registerTask('sync', 'Syncs necessary libraries for development purposes. Read more in: MAINTAINERS.md.', function () {
    var cwd = process.cwd();
    var force = grunt.option('force');
    var path = require('path');
    var pkg = require('../package');
    var mapSeries = require('promise-map-series');
    var simpleJsonRequest = require('simple-json-request');
    var semver = require('semver');
    var getJson = function (uri) {
      return simpleJsonRequest.get({url: uri});
    };

    // Internal variables.
    var libraries = {};
    var librariesCache = path.join(cwd, pkg.caches.libraries);
    var librariesPath = path.join(cwd, pkg.paths.libraries);
    var exists = grunt.file.exists(librariesCache);
    var expired = false;

    // Determine the validity of any existing cached libraries file.
    if (!force && exists) {
      grunt.verbose.write('Cached library information detected, checking...');
      var fs = require('fs');
      var stat = fs.statSync(librariesCache);
      var now = new Date().getTime();
      var expire = new Date(stat.mtime);
      expire.setDate(expire.getDate() + 7); // 1 week
      expired = now > expire.getTime();
      grunt.verbose.writeln((expired ? 'EXPIRED' : 'VALID')[expired ? 'red' : 'green']);
    }

    var getApiV1Json = function ($package) {
      var $json = {name: $package, assets: []};
      var $latest = '0.0.0';
      var $versions = [];
      return getJson('https://data.jsdelivr.com/v1/package/npm/' + $package)
        .catch(function (error) {
          if (!(error instanceof Error)) {
            error = new Error(error);
          }
          grunt.verbose.error(error);
        })
        .then(function ($packageJson) {
          if (!$packageJson) {
            $packageJson = {versions: []};
          }
          if ($packageJson.versions === void 0) {
            $packageJson.versions = [];
          }
          return mapSeries($packageJson.versions, function ($version, $key) {
            // Skip irrelevant versions.
            if (!$version.match(/^3\.\d+\.\d+$/)) {
              return Promise.resolve();
            }
            return getJson('https://data.jsdelivr.com/v1/package/npm/' + $package + '@' + $version + '/flat')
              .then(function ($versionJson) {
                // Skip empty files.
                if (!$versionJson.files || !$versionJson.files.length) {
                  return;
                }

                $versions.push($version);
                if (semver.compare($latest, $version) === -1) {
                  $latest = $version;
                }

                var $asset = {files: [], version: $version};
                $versionJson.files.forEach(function ($file) {
                  // Skip old bootswatch file structure.
                  if ($package === 'bootswatch' && $file.name.match(/^\/2|\/bower_components/)) {
                    return;
                  }
                  var $matches = $file.name.match(/([^/]*)\/bootstrap(-theme)?(\.min)?\.(js|css)$/, $file['name']);
                  if ($matches && $matches[1] !== void 0 && $matches[4] !== void 0 && $matches[1] !== 'custom') {
                    $asset.files.push($file.name);
                  }
                });
                $json.assets.push($asset);
                $json.lastversion = $latest;
                $json.versions = $versions;
              })
          });
        })
        .then(function () {
          return $json;
        });
    };

    // Register a private sub-task. Doing this inside the main task prevents
    // this private sub-task from being executed directly and also prevents it
    // from showing up on the list of available tasks on --help.
    grunt.registerTask('sync:api', function () {
      var done = this.async();
      mapSeries(['bootstrap', 'bootswatch'], function ($package) {
        return getApiV1Json($package);
      }).then(function (json) {
        grunt.verbose.write("\nExtracting versions and themes from libraries...");
        libraries = {};
        json.forEach(function (library) {
          if (library.name === 'bootstrap' || library.name === 'bootswatch') {
            library.assets.forEach(function (asset) {
              if (asset.version.match(/^3.\d\.\d$/)) {
                if (!libraries[library.name]) libraries[library.name] = {};
                if (!libraries[library.name][asset.version]) libraries[library.name][asset.version] = {};
                asset.files.forEach(function (file) {
                  if (!file.match(/bootstrap\.min\.css$/)) return;
                  if (library.name === 'bootstrap') {
                    libraries[library.name][asset.version]['bootstrap'] = true;
                  }
                  else {
                    libraries[library.name][asset.version][file.split(path.sep).filter(Boolean)[0]] = true;
                  }
                });
              }
            });
          }
        });
        grunt.verbose.ok();

        // Flatten themes.
        for (var library in libraries) {
          grunt.verbose.header(library);
          if (!libraries.hasOwnProperty(library)) continue;
          var versions = Object.keys(libraries[library]);
          grunt.verbose.ok('Versions: ' + versions.join(', '));
          var themeCount = 0;
          for (var version in libraries[library]) {
            if (!libraries[library].hasOwnProperty(version)) continue;
            var themes = Object.keys(libraries[library][version]).sort();
            libraries[library][version] = themes;
            if (themes.length > themeCount) {
              themeCount = themes.length;
            }
          }
          grunt.verbose.ok(grunt.util.pluralize(themeCount, 'Themes: 1/Themes: ' + themeCount));
        }
        grunt.verbose.writeln();
        grunt.file.write(librariesCache, JSON.stringify(libraries, null, 2));

        grunt.log.ok('Synced');

        done();
      });
    });

    // Run API sync sub-task.
    if (!exists || force || expired) {
      if (!exists) grunt.verbose.writeln('No libraries cache detected, syncing libraries.');
      else if (force) grunt.verbose.writeln('Forced option detected, syncing libraries.');
      else if (expired) grunt.verbose.writeln('Libraries cache is over a week old, syncing libraries.');
      grunt.task.run(['sync:api']);
    }

    // Register another private sub-task.
    grunt.registerTask('sync:libraries', function () {
      var bower = require('bower');
      var done = this.async();
      var inquirer =  require('inquirer');
      var queue = require('queue')({concurrency: 1, timeout: 60000});
      if (!grunt.file.exists(librariesCache)) {
        return grunt.fail.fatal('No libraries detected. Please run `grunt sync --force`.');
      }
      libraries = grunt.file.readJSON(librariesCache);
      var bowerJson = path.join(cwd, 'bower.json');
      if (!grunt.file.isDir(librariesPath)) grunt.file.mkdir(librariesPath);

      // Iterate over libraries.
      for (var library in libraries) {
        if (!libraries.hasOwnProperty(library)) continue;

        // Iterate over versions.
        for (var version in libraries[library]) {
          if (!libraries[library].hasOwnProperty(version)) continue;

          var endpoint = library + '#' + version;

          // Check if library is already installed. If so, skip.
          var versionPath = path.join(librariesPath, version);
          grunt.verbose.write('Checking ' + endpoint + '...');
          if (grunt.file.isDir(versionPath) && grunt.file.isDir(versionPath + '/' + library)) {
            grunt.verbose.writeln('INSTALLED'.green);
            continue;
          }

          grunt.verbose.writeln('MISSING'.red);
          grunt.file.mkdir(versionPath);
          grunt.file.copy(bowerJson, path.join(versionPath, 'bower.json'));

          var config = {
            cwd: versionPath,
            directory: '',
            interactive: true,
            scripts: {
              postinstall: 'rm -rf jquery && rm -rf font-awesome'
            }
          };

          // Enqueue bower installations.
          (function (endpoint, config) {
            queue.push(function (done) {
              bower.commands
                .install([endpoint], {saveDev: true}, config)
                .on('log', function (result) {
                  if (result.level === 'action' && result.id !== 'validate' && !result.message.match(/(jquery|font-awesome)/)) {
                    grunt.log.writeln(['bower', result.id.cyan, result.message.green].join(' '));
                  }
                  else if (result.level === 'action') {
                    grunt.verbose.writeln(['bower', result.id.cyan, result.message.green].join(' '));
                  }
                  else {
                    grunt.log.debug(['bower', result.id.cyan, result.message.green].join(' '));
                  }
                })
                .on('prompt', function (prompts, callback) {
                  inquirer.prompt(prompts, callback);
                })
                .on('end', function () { done() })
              ;
            });
          })(endpoint, config);
        }
      }

      // Start bower queue.
      queue.start(function (e) {
        return done(e);
      });
    });

    // Run private sub-task.
    grunt.task.run(['sync:libraries']);
  });

}
