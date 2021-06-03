FROM alpine:3.12
LABEL maintainer "junghan <junghan@student.seoul42.kr>"
RUN apk update && apk upgrade

RUN apk add openrc


RUN apk add nginx
RUN apk add wget
RUN apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session php7-ctype



WORKDIR /tmp/
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz && \
		mv wordpress /var/www/html/ && \
		rm latest.tar.gz
COPY ./wp-config.php /var/www/html/wp-config.php
WORKDIR /


COPY ./fastcgi_params /etc/nginx/fastcgi_params
COPY ./wp_php_server.conf /etc/nginx/conf.d/wp_php_server.conf


COPY ./setup.sh /tmp/setup.sh
RUN chmod -u+x /tmp/setup.sh

EXPOSE 5050

CMD ["./tmp/setup.sh"]
