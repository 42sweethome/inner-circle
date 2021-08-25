#!/bin/bash

#권한 설정
chmod -R 755 /var/www/

# Wordpress 설치
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
cp -rp ./wp-config.php /var/www/html/wordpress

rc-update add php-fpm7 default
rc-update add nginx default
rc-status default
rc-service php-fpm7 start
nginx -g "daemon off;"
