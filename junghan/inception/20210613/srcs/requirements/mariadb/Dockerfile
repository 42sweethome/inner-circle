FROM alpine:3.12
LABEL maintainer "junghan <junghan@student.seoul42.kr>"
RUN apk update && apk upgrade

# install openrc
RUN apk add openrc

# expose a port
EXPOSE 3306

# install mariadb mariadb-client
RUN apk add mariadb mariadb-client

# config file for mariadb

RUN mkdir -p /run/mysqld
COPY ./my.cnf /etc/mysql/

# initialize for phpmyadmin
#COPY ./create_tables.sql /tmp/create_tables.sql
#COPY ./wordpress_copy.sql /tmp/wordpress.sql
COPY ./mysql-init.sql /tmp/mysql-init.sql
COPY ./setup.sh /tmp/
RUN chmod 775 /tmp/setup.sh


# initialize openrc
RUN mkdir /run/openrc && touch /run/openrc/softlevel

CMD ["./tmp/setup.sh"]
