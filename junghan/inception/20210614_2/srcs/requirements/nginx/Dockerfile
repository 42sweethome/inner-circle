FROM alpine:3.12
LABEL maintainer "junghan <junghan@student.42seoul.kr>"
RUN apk update && apk upgrade

# install nginx
RUN apk add nginx

# set ssl
RUN apk add openssl
RUN apk add openrc
RUN openssl req -newkey rsa:2048 \
			-x509 \
			-sha256 \
			-days 3650 \
			-nodes \
			-out /etc/ssl/certs/www.junghan.42.fr.crt \
			-keyout /etc/ssl/private/www.junghan.42.fr.key \
			-subj "/C=KR/ST=Seoul/L=Seoul/O=42seoul/OU=inception/CN=www.junghan.42.fr" && \
			chmod 600 /etc/ssl/certs/www.junghan.42.fr.crt /etc/ssl/private/www.junghan.42.fr.key
COPY ./tools/hosts /etc/
COPY ./conf/nginx.conf /etc/nginx/conf.d/www.junghan.42.fr.conf
RUN rm -f /etc/nginx/conf.d/default.conf
COPY ./tools/index.html /var/www/html/
RUN mkdir /var/www/junghan.42.fr/
COPY ./tools/index.html /var/www/junghan.42.fr/
RUN mkdir /run/nginx

RUN rc-update add nginx default

# expose ports
EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
