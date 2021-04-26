openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gun/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt /etc/ssl/certs/
mv localhost.dev.key /etc/ssl/private/
chmod 600 /etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key


wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/


wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress


cp /tmp/default /etc/nginx/sites-available
cp /tmp/config.inc.php /var/www/html/phpmyadmin
cp /tmp/wp-config.php /var/www/html/wordpress


service mysql start
mysql < /var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password
mysql -e "CREATE DATABASE IF NOT EXISTS wordpress";
mysql -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'daekim'@'localhost' IDENTIFIED BY '123456' WITH GRANT OPTION";


service php7.3-fpm start
service nginx start

bash
