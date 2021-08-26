FROM	debian:buster

RUN		apt-get update
RUN		apt-get upgrade -y

RUN		apt-get -y install vim wget mariadb-server php-mysql

RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN		tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN		mv phpMyAdmin-5.0.2-all-languages phpmyadmin
COPY	./tools/config.inc.php /phpmyadmin

CMD		service mysql start;\
		echo "CREATE USER IF NOT EXISTS 'daekim'@'localhost' identified by '';" | mysql -u root --skip-password;\
		echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password;\
		echo "GRANT ALL PRIVILEGES ON *.* TO 'daekim'@'localhost' IDENTIFIED BY '123456' WITH GRANT OPTION" | mysql -u root --skip-password ;\
 	 	echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password;\

