#!/bin/bash
BASEDIR=$(dirname "$0")
docker image rm -f wordpress
docker build -t wordpress $BASEDIR
