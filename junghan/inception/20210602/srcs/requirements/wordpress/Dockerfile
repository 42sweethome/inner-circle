FROM alpine:3.12

RUN apk update && \
	apk upgrade && \
	apk add php-fpm php7 php7-fpm php7-opcache php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session php7-ctype && \
	apk add wget && \
	apk add openrc && \
	apk add nginx && \
	rm -rf /var/cache/apk/*

COPY ./tools/run.sh ./

COPY ./tools/wp-config.php ./
COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./conf/default.conf /etc/nginx/conf.d/default.conf
COPY ./conf/ssl.conf /etc/nginx/conf.d/ssl.conf

COPY ./tools/website /usr/share/nginx/html

RUN chmod 777 run.sh

# Expose ports
EXPOSE 9000

CMD sh ./run.sh;\
