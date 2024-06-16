FROM	alpine:3.19

# 빌드 시점에서 사용될 매개 변수
ARG		SSL_KEY_DIR
ARG		SSL_KEY_PATH
ARG		SSL_CERT_PATH
ARG		SSL_SUBJ

RUN		apk update && apk --no-cache add nginx \
										 openssl \
										 gettext
RUN		mkdir -p /etc/nginx/conf.d ${SSL_KEY_DIR} /usr/local/bin
RUN		chmod 755 /usr/local/bin

COPY	./conf/nginx.conf /etc/nginx/nginx.conf
COPY	./conf/default.conf.template /etc/nginx/conf.d/default.conf.template
COPY	./tools/docker-entrypoint.sh /usr/local/bin/

RUN		chmod +x /usr/local/bin/docker-entrypoint.sh
RUN		openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
		-keyout ${SSL_KEY_PATH} -out ${SSL_CERT_PATH} \
		-subj "$SSL_SUBJ"

EXPOSE	443

ENTRYPOINT [ "/usr/local/bin/docker-entrypoint.sh" ]
CMD		["nginx", "-g", "daemon off;"]