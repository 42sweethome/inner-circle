FROM	debian:buster

LABEL	maintainer="daekim@student.42seoul.kr"

RUN		apt-get update
RUN		apt-get upgrade -y
#RUN		apt-get install -y --no-install-recommends apt-utils

RUN		apt-get -y install vim wget nginx openssl php-fpm mariadb-server php-mysql

#RUN		apt-get -y install wget
#RUN		apt-get -y install nginx
#RUN		apt-get -y install openssl
#RUN		apt-get -y install php-fpm
#RUN		apt-get -y install mariadb-server
#RUN		apt-get -y install php-mysql

COPY	./srcs/default ./tmp
COPY	./srcs/wp-config.php ./tmp
COPY	./srcs/config.inc.php ./tmp
COPY	./srcs/run.sh ./

EXPOSE	80 443

CMD		bash run.sh
