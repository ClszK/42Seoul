#!/bin/sh

CONF_PATH="/etc/nginx/conf.d"

envsubst '\$DOMAIN_NAME \$SSL_KEY_PATH \$SSL_CERT_PATH' \
			< ${CONF_PATH}/default.conf.template \
			> ${CONF_PATH}/default.conf

rm -f ${CONF_PATH}/default.conf.template /docker-entrypoint.sh

exec "$@"
