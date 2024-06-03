FROM	alpine:3.19

RUN		apk update && apk --no-cache add nginx openssl
RUN		mkdir -p /etc/nginx/conf.d /etc/nginx/ssl

COPY	./conf/nginx.conf /etc/nginx/nginx.conf
COPY	./conf/default.conf /etc/nginx/conf.d/default.conf

RUN		openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
		-keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt \
		-subj "/CN=jeholee.login.fr"

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]