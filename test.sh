#!/bin/bash

if [ $1 = 'clean' ];then
    rm -f ./test/*.o
    rm -f test_ftprintf
    rm -rf ./test/leaks
    exit 1
fi
if [ $1 = 'test' ];then
    make re
    gcc -o ./test/main.o  -c ./test/main.c -Iinclude -I./libft/includes -g
    gcc -o test_ftprintf ./test/main.o -L. -lftprintf -g
    ./test_ftprintf
    exit 1
fi
if [ $1 = 'Itoetest' ];then
    gcc -o ./test/main2.o  -c ./test/main2.c -Iinclude -I./libft/includes -g
    gcc -o test_ftprintf ./test/main2.o -L. -lftprintf -g
    ./test_ftprintf
    exit 1
fi
if [ $1 = 'Caruytest' ];then
    ./test/caruytest/run.sh
    exit 1
fi
if [ $1 = 'valgrind' ];then
    mkdir -p ./test/leaks
    if [ -e "/Users/briffard/Desktop/B9R9-ft_printf/test/leaks/valgrindlog" ]; then
        rm -f /Users/briffard/Desktop/B9R9-ft_printf/test/leaks/valgrindlog
    fi
    gcc -o ./test/main.o  -c ./test/main.c -Iinclude -I./libft/includes -g
    gcc -o test_ftprintf ./test/main.o -L. -lftprintf -g
    valgrind  --leak-check=full --show-leak-kinds=all --log-file="./test/leaks/valgrindlog" test_ftprintf
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

