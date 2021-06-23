#!/bin/sh
RED='\033[0;31m'
ORANGE='\033[0;33m'
GREEN='\033[0;32m'
MODE=$(id -u)
if [ $MODE -ne "0" ]; then 
echo "${RED}Please run as root${RED}"
  exit
fi
echo "${ORANGE}Stop local services ...\n${ORANGE}" 
#sudo su 
service nginx stop 
service mysql stop 
echo "${GREEN}nginx and mysql service stopped with SUCCESS\n${GREEN}" 
echo "${ORANGE}set env value on the launchpad ...\n${ORANGE}" 
source srcs/.env
echo "${GREEN}Env Values set with success\n${GREEN}" 
echo "${ORANGE}change the hosts file ...\n${ORANGE}" 
echo '127.0.0.1 junghan.42.fr' >> /etc/hosts 
echo '127.0.0.1 www.junghan.42.fr' >> /etc/hosts 
echo "${GREEN}Your host file as changed for this project !${GREEN}  ${ORANGE}Don't forget to run the clean script after the correction !${ORANGE}\n" 
echo "${ORANGE}Shutdown docker properly ... ${ORANGE}\n" 
docker-compose down 
docker system prune 
echo "${ORANGE}Removing the data folder ...\n${ORANGE}" 
if [ -d "~/data/" ]; then 
echo "${GREEN}Data folder was found ! it's now clean ${GREEN}\n" 
rm -rf ~/data/
fi 
echo "${ORANGE}restarting Docker service ... ${ORANGE}\n" 
service docker restart 
echo "${GREEN}Well done, you can start the correction, don't forget the clean script at the end\n${GREEN}"
