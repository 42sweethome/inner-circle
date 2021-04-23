FROM			debian:buster

RUN				apt-get update && apt-get -y upgrade\
				nginx\
				openssl\
				vim\
				php-fpm\
				mariadb-server\
				php-mysql\
				wget

EXPOSE 			80 443

CMD				bash run.sh
