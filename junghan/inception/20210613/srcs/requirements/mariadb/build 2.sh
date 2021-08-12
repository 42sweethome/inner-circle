#!/bin/bash
BASEDIR=$(dirname "$0")
sed -e "s/minikube_ip/$MINIKUBE_IP/" $BASEDIR/wordpress.sql > $BASEDIR/wordpress_copy.sql
docker image rm -f mysql
docker build -t mysql $BASEDIR
