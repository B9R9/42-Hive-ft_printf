#!/bin/bash

bleu='\e[1;34m'
orange='\e[0;33m'
green='\e[0;32m'
red='\e[0;31m'
neutre='\e[0;m'


if [ $1 = 'clean' ]; then
    rm -f *.o
    rm -f sample_c sample_ft testftprintf_flag_s testprintf_flag_s testftprintf_flag_c testprintf_flag_c
    exit 1
fi
if [ $1 = 'all' ]; then
    ./maintest.sh s
    ./maintest.sh c

    exit 1    
fi

if [ $1 = 's' ]; then

    printf "${bleu}--------------------------------------------------------------------------------${neutre}\n"
	printf "${bleu}-----------------------------------------------------------------------   FALG S\n${neutre}\n"

    gcc -Wall -Werror -Wextra -I../ftprintf/include -I../libft/includes -o 00_ftprintf_flag_s.o -c 00_ftprintf_flag_s.c
    gcc -Wall -Werror -Wextra -o testftprintf_flag_s 00_ftprintf_flag_s.o -L../libft/ -lft -L../ftprintf/ -lftprintf
    gcc -Wall -Werror -Wextra -o testprintf_flag_s 00_printf_flag_s.c

    ./testprintf_flag_s >> sample_c
    ./testftprintf_flag_s >> sample_ft

    printf "================================================ OUTPUT ===========================================\n"
    printf "                         PRINTF                                              FTPRINTF\n"
    diff -y sample_c sample_ft
    rm -f sample_c sample_ft
    exit 1
fi
if [ $1 = 'c' ]; then
    printf "${bleu}--------------------------------------------------------------------------------${neutre}\n"
	printf "${bleu}-----------------------------------------------------------------------   FALG C\n${neutre}\n"

    gcc -Wall -Werror -Wextra -I../ftprintf/include -I../libft/includes -o 01_ftprintf_flag_c.o -c 01_ftprintf_flag_c.c
    gcc -Wall -Werror -Wextra -o testftprintf_flag_c 01_ftprintf_flag_c.o -L../libft/ -lft -L../ftprintf/ -lftprintf
    gcc -Wall -Werror -Wextra -o testprintf_flag_c 01_printf_flag_c.c

    ./testprintf_flag_c >> sample_c
    ./testftprintf_flag_c >> sample_ft

    printf "================================================ OUTPUT ===========================================\n"
    printf "                         PRINTF                                              FTPRINTF\n"
    diff -y sample_c sample_ft
    rm -f sample_c sample_ft
    exit 1
fi
