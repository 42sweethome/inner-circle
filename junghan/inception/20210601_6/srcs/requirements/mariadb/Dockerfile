FROM alpine

RUN apk add mysql && \
	apk add php-fpm && \
	rm -rf /var/cache/apk/*

COPY ./tools/run.sh ./

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./conf/default.conf /etc/nginx/conf.d/default.conf
COPY ./conf/ssl.conf /etc/nginx/conf.d/ssl.conf

COPY ./tools/website /usr/share/nginx/html


# Expose ports
EXPOSE 80 443

CMD sh ./run.sh;\
