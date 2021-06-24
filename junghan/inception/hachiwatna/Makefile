NAME = inception
START_PATH = ./srcs/

all: purge setup reload

setup:
	@ cd $(START_PATH)/requirements/tools && sudo sh launchpad.sh
	
stop:
	@ cd $(START_PATH) && docker-compose down; 

clean: stop
	@ cd $(START_PATH) && docker system prune; 

purge: clean
	@  rm -Rf ~/data/;

reload: 
	@ cd $(START_PATH) &&  docker-compose up --build ; 

 

.PHONY: setup stop clean purge reload all 
