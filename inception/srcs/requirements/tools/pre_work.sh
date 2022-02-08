#!/bin/sh

echo -e "\e[47;35m--Remove images and containers--\e[0m\n"

docker-compose down 
docker system prune -a

echo -e "\e[44;33m@@@It's all been erased@@@\e[0m\n\n"

echo -e "\e[47;35m--Setting for environment variable load--\e[0m\n"

source ../../.env

echo -e "\e[44;33m@@@It's set up@@@\e[0m\n\n"

echo -e "\e[47;35m--Host conversion operation to replace DNS--\e[0m\n"

echo '127.0.0.1 doyun.42.fr' >> /etc/hosts 
echo '127.0.0.1 www.doyun.42.fr' >> /etc/hosts 

echo -e "\e[44;33m@@@Host is set up@@@\e[0m\n\n"
