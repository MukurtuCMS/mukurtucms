<?php
// output the top wizard of the dashboard

$attribs = array('query'=>array('destination'=>$_GET['q']), 'attributes' => array('class' => array('btn','btn-default')));
$toggle_link = l('Hide Wizard', 'wizard/toggle', $attribs);

?>
<a href="<?php echo url('dashboard'); ?>" class="btn btn-default">Return to Dashboard</a>
<?php echo $toggle_link; ?>
<div id="tabs" class="wizard-tabs">
  <ul>
    <li><a href="#tabs-1">1. Orientation</a></li>
    <li><a href="#tabs-2">2. Site Setup</a></li>
    <li><a href="#tabs-3">3. Communities</a></li>
    <li><a href="#tabs-4">4. Cultural Protocols</a></li>
    <li><a href="#tabs-5">5. Categories</a></li>
    <li><a href="#tabs-6">6. Digital Heritage</a></li>
    <li><a href="#tabs-7">7. Users</a></li>
  </ul>

  <!-- Orientation -->
  <div id="tabs-1">
    <h3>Welcome to your Site Dashboard. Let's start with a dashboard orientation...</h3>
    <p>This is your administrative dashboard. Only you and other administrators will be able to access these panels. You may use them to manage all the features of Mukurtu. If you find yourself needing help at any time, make your way back to this dashboard by clicking ‘dashboard’ in the top right corner of your screen.</p>

    <p>Notice how the boxes below correspond to different functions you can perform as a site administrator. In the following steps and videos, we will walk through some of these features together.</p>

    <p>To get started, click the '<a href="#tabs-2" class="interlink">Site Setup</a>' tab and start setting up your Mukurtu Site. To leave this wizard at any time, click 'hide wizard' above.</p>
  </div>


  <!-- Site Set Up -->
  <div id="tabs-2">
    <h3>Basic Site Setup - Adding site info, changing site logos</h3>
    <p>In the panels below, locate the box labelled 'Set up Site'. Here you can find links to change the look and feel of your site.</p>

    <p>Start by clicking 'Change site name, slogan, and email address'. Here you take the first steps to making Mukurtu CMS truly yours. You can visit this page any time to change the default email, however we recommend you set up an email for your site which is connected to your organization, that way it does not fall on one person's shoulders for responsibility.</p>

    <p>From this panel you may also change your logo, edit your about page, edit your menus, header and footer content.</p>

    <p>To move forward with your orientation, click the '<a href="#tabs-3" class="interlink">Communities</a>' tab and set up some communities. To leave this wizard at any time, click 'hide wizard' above.</p>
  </div>

  <!-- Communities -->
  <div id="tabs-3">


    <h3>Configuring Communities</h3>

    <span class="video-help-embedded"><iframe src="https://player.vimeo.com/video/123257330" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe></span>

    <p>In the panels below, locate the box labelled 'Communities and Protocols'. We will be using this block for our next two lessons.</p>

    <p>Communities and Protocols are at the Core of your Mukurtu CMS. Communities group together site users: the WHO of Mukurtu. Through membership in communities, users can interact with and join cultural protocols. Cultural Protocols are HOW content is shared between people.</p>

    <p>Please watch the video on the right to learn:</p>
    <ul>
      <li>How to create and edit a community</li>
      <li>How to add media to your community page</li>
      <li>Default cultural protocols within a community</li>
      <li>How to add members to your community</li>
      <li>Roles in a community</li>
    </ul>

    <p>To move forward with your orientation, click the '<a href="#tabs-4" class="interlink">Cultural Protocols</a>' tab to learn about Cultural Protocols. To leave this wizard at any time, click 'hide wizard' above.
    </p>

  </div>

  <!-- Cultural Protocols -->
  <div id="tabs-4">
    <h3>Configuring Protocols</h3>

    <span class="video-help-embedded"><iframe src="https://player.vimeo.com/video/123257729" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe></span>

    <p>Cultural Protocols help define how content is shared within your Mukurtu CMS. Cultural Protocols can be added within each community you create and must be nested within a parent community. When you create a new community, a default cultural protocol is generated for sharing content within your community only. Notice that any time a member is added to your community, they are also added to this protocol.</p>

      <p>When you add a cultural protocol, keep in mind that this is a portal through which users will access your content. Like a community, the cultural protocol has a name, description, and images, but it also has a sharing protocol and a parent community. The sharing protocol is the default sharing setting for any content within the cultural protocol. If you select 'open', digital heritage items will be accessible to any site visitor. If you select 'strict' digital heritage items will be accessible to cultural protocol members only. If you have reached this form via a community page, the parent community will be selected for you. You can select a parent community from any community you administer.</p>

      <p>Please watch the video on the right to learn:</p>
      <ul>
        <li>How to create and edit a cultural protocol</li>
        <li>How to add members to your cultural protocol</li>
        <li>Roles in a cultural protocol</li>
        <li>How to set up and use protocols to share content</li>
      </ul>

      <p>To move forward with your orientation, click '<a href="#tabs-5" class="interlink">Categories</a>' tab to learn about Categories. To leave this wizard at any time, click 'hide wizard' above.</p>
  </div>

  <!-- Categories -->
  <div id="tabs-5">
    <h3>Working with Categories</h3>
    
    <p>Search and browse terms like categories and keywords not only help users locate specific digital heritage items, they link together similar kinds of digital heritage items, and aid users in discovering other items of interest.</p>

    <p>Sometimes, creating an entire list of categories in your CMS before working with content is a lot of responsibility to handle, so we have added a few recommendations below to get you started. These categories are a combination of the categories used in the first two instances of Mukurtu.</p>

    <p>Check the list by finding the Categories box below and click ‘manage categories’, if you would like to edit or delete a category, simply click ‘edit’ on the same line as the category you wish to change. On the next screen, either make edits and save changes, or delete.</p>

    <p>You can also add a category anytime by clicking “+category” or by visiting the category box on your dashboard.</p>

    <p>To move forward with your orientation, click '<a href="#tabs-6" class="interlink">Digital Heritage</a>' tab to learn about Digital Heritage. To leave this wizard at any time, click 'hide wizard' above.</p>
  </div>

  <!-- DH Items -->
  <div id="tabs-6">
    <h3>Working with Media Assets and Digital Heritage Items</h3>

    <span class="video-help-embedded"><iframe src="https://player.vimeo.com/video/123257917" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe></span>

    <p>A digital heritage (DH) item is a single item of content in your Mukurtu CMS. A DH item must have a title, community, cultural protocol, and category associated with it, listed here in the Mukurtu Essentials tab. Most users also add one or more media items to their digital heritage, and additional metadata available in the following tabs: Mukurtu Core, Rights and Permissions, Additional Metadata, and Relations.</p>

    <p>Please watch the video on the right to learn more about building and curating digital heritage items.</p>

    <p>For more information about filling in these fields at any time, hover above a field to see any help text.</p>

    <p>To move forward with your orientation, click '<a href="#tabs-7" class="interlink">Users</a>' tab to learn about Users. To leave this wizard at any time, click 'hide wizard' above.</p>
  </div>

  <!-- Users -->
  <div id="tabs-7">

    <h3>Adding People and User Management</h3>

    <span class="video-help-embedded"><iframe src="https://player.vimeo.com/video/123258147" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe></span>

    <p>Mukurtu CMS is all about sharing knowledge, stories, and histories within and between communities. Now that you know a bit about each component of a Mukurtu CMS site, let's talk about the people who make content and information meaningful by accessing, retelling, and sharing the items you contribute to your CMS. To add one or more users, click add user in the Site Users block below.</p>

    <p>Most users will be 'authenticated users', but you may grant a select few roles as administrators and curators. The site admin, curator, and authenticated roles are sitewide, however there are other roles which allow users to participate in communities and protocols and their experience in these cultural protocol groups will change depending on the group membership. The only role that cannot participate in communities is the curator. Curators are responsible for the site wide aesthetic and the experience of anonymous users. As your site becomes more robust, you may find that you use your site admin responsibilities less and less, and your communities, content, and sharing will take on a life of its own.</p>

    <p>Check out the video on the right to learn more.</p>

  </div>
</div>