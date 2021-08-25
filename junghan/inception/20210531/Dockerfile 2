FROM alpine
RUN apk add --update nginx && rm -rf /var/cache/apk/ \
RUN apk add openssl
RUN	apk add vim
RUN apk add bash 

RUN mkdir -p /tmp/nginx/client-body

COPY ./srcs/run.sh ./
COPY nginx/nginx.conf /etc/nginx/nginx.conf
COPY nginx/default.conf /etc/nginx/conf.d/default.conf
COPY website /usr/share/nginx/html

CMD bash ./run.sh;\
	nginx -g "daemon off;"
