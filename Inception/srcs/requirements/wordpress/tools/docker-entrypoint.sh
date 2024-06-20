#!/bin/sh
set -e

# Change to the WordPress directory
cd /var/www/html

if [ ! -f wp-load.php ]; then
    echo "Downloading WordPress..."
    wp core download --allow-root
fi

for i in {30..0}; do
  if timeout 10s mysqladmin ping -h "$WORDPRESS_DB_HOST" --silent; then
    break
  fi
  echo 'Waiting for MySQL...'
  sleep 2
done

if [ "$i" = 0 ]; then
  echo >&2 'MySQL not available after 30 attempts, exiting.'
  exit 1
fi

# Check if wp-config.php exists, if not create it
if [ ! -f wp-config.php ]; then
  echo "Creating wp-config.php..."
  wp config create \
    --dbname="$MYSQL_DATABASE" \
    --dbuser="$MYSQL_USER" \
    --dbpass="$MYSQL_PASSWORD" \
    --dbhost="$WORDPRESS_DB_HOST" \
    --allow-root 
fi

# Check if WordPress is installed, if not install it
if ! wp core is-installed --allow-root; then
  echo "Installing WordPress..."
  wp core install \
    --url="$WORDPRESS_URL" \
    --title="$WORDPRESS_TITLE" \
    --admin_user="$WORDPRESS_ADMIN_USER" \
    --admin_password="$WORDPRESS_ADMIN_PASSWORD" \
    --admin_email="$WORDPRESS_ADMIN_EMAIL" \
    --skip-email \
	--allow-root

  wp user create $WORDPRESS_USER $WORDPRESS_USER_EMAIL \
	--user_pass=$WORDPRESS_USER_PASSWORD \
	--role=author \
	--allow-root
fi



echo "Start php-fpm82"
# Keep the container running
exec "$@"