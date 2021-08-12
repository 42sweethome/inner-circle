FROM alpine

RUN apk add mysql && \
	rm -rf /var/cache/apk/*

COPY ./tools/run.sh ./

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./conf/default.conf /etc/nginx/conf.d/default.conf
COPY ./conf/ssl.conf /etc/nginx/conf.d/ssl.conf

COPY ./tools/website /usr/share/nginx/html

RUN addgroup mysql mysql

# Expose ports
EXPOSE 80 443

CMD bash ./run.sh;\
