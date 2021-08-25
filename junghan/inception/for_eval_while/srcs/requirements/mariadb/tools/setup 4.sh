if [ ! -d "/var/lib/mysql/wordpress" ]; then 
    
    mysql_install_db
    service mysql start
    
    mysql -e "CREATE USER '${MARIA_ID}'@'localhost' identified by '${MARIA_PW}';" &&\
	mysql -e "CREATE DATABASE IF NOT EXISTS wordpress;" &&\
	mysql -e "GRANT ALL PRIVILEGES ON *.* TO '${MARIA_ID}'@'%' IDENTIFIED BY '${MARIA_PW}';" &&\
	mysql -e "UPDATE mysql.user SET Password = PASSWORD('${MARIA_PW}') WHERE User = 'root'" &&\
	mysql -e "FLUSH PRIVILEGES;"
    service mysql stop 
fi

mysqld
