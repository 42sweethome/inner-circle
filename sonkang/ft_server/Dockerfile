FROM	debian:buster

RUN		apt-get -y update && apt-get -y upgrade
RUN		apt-get -y install \
		nginx \
		openssl \
		vim \
		php-fpm \
		mariadb-server \
		php-mysql \
		wget

COPY	./srcs/run.sh ./
COPY	./srcs/default ./tmp
COPY	./srcs/config.inc.php ./tmp
COPY	./srcs/wp-config.php ./tmp

EXPOSE	80 443

CMD		bash run.sh
