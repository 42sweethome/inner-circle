FROM debian:buster

MAINTAINER doyun@student.42seoul.kr

RUN apt-get update
RUN apt-get install -y mariadb-server vim ; 

COPY tools/setup.sh . 
RUN chmod +x setup.sh 

EXPOSE 3306
RUN rm /etc/mysql/mariadb.conf.d/50-server.cnf 
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d 
ENTRYPOINT ["bash", "/setup.sh"]