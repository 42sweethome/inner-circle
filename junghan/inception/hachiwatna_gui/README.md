# inception

# Tips and Introduction

![Tips%20and%20Introduction%20ace998bc4bdd4eb088d6b73e8594473d/Inception-still-006.jpeg](Tips%20and%20Introduction%20ace998bc4bdd4eb088d6b73e8594473d/Inception-still-006.jpeg)

English version for the next time ... 

*"Ft_server trop facile ? Attendez on va vous compliquer un peu la tâche ..."* 

**C'est quoi Docker ?** 

En quelques mots Docker est un outil qui permet de déployer des services dans plusieurs environnements qui tournent indépendamment de l'environnement de travail de l'utilisateur. En gros c'est comme une machine virtuelle mais en moins lourd et qui utilise uniquement les ressources dont le service à besoin pour tourner. Bon vous avez probablement déjà fait ft_server  donc Docker ne vous est pas non plus inconnu, sinon Google est votre meilleur ami. 

**C'est quoi Docker Compose ?** 

Faire tourner un Docker c'est cool, mais pas très pertinent. Dans le monde réel, la vie, la vraie vous allez devoir déployer différents services pour votre application, site web, enfin le produit pour lequel votre boîte vous embauche. Pour déployer ces services sans encombre ils doivent être indépendants car si l'un d'eux comporte un bug, les autres services ne sont pas affectés ou très peu. Vous allez donc vous retrouvez avec plusieurs services par container : Wordpress ? Un container. La base de donnée ? Un autre container ? etc. Dans ce cas docker-compose permet de déployer tous ces container d'un seul coup et les faisant communiquer entre eux. 

Dans les faits, ça ressemble à quoi Docker Compose ? 

`docker-compose` est une commande qui va exécuter un script (docker-compose.yml) qui va lancer les différents Dockerfile de chaque service en y ajoutant quelques règles en plus. 

### À quoi ressemble un docker-compose.yml ?

```yaml

le_nom_du_service:
        image: le_nom_del'image:sontag
        volumes: <-- si vous voulez des données persistentes 
            - ledossierdupc:ledossierducontainter
        restart: <-- Si vous voulez que votre image redémarre au cas où ...
        environment: <-- environmment ... variable ... t'as capté 
            VAR1: "${POURQUOI}"
            VAR2: "${CETTE}"
            VAR3: "${SYNTAX??}"
          depend_on: <-- Si ton container dépend d'un autre, ben il faut le préciser
            - ton service plus important que le_nom_du_service
	        build: 
            context: <-- Le path du Dockerfile en question
            dockerfile: Le nom du Dockerfile en question 
					env_file: comme son nom l'indique. 
        
```yaml 


### Des trucs comme ça :

`docker-compose up —build`   ça lance les containers en suivant les règles du docker-compose.yml et ça build Dockerfile en même temps. 

`docker-compose down` ça arrête tous les services appelés par le docker-compose.yml. 

`docker exec -it container_id bash` pour rentrer dans le bash d'un container qui est en train de tourner (c'est cool pour debuguer) 

Avant de lancer le docker-compose, il faut penser à arrêter les services nginx et mysql du système pour libérer vos ports pour vos services DOcker: 

`service nginx stop` 

`service mysql stop`

Dans le cas où l'on cherche des infos sur un container (IP/ ID d'un container etc ...) : `docker ps`

`docker system prune`  Dans le cas ou l'on veut nettoyer et vider tous les containers pour un rebuild propre (parce'que les pruneaux ça permet de ne plus être ... enfin bref).  

[Les services à mettre en place ](https://www.notion.so/dac3b0e7a99e4acb8d31d3447e61d6d5)
