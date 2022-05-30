#!/bin/bash

if [ $1 = 'clean' ];then
    rm -f *.o
    rm -f test_ftprintf
    rm -f ./leaks/*
	rm -rf ./leaks
	make -C ../ fclean
    exit 1
fi
if [ $1 = 'test' ];then
    make -C ../ re
	mkdir -p leaks
    gcc -Wextra -Wall  -o main.o  -c -x c main -I../ft_printf/includes -g
    gcc -Wextra -Wall -o test_ftprintf main.o -L../ -lftprintf -g
    ./test_ftprintf
    exit 1
fi
if [ $1 = 'test2' ];then
	make -C ../ re
	mkdir -p leaks
    gcc -o main2.o  -c -x c main2 -I../ft_printf/includes
    gcc -o test_ftprintf main2.o -L../ -lftprintf
    ./test_ftprintf
    exit 1
fi
if [ $1 = 'test3' ];then
	make -C ../ re
	mkdir -p leaks
    gcc  -Wextra -Wall  -o main3.o  -c -x c main3 -I../ft_printf/includes
    gcc  -Wextra -Wall  -o test_ftprintf main3.o -L../ -lftprintf
    ./test_ftprintf
    exit 1
fi
if [ $1 = 'valgrind' ];then
    gcc -o main.o  -c -x c main  -I../libft/includes
    gcc -o test_ftprintf main.o -L../ -lftprintf
    valgrind  --leak-check=full --show-leak-kinds=all --log-file="./leaks/valgrindlog" ./test_ftprintf
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

