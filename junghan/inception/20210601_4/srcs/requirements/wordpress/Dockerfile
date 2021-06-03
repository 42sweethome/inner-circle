FROM alpine

RUN apk update && \
	apk upgrade && \
	apk add php-fpm && \
	apk add wget && \
	rm -rf /var/cache/apk/*

COPY ./tools/run.sh ./

COPY ./tools/wp-config.php ./

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./conf/default.conf /etc/nginx/conf.d/default.conf
COPY ./conf/ssl.conf /etc/nginx/conf.d/ssl.conf

COPY ./tools/website /usr/share/nginx/html


# Expose ports
EXPOSE 80 443

CMD sh ./run.sh;\
