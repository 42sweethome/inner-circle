#!/bin/sh

echo  "\033[47;35m--Remove images and containers--\033[0m\n"

docker-compose down 
docker system prune -a

echo  "\033[44;33m@@@It's all been erased@@@\033[0m\n\n"

echo "\033[47;35m--Setting for environment variable load--\033[0m\n"

source ../../.env

echo  "\033[44;33m@@@It's set up@@@\033[0m\n\n"

echo  "\033[47;35m--Host conversion operation to replace DNS--\033[0m\n"

echo '127.0.0.1 junghan.42.fr' >> /etc/hosts 
echo '127.0.0.1 www.junghan.42.fr' >> /etc/hosts 

echo  "\033[44;33m@@@Host is set up@@@\033[0m\n\n"
