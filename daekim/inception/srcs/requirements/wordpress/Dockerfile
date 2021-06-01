FROM	debian:buster

RUN		apt-get update
RUN		apt-get -y upgrade

RUN		apt-get -y install wget



RUN		wget https://wordpress.org/latest.tar.gz
RUN		tar -xvf latest.tar.gz
COPY	./tools/wp-config.php /wordpress

RUN		chown -R www-data:www-data wordpress


