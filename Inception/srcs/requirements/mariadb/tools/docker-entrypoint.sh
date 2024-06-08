#!/bin/sh

set -e

if [ ! -f /var/lib/mysql/.initialized ]; then
    echo 'Initializing database...'
    mysql_install_db --user=root --datadir=/var/lib/mysql
    chown -R mysql:mysql /var/lib/mysql
    echo 'Database initialized'

    echo 'Starting temporary MariaDB server...'
	mysqld_safe --skip-networking --user=root &
    pid="$!"

    mysql_cmd="mysql --protocol=socket -uroot"

    for i in {30..0}; do
        if echo 'SELECT 1' | $mysql_cmd &> /dev/null; then
            break
        fi
        echo 'MariaDB init process in progress...'
        sleep 1
    done

    if [ "$i" = 0 ]; then
        echo >&2 'MariaDB init process failed.'
        exit 1
    fi

    echo "Creating user and database..."
    $mysql_cmd <<EOSQL
        SET @@SESSION.SQL_LOG_BIN=0;
        CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\`;
        CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
        GRANT ALL ON \`$MYSQL_DATABASE\`.* TO '$MYSQL_USER'@'%';
        FLUSH PRIVILEGES;
EOSQL

    if [ ! -z "$MYSQL_ROOT_PASSWORD" ]; then
        $mysql_cmd <<EOSQL
            ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
EOSQL
    fi

    echo 'Stopping temporary MariaDB server...'
	mysqladmin --protocol=socket -uroot -p$MYSQL_ROOT_PASSWORD shutdown
	
    sleep 5

    touch /var/lib/mysql/.initialized
    echo 'MariaDB init process done. Ready for start up.'
fi

exec "$@"
