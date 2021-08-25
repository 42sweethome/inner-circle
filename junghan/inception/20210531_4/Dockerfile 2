FROM alpine

RUN apk update && \
	apk upgrade && \
	apk add --update nginx && \
	apk add vim && \
	apk add openssl && \
	apk add bash && \
	rm -rf /var/cache/apk/*

COPY ./srcs/run.sh ./

COPY nginx/nginx.conf /etc/nginx/nginx.conf
COPY nginx/default.conf /etc/nginx/conf.d/default.conf
COPY nginx/ssl.conf /etc/nginx/conf.d/ssl.conf

COPY website /usr/share/nginx/html



# Expose ports
EXPOSE 80 443

CMD bash ./run.sh;\
	nginx -g "daemon off;"
