FROM alpine:3.12
LABEL maintainer "junghan <junghan@student.42seoul.kr>"
RUN apk update && apk upgrade

# install nginx
RUN apk add nginx

# set ssl
RUN apk add openssl
RUN openssl req -newkey rsa:2048 \
			-x509 \
			-sha256 \
			-days 3650 \
			-nodes \
			-out /etc/ssl/certs/nginx-selfsigned.crt \
			-keyout /etc/ssl/private/nginx-selfsigned.key \
			-subj "/C=KR/ST=Seoul/L=Seoul/O=42seoul/OU=inception/CN=localhost" && \
			chmod 600 /etc/ssl/certs/nginx-selfsigned.crt /etc/ssl/private/nginx-selfsigned.key
COPY ./conf/nginx.conf /etc/nginx/conf.d/nginx_service.conf
RUN rm -f /etc/nginx/conf.d/default.conf
COPY ./tools/index.html /var/www/html/
RUN mkdir /run/nginx

# expose ports
EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
