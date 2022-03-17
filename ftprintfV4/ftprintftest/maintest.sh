#!/bin/bash

bleu='\e[1;34m'
orange='\e[0;33m'
green='\e[0;32m'
red='\e[0;31m'
neutre='\e[0;m'


if [ $1 = 'clean' ]; then
    rm -f *.o
    rm -f sample_c sample_ft testftprintf_flag_s testprintf_flag_s
    exit 1
fi
if [ $1 = 'all' ]; then
    ./maintest.sh s

    exit 1    
fi

if [ $1 = 's' ]; then
    printf "${bleu}--------------------------------------------------------------------------------${neutre}\n"
	printf "${bleu}-----------------------------------------------------------------------   FALG S${neutre}\n"

    gcc -Wall -Werror -Wextra -I../ftprintf/include -I../libft/includes -o ftprintf_flag_s.o -c ftprintf_flag_s.c
    gcc -Wall -Werror -Wextra -o testftprintf_flag_s ftprintf_flag_s.o -L../libft/ -lft -L../ftprintf/ -lftprintf
    gcc -Wall -Werror -Wextra -o testprintf_flag_s printf_flag_s.c

    ./testprintf_flag_s >> sample_c
    ./testftprintf_flag_s >> sample_ft

    diff -y sample_c sample_ft
    rm -f sample_c sample_ft
    exit 1
fi
if [ $1 = 'c' ]; then
    printf "${bleu}--------------------------------------------------------------------------------${neutre}\n"
	printf "${bleu}-----------------------------------------------------------------------   FALG C${neutre}\n"
