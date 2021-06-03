FROM alpine

RUN apk update && \
	apk upgrade && \
	apk add --update nginx && \
	apk add vim && \
	apk add openssl && \
	apk add bash && \
	rm -rf /var/cache/apk/*

RUN mkdir -p /tmp/nginx/client-body

COPY ./srcs/run.sh ./
COPY nginx/nginx.conf /etc/nginx/nginx.conf
COPY nginx/common.conf /etc/nginx/common.conf
COPY nginx/default.conf /etc/nginx/conf.d/default.conf
COPY website /usr/share/nginx/html
COPY nginx/ssl.conf /etc/nginx/conf.d/ssl.conf


# Expose ports
EXPOSE 80 443

CMD bash ./run.sh;\
	nginx -g "daemon off;"
