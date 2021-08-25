#!/bin/bash

#권한 설정
chmod -R 755 /var/www/
chmod 775 /run.sh

openssl req -newkey rsa:2048 -nodes -x509 -days 365 -subj "/C=KR/ST=Seoul/L=Seoul/O=42seoul/OU=Gon/CN=junghan" -keyout localhost.dev.key -out localhost.dev.crt 

mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

