FROM	debian:buster

RUN		apt-get update
RUN		apt-get -y upgrade

RUN		apt-get -y install vim wget php-fpm php-mysql

RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN		tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN		mv phpMyAdmin-5.0.2-all-languages phpmyadmin
RUN		mv phpmyadmin /var/www/html/
COPY	./srcs/config.inc.php ./phpmyadmin

RUN		wget https://wordpress.org/latest.tar.gz
RUN		tar -xvf latest.tar.gz
RUN		mv wordpress/ var/www/html/
COPY	./srcs/wp-config.php /var/www/html/wordpress

RUN		chown -R www-data:www-data /var/www/html/wordpress


CMD		service mysql start;\
		service php7.3-fpm start;\
		echo "CREATE USER 'daekim'@'localhost' identified by '';" | mysql -u root --skip-password;\
		echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password;\
		echo "GRANT ALL PRIVILEGES ON *.* TO 'daekim'@'localhost' IDENTIFIED BY '123456' WITH GRANT OPTION" | mysql -u root --skip-password ;\
 	 	echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password;\
		service nginx start;\
		sleep inf
