#!/bin/bash

if [ ! -d "/var/lib/mysql/wordpress" ]; then 
   chown -R root:root /var/lib/mysql
#    chown -R ovar/lib/mysql 
#    mysql_install_db
	mysql_install_db --user=mysql \
	--basedir=/usr \
	--datadir=/var/lib/mysql
    service mysql start
    
    mysql -e "CREATE USER '${MARIA_ID}'@'localhost' identified by '${MARIA_PW}';"
	mysql -e "CREATE DATABASE IF NOT EXISTS wordpress;"
	mysql -e "GRANT ALL PRIVILEGES ON *.* TO '${MARIA_ID}'@localhost IDENTIFIED BY '${MARIA_PW}';"
	mysql -e "GRANT ALL PRIVILEGES ON *.* TO '${MARIA_ID}'@'%' IDENTIFIED BY '${MARIA_PW}';"
	mysql -e "UPDATE mysql.user SET Password = PASSWORD('${MARIA_PW}') WHERE User = 'root';"
	mysql -e "FLUSH PRIVILEGES;"
    mysqladmin -uroot -p${MARIA_PW} shutdown
#sevice mysql stop
fi

#mysqld
#mysql -u root -p${MARIA_PW} -S /var/run/mysqld/mysqld.sock
#chmod -R 755 /var/run/mysqld
ln -s /run/mysqld/mysqld.sock /var/run/mysqld/mysqld.sock
exec mysqld_safe
#/usr/bin/mysqld_safe --datadir='var/lib/mysql'
