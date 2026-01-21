
# Image release and update

## Build image

docker build -t <docker-repo>/mukurtucms:<mukurtu-version>-<revision> .

Example:

docker build -t cbenning/mukurtucms:2.1.3-1 .

## Push / Release image

docker push cbenning/mukurtucms:2.1.3-1

# Deploy 

## Database Service

docker network create mukurtu

docker create \
	--name mukurtu-mariadb \
	--network mukurtu \
	--restart unless-stopped \
	-e MYSQL_ROOT_PASSWORD=my-root-password \
	mariadb:10.1.44-bionic

docker start mukurtu-mariadb

## Customer Database setup (Per customer)

docker exec -it mukurtu-mariadb bash 

mysql -u root -p
CREATE DATABASE mukurtu;
CREATE USER mukurtu-customer-name IDENTIFIED BY 'my-mukurtu-password';
GRANT SELECT, INSERT, UPDATE, DELETE, CREATE, DROP, INDEX, ALTER, CREATE TEMPORARY TABLES ON mukurtu.* TO mukurtu;
quit
exit

## Mukurtu service

Decide a path you want the container to store it's configuration for easy access
mkdir /my/unique/config/path 

Example:
mkdir /home/admin/customer1

docker create \
	--name mukurtu \
	--network mukurtu \
	--restart unless-stopped \
	-p 8080:80 \
	-v /my/unique/config/path:/var/www/ \
	cbenning/mukurtucms:2.1.3-1

docker start mukurtu

## Mukurtu Setup

Go to: http://localhost:8080
Enter details, DB hostname should be `mukurtu-mariadb`, DB name should be mukurtu-customer-name (whatever you setup)

# Multi-customer deployment setup

NGINX:https/443 (TLS)
 |
 customer1.domain.com -> docker:mukuru:http:8080 |
 customer2.domain.com -> docker:mukuru:http:8081 -> docker:mukurtu-mariadb (shared)
 customer3.domain.com -> docker:mukuru:http:8082 |
 customerN.domain.com -> ...                     
  
 





