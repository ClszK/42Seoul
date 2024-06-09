DOCKER_COMPOSE = docker compose -f srcs/docker-compose.yml
DOCKER_EXEC = docker exec -it
DOCKER_PS = docker ps

all: build up

build:
	mkdir -p /home/${USER}/data/mariadb
	mkdir -p /home/${USER}/data/wordpress
	$(DOCKER_COMPOSE) build --parallel

up:
	$(DOCKER_COMPOSE) up

down:
	$(DOCKER_COMPOSE) down

clean:
	$(DOCKER_COMPOSE) down --rmi all

fclean: clean
	rm -rf /home/${USER}/data/*

re: fclean all 

run-mariadb:
	$(DOCKER_COMPOSE) up mariadb

run-nginx:
	$(DOCKER_COMPOSE) up nginx

run-wordpress:
	$(DOCKER_COMPOSE) up wordpress

exec-mariadb:
	$(DOCKER_EXEC) mariadb /bin/sh

exec-nginx:
	$(DOCKER_EXEC) nginx /bin/sh

exec-wordpress:
	$(DOCKER_EXEC) wordpress /bin/sh

logs:
	$(DOCKER_COMPOSE) logs -f

ps:
	$(DOCKER_PS)

.PHONY: all build up down clean fclean re
