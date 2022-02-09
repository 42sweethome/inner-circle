NAME = inception

all: setup build

install:
	cd ./srcs/requirements/tools && sudo sh set_for_docker.sh

setup:
	cd ./srcs/requirements/tools && sudo bash pre_work.sh

build: 
	cd ./srcs/ && docker-compose up -d --build; 
	
stop:
	cd ./srcs/ && docker-compose down; 

volrm:
	cd ./srcs/ && docker volume prune;

clean: stop
	cd ./srcs/ && docker system prune -a; 

fclean: clean
	sudo rm -Rf ~/data/;

.PHONY: install setup build stop volrm clean fclean all
