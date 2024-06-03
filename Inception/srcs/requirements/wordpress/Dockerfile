FROM	alpine:3.19

RUN		addgroup -S www-data && adduser -S -G www-data www-data

RUN		apk update && apk add --no-cache \
		php7 \
		php7-fpm \
		php7-mysqli \
		php7-json \
		php7-curl \
		php7-xml \
		php7-mbstring \
		php7-dom \
		php7-session \
		php7-zlib \
		php7-opcache \
		php7-gd \
		php7-zip \
		curl \
		tar \
		mariadb-client \
		&& rm -rf /var/cache/apk/*

COPY	./conf/php-fpm.conf /etc/php7/php-fpm.d/www.conf

RUN		curl -O https://wordpress.org/latest.tar.gz && \
		tar -zxvf latest.tar.gz && \
		mv wordpress /var/www/html && \
		chown -R www-data:www-data /var/www/html && \
		rm latest.tar.gz

COPY	./tools/wp-init.sh /usr/local/bin/wp-init.sh
RUN		chmod +x /usr/local/bin/wp-init.sh

EXPOSE	9000

CMD		["sh", "-c", "/usr/local/bin/wp-init.sh && php-fpm7 -F"]