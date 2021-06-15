#!/bin/sh
ps | grep php-fpm| grep -v grep
return $?
