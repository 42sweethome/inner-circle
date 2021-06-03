FROM alpine:3.12
LABEL maintainer "junghan <junghan@student.42seoul.kr>"
RUN apk update && apk upgrade


RUN apk add nginx


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
COPY ./nginx.conf /etc/nginx/conf.d/nginx_service.conf
RUN rm -f /etc/nginx/conf.d/default.conf
COPY ./index.html /var/www/html/
RUN mkdir /run/nginx


EXPOSE 80 443

CMD ["nginx", "-g", "daemon off;"]
