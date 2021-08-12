FROM alpine


RUN apk add nginx php php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-xmlreader php7-zip php7-session php7-json php7-xml php7-simplexml php7-dom php7-pdo php7-pdo_mysql php7-mbstring php7-tokenizer mariadb mariadb-client --no-cache

#RUN apk add mysql && \
#	apk add mariadb && \
#	apk	add php-fpm && \
#	rm -rf /var/cache/apk/* &&\
#	chown -R mysql /var/lib/mysql &&\
#	chown -R mysql /var/tmp &&\
#	mkdir /run/mysqld &&\
#	chown -R mysql /run/mysqld &&\
#	mysql_install_db --user=mysql --datadir=/var/lib/mysql

COPY ./tools/run.sh ./

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./conf/default.conf /etc/nginx/conf.d/default.conf
COPY ./conf/ssl.conf /etc/nginx/conf.d/ssl.conf

COPY ./tools/website /usr/share/nginx/html

# Expose ports
EXPOSE 80 443

CMD sh ./run.sh;\
