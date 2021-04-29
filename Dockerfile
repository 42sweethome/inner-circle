FROM			debian:buster

RUN				apt-get update && apt-get -y upgrade &&\
				apt-get -y install nginx\
				openssl\
				vim\
				php-fpm\
				mariadb-server\
				php-mysql\
				wget

RUN				wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz &&\
				tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz &&\
				mv phpMyAdmin-5.0.2-all-languages phpmyadmin &&\
				mv phpmyadmin /var/www/html &&\
				rm phpMyAdmin-5.0.2-all-languages.tar.gz

RUN				wget https://wordpress.org/latest.tar.gz &&\
				tar -xvf latest.tar.gz &&\
				mv wordpress /var/www/html &&\
				chown -R www-data:www-data /var/www/html/wordpress &&\
				rm latest.tar.gz


COPY			./srcs/default ./etc/nginx/sites-available/default
COPY			./srcs/wp-config.php ./var/www/html/wordpress/
COPY			./srcs/config.inc.php ./var/www/html/phpmyadmin/
COPY			./run.sh ./


EXPOSE 			80 443

CMD				bash ./run.sh
