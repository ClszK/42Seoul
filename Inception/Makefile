DOCKER_COMPOSE = docker-compose -f srcs/docker-compose.yml
DOCKER_BUILD = docker build
DOCKER_RUN = docker run
DOCKER_EXEC = docker exec
DOCKER_RM = docker rm
DOCKER_RMI = docker rmi
DOCKER_PS = docker ps

.PHONY: all build up down clean fclean re

all: build up

build:
	mkdir -p /home/${USER}/data/mariadb
	mkdir -p /home/${USER}/data/wordpress
	$(DOCKER_COMPOSE) build

up:
	$(DOCKER_COMPOSE) up

down:
	$(DOCKER_COMPOSE) down

clean:
	$(DOCKER_COMPOSE) down --rmi all

fclean: clean
	rm -rf /home/${USER}/data/*

re: fclean all 

build-mariadb:
	$(DOCKER_BUILD) -t custom-mariadb srcs/requirements/mariadb

build-nginx:
	$(DOCKER_BUILD) -t custom-nginx srcs/requirements/nginx

build-wordpress:
	$(DOCKER_BUILD) -t custom-wordpress srcs/requirements/wordpress

run-mariadb:
	$(DOCKER_RUN) -d --name mariadb custom-mariadb

run-nginx:
	$(DOCKER_RUN) -d --name nginx custom-nginx

run-wordpress:
	$(DOCKER_RUN) -d --name wordpress custom-wordpress

logs:
	$(DOCKER_COMPOSE) logs -f

ps:
	$(DOCKER_PS)
