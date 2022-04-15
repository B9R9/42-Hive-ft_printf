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
    cp -r /Users/briffard/Desktop/NewVersion /Users/briffard/Desktop/B9R9-ft_printf
    cd /Users/briffard/Desktop/B9R9-ft_printf
    git add NewVersion
    git commit -m "AUTO SAVE"
    git push
fi

