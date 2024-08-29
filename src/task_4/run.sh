#!/bin/bash

gcc -o hello hello.c -lfcgi
spawn-fcgi -p 8080 -n ./hello &
service nginx start
nginx -s reload
/bin/bash