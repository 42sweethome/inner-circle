#!/bin/bash

#권한 설정

mysql;
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "CREATE USER IF NOT EXISTS 'sonkang'@'localhost' IDENTIFIED BY '';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON *.* TO 'sonkang'@'localhost' IDENTIFIED BY '1111' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password;
