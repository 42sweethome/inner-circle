 ME = inception

all: clean setup build

setup:
	cd ./srcs/requirements/tools && sudo bash pre_work.sh

build: 
	cd ./srcs/ && docker-compose up --build ; 
	
stop:
	cd ./srcs/ && docker-compose down; 

volrm:
	cd ./srcs/ && docker volume prune;

clean: stop
	cd ./srcs/ && docker system prune -a; 

fclean: clean
	sudo rm -Rf ~/data/;

.PHONY: setup build stop volrm clean fclean all
