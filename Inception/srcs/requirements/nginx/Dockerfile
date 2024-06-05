FROM	alpine:3.19

# 빌드 시점에서 사용될 매개 변수
ARG		SSL_KEY_DIR
ARG		SSL_KEY_PATH
ARG		SSL_CERT_PATH
ARG		SSL_SUBJ

# 환경 변수
ENV		DOMAIN_NAME=${DOMAIN_NAME}
ENV		SSL_KEY_PATH=${SSL_KEY_PATH}
ENV		SSL_CERT_PATH=${SSL_CERT_PATH}

RUN		apk update && apk --no-cache add nginx openssl gettext
RUN		mkdir -p /etc/nginx/conf.d ${SSL_KEY_DIR}

COPY	./conf/nginx.conf /etc/nginx/nginx.conf
COPY	./conf/default.conf.template /etc/nginx/conf.d/default.conf.template
COPY	./tools/docker-entrypoint.sh /docker-entrypoint.sh

RUN		chmod +x /docker-entrypoint.sh
RUN		openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
		-keyout ${SSL_KEY_PATH} -out ${SSL_CERT_PATH} \
		-subj "$SSL_SUBJ"

EXPOSE	443

ENTRYPOINT [ "/docker-entrypoint.sh" ]
CMD		["nginx", "-g", "daemon off;"]