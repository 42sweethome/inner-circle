From debian:buster

Maintainer doyun@student.42seoul.kr

RUN apt-get update
RUN apt-get install -y nginx openssl vim curl
RUN rm /etc/nginx/sites-available/default
RUN rm /etc/nginx/sites-enabled/default

COPY conf/nginx.conf /etc/nginx/sites-available/default 
#default를 nginx.conf로 바꿀까?

RUN ln -s /etc/nginx/sites-available/default /etc/nginx/sites-enabled/default

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -days 365 -nodes \
    -out /etc/nginx/ssl/www.doyun.42.fr.crt \
    -keyout /etc/nginx/ssl/www.doyun.42.fr.key \
    -subj "/C=KR/ST=SEOUL/O=42/OU=GUN/CN=doyun"
RUN chmod 777 /etc/nginx/ssl/*
RUN chmod 777 -R /var/www
#www 파일 내에 다른 폴더 혹은 파일을 추가 삭제 하기 위함인거 같음 
#nginx.conf 파일 내에 root 설정을 위해 해주는 것 같음
#지우고 한번 실행 해보자~

EXPOSE 443
cmd nginx service start
cmd /bin/bash
#ENTRYPOINT ["nginx","-g","daemon off;"]