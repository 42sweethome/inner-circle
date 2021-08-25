FROM alpine:3.12
LABEL maintainer "junghan <junghan@student.seoul42.kr>"
RUN apk update && apk upgrade

RUN apk add openrc


EXPOSE 3306

RUN apk add mariadb mariadb-client


RUN mkdir -p /run/mysqld
COPY ./my.cnf /etc/mysql/


COPY ./mysql-init.sql /tmp/mysql-init.sql
COPY ./setup.sh /tmp/
RUN chmod 775 /tmp/setup.sh



RUN mkdir /run/openrc 
# && touch /run/openrc/softlevel

CMD ["./tmp/setup.sh"]
