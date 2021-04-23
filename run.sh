#!/bin/bash
#docker run -it -p 80:80 -p 443:443 --name doyun debian:buster

#touch bestdoyun.txt

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/ O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
mv chown -R www-data:www-data /var/www/html/wordpress

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
rm chown -R www-data:www-data /var/www/html/wordpress

docker cp -rp ./srcs/default doyun:/etc/nginx/site-available/
docker cp -rp ./srcs/config.ini.php doyun:/var/www/html/phpmyadmin/
docker cp -rp ./srcs/wp-config.php doyun:/var/www/html/wordpress/

service nginx start
service mysql start
service php7.3-fpm start

bash
