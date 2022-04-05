/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_printf_flag_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:49:49 by briffard          #+#    #+#             */
/*   Updated: 2022/03/17 12:50:15 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
    char    letter;
    char    upper;
    char    symbol;
    char    space;
    char    tab;
    char    num;
    char    multiple1;
    char    multiple2;
    char    multiple3;
    
    letter =     'a';
    upper =     'A';
    symbol = '@';
    space = ' ';
    tab = '\t';
    num = '9';
    multiple1 = 'O';
    multiple2 = 'C';
    multiple3 = 'B';
    printf("%c\n",letter);
    printf("%c\n",upper);
    printf("%c\n",symbol);
    printf("%c\n",space);
    printf("%c\n",tab);
    printf("%c\n",num);
    printf("%c-%c-%c\n",multiple1, multiple2, multiple3);
    return (0);
}