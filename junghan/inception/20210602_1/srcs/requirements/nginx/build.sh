#!/bin/bash
BASEDIR=$(dirname "$0")
docker image rm -f nginx
docker build -t nginx $BASEDIR
