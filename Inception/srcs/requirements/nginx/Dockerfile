FROM	alpine:3.19

# 빌드 시점에서 사용될 매개 변수
ARG		SSL_KEY_DIR = ${SSL_KEY_DIR}

# 환경 변수
ENV		DOMAIN_NAME = ${DOMAIN_NAME}
ENV		SSL_KEY_DIR = ${SSL_KEY_DIR}
ENV		SSL_KEY_PATH = ${SSL_KEY_PATH}
ENV		SSL_CERT_PATH = ${SSL_CERT_PATH}
ENV		SSL_SUBJ = ${SSL_SUBJ}

RUN		apk update && apk --no-cache add nginx openssl
RUN		mkdir -p /etc/nginx/conf.d ${SSL_KEY_DIR}

COPY	./conf/nginx.conf /etc/nginx/nginx.conf
COPY	./conf/default.conf /etc/nginx/conf.d/default.conf

RUN		openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
		-keyout ${SSL_KEY_PATH} -out ${SSL_CERT_PATH} \
		-subj ${SSL_SUBJ}

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]