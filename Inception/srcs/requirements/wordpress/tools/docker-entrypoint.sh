#!/bin/sh
set -e

# Change to the WordPress directory
cd /var/www/html

if [ ! -f wp-load.php ]; then
    echo "Downloading WordPress..."
    wp core download --allow-root
fi

# Check if wp-config.php exists, if not create it
if [ ! -f wp-config.php ]; then
  echo "Creating wp-config.php..."
  wp config create \
    --dbname="$WORDPRESS_DB_NAME" \
    --dbuser="$WORDPRESS_DB_USER" \
    --dbpass="$WORDPRESS_DB_PASSWORD" \
    --dbhost="$WORDPRESS_DB_HOST" --allow-root 
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
    --skip-email --allow-root
fi

echo "Start php-fpm82"
# Keep the container running
exec "$@"
