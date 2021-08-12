#! /bin/sh

cd /usr/bin/

# Install MariaDB database(mariadb-install-db is a symlink to mysql_install_db).

mysql_install_db --user=root
# Invoking "mysqld" will start the MySQL server. Terminating "mysqld" will shutdown the MySQL server.


mysqld -u root

# Create Wordpress database.
mysqld -u root --execute="CREATE DATABASE wordpress;"

# Import previously backed up database to MariaDB database server (wordpress < /wordpress.sql).

# Create new user "root" with password "toor" and give permissions.
mysqld -u root --execute="CREATE USER 'root'@'%' IDENTIFIED BY 'root'; GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION; USE wordpress; FLUSH PRIVILEGES;"

# Start Telegraf and sleep infinity for avoid container to stop.

mysqld
