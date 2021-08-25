
sleep 8;
if  [ ! -f /var/www/wordpress/wp-config.php ]; then 
    
    wp core --allow-root download --locale=ko_KR --force 
    sleep 5;
    while  [ ! -f /var/www/wordpress/wp-config.php ]; do   

        
        wp core config --allow-root --dbname=wordpress --dbuser=$MARIA_ID --dbpass=$MARIA_PW --dbhost=mariadb:3306
        

    done 
    wp core install --allow-root --url='junghan.42.fr' --title='WordPress for Inception' --admin_user=$WP_ID --admin_password=$WP_PW  --admin_email="junghan@student.42seoul.kr" --path='/var/www/wordpress';
    wp  user create --allow-root $WP_USER_ID user2@user.com --user_pass=$WP_USER_PW --role=author
    wp theme install --allow-root dark-mode --activate     
fi 
php-fpm7.3 --nodaemonize
