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
    if [ -e "/Users/briffard/Desktop/B9R9-ft_printf/NewVersion/Valgrindlog" ]; then
        rm -f /Users/briffard/Desktop/B9R9-ft_printf/NewVersion/Valgrindlog
    fi
    gcc -o main.o  -c main.c -Iinclude -I./libft/includes -g
    gcc -o test main.o -L. -lftprintf -g
    valgrind  --leak-check=full --show-leak-kinds=all --log-file="Valgrindlog" test
    exit 1
fi
if [ $1 = 'push' ];then
    git add .
    git commit -m "$2"
    git push
fi
if [ $1 = 'pull' ];then
    git fetch
    git pull
fi
