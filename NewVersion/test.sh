#!/bin/bash

if [ $1 = 'clean' ];then
    rm -f *.o
    rm -f test
    exit 1
fi
if [ $1 = 'compil' ];then
    gcc -o main.o  -c main.c -Iinclude -I./libft/includes -g
    gcc -o test main.o -L. -lftprintf -g
    exit 1
fi
if [ $1 = 'valgrind' ];then
    gcc -o main.o  -c main.c -Iinclude -I./libft/includes -g
    gcc -o test main.o -L. -lftprintf -g
    valgrind  --leak-check=full --show-leak-kinds=all test
    exit 1
fi
if [ $1 = 'push' ];then
    cd ../
    git add ./NewVersion
    git commit -m "$2"
    git push
fi

