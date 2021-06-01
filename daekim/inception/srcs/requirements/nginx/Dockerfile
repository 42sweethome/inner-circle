FROM debian:buster

RUN		apt-get update
RUN		apt-get -y update

RUN		atp-get -y install vim wget curl nginx openssl

RUN		openssl req -x509 -nodes -days 365 -newkey rsa:4096 -subj "/C=KR/ST=Gyeonggi/L=Seongnam/O=42seoul/OU=Gun/CN=localhost" -keyout /etc/ssl/private/localhost.dev.key -out /etc/ssl/certs/localhost.dev.crt 

# 설정 파일을 Docker 내부로 복사
COPY ./tools/default.conf /etc/nginx/conf.d/default.conf

# Docker Host로 포트 번호 노출
EXPOSE 80

# 백그라운드에서 실행
ENTRYPOINT ["nginx","-g","daemon off;"]
