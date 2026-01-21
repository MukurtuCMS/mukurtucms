FROM drupal:7.69-apache

# Set correct environment variables
ENV MUKURTU_VERSION 2.1.3
ENV MUKURTU_DIR mukurtucms-${MUKURTU_VERSION}
ENV DRUPAL_VERSION 7.69

WORKDIR /var/www

RUN apt-get update && apt-get -y upgrade 
RUN apt-get -y install wget
RUN wget https://github.com/MukurtuCMS/mukurtucms/archive/${MUKURTU_VERSION}.tar.gz \
	&& tar xf ${MUKURTU_VERSION}.tar.gz
RUN ln -s /var/www/${MUKURTU_DIR} /var/www/mukurtu \
	&& cp -r /var/www/html/* /var/www/mukurtu/ \
	&& cp /var/www/html/.htaccess /var/www/mukurtu/ \
	&& chown -R www-data:www-data /var/www/mukurtu/ \
	&& sed -i "s/DocumentRoot \/var\/www\/html/DocumentRoot \/var\/www\/mukurtu/g" /etc/apache2/sites-enabled/000-default.conf

