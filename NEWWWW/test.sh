#!/bin/bash

if [ $1 = 'clean' ];then
    rm -f *.o
    rm -f test
    exit 1
fi
if [ $1 = 'compil' ];then
    gcc -o main.o  -c main.c -Iinclude -I./libft/includes
    gcc -o test main.o -L. -lftprintf
fi

