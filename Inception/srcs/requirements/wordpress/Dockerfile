FROM alpine:3.19

# Install required packages and PHP extensions
RUN apk update && apk add --no-cache \
        php82 \
        php82-fpm \
        php82-mysqli \
        php82-json \
        php82-opcache \
        php82-gd \
        php82-zlib \
        php82-xml \
        php82-phar \
        php82-mbstring \
        php82-curl \
        php82-session \
        php82-zip \
        mariadb-client \
        curl \
        bash

# Install WordPress CLI
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# Set up the document root
WORKDIR /var/www/html

# Copy PHP-FPM configuration file
COPY ./conf/php-fpm.conf /etc/php82/php-fpm.d/www.conf
COPY ./tools/docker-entrypoint.sh /usr/local/bin

RUN chmod +x /usr/local/bin/docker-entrypoint.sh

# Set permissions
RUN chown -R nobody:nobody /var/www/html

EXPOSE 9000

ENTRYPOINT [ "/usr/local/bin/docker-entrypoint.sh" ]

CMD [ "php-fpm82", "-F" ]
