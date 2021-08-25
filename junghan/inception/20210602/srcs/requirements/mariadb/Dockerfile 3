FROM alpine:3.12

RUN apk update && apk upgrade && \
	apk add mariadb mariadb-client && \
	apk add openrc && \
	mkdir -p /run/mysqld/

COPY	./tools/my.cnf			/etc/mysql
COPY ./tools/run.sh		./
COPY ./tools/website			/usr/share/nginx/html

RUN chmod 775 run.sh
RUN mkdir /run/openrc && touch /run/openrc/softlevel

# Expose ports
EXPOSE 3306

CMD sh ./run.sh;\
