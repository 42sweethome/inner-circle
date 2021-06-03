#!/bin/bash

#권한 설정
chmod -R 755 /var/www/
chmod 775 /run.sh

openssl req -newkey rsa:2048 -nodes -x509 -days 365 -subj "/C=KR/ST=Seoul/L=Seoul/O=42seoul/OU=Gon/CN=junghan" -keyout localhost.dev.key -out localhost.dev.crt 

mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

# Wordpress 설치
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
cp -rp ./wp-config.php /var/www/html/wordpress


echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "CREATE USER IF NOT EXISTS 'sonkang'@'localhost' IDENTIFIED BY '';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON *.* TO 'sonkang'@'localhost' IDENTIFIED BY '1111' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password;
