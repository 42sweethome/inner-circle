#!/bin/sh

mkdir -p /run/php-fpm7/
mkdir -p /run/nginx/
mkdir -p /run/openrc/
#touch /run/php-fpm7/softlevel
#touch /run/nginx/softlevel
#touch /run/openrc/softlevel

rc-update add php-fpm7 default
rc-update add nginx default
rc-status default
rc-service php-fpm7 start
nginx -g "daemon off;"
