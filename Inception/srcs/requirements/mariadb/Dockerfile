FROM alpine:3.19

RUN apk update && apk add --no-cache mariadb mariadb-client
RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld
RUN mkdir -p /usr/local/bin && chmod 755 /usr/local/bin

EXPOSE 3306

COPY ./tools/docker-entrypoint.sh /usr/local/bin/docker-entrypoint.sh
COPY ./conf/my.cnf /etc/my.cnf

RUN chmod +x /usr/local/bin/docker-entrypoint.sh

ENTRYPOINT [ "/usr/local/bin/docker-entrypoint.sh" ]
CMD ["mysqld_safe", "--user=root"]