#!/bin/bash

if [ $1 = 'clean' ];then
    rm -f *.o
    rm -f test
    rm -f leaksreport.txt
    rm -f valgrindlog
    exit 1
fi
if [ $1 = 'compil' ];then
    gcc -o main.o  -c main.c -Iinclude -I./libft/includes -g
    gcc -o test main.o -L. -lftprintf -g
    exit 1
fi
if [ $1 = 'compilitoe' ];then
    gcc -o main2.o  -c main2.c -Iinclude -I./libft/includes -g
    gcc -o test main2.o -L. -lftprintf -g
    exit 1
fi
if [ $1 = 'valgrind' ];then
    if [ -e "/Users/briffard/Desktop/B9R9-ft_printf/NewVersion/valgrindlog" ]; then
        rm -f /Users/briffard/Desktop/B9R9-ft_printf/NewVersion/Valgrindlog
    fi
    gcc -o main.o  -c main.c -Iinclude -I./libft/includes -g
    gcc -o test main.o -L. -lftprintf -g
    valgrind  --leak-check=full --show-leak-kinds=all --log-file="valgrindlog" test
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
if [ $1 = 'Call' ];then
    sed -i "17i\test_basic();\n" ./caruytest/run.sh
    sed -i "18i\test_lengths();\n" ./caruytest/run.sh
    sed -i "19i\test_flags();\n" ./caruytest/run.sh
    sed -i "20i\test_precision();\n" ./caruytest/run.sh
    sed -i "21i\test_widths();\n" ./caruytest/run.sh
    sed -i "22i\test_wildcards();\n" ./caruytest/run.sh
    sed -i "23i\test_more();\n" ./caruytest/run.sh
    ./caruytest/run.sh

    sed -l 17
    sed -l 18
    sed -l 19
    sed -l 20
    sed -l 21
    sed -l 22
    sed -l 23

fi

