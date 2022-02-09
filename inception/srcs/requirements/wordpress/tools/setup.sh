#!/bin/bash

for ((i=100; i>=0; i--))
do
	echo -e "\e[31mloading...\e[0m\n"
done

if  [ ! -f /var/www/wordpress/wp-config.php ]; then 
    
	for ((i=10000; i>=0; i--))
	do
		echo -e "\e[31mloading123...\e[0m\n"
	done

    wp core --allow-root download --locale=ko_KR --force 
    while  [ ! -f /var/www/wordpress/wp-config.php ]; do

        wp core config --allow-root --dbname=wordpress --dbuser=${MARIA_ID} --dbpass=${MARIA_PW} --dbhost=mariadb:3306

	done 
    wp core install --allow-root --url='doyun.42.fr' --title='Welcome to doyun`s Inception' --admin_user=${WP_ID} --admin_password=${WP_PW}  --admin_email="doyun@student.42seoul.kr" --path='/var/www/wordpress';
    wp  user create --allow-root ${WP_USER_ID} gkswndaud@gmail.com --user_pass=${WP_USER_PW} --role=author 
fi 

php-fpm7.3 --nodaemonize
