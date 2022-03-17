/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ftprintf_flag_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:43:24 by briffard          #+#    #+#             */
/*   Updated: 2022/03/17 12:49:48 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

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
    ft_printf("%c\n",letter);
    ft_printf("%c\n",upper);
    ft_printf("%c\n",symbol);
    ft_printf("%c\n",space);
    ft_printf("%c\n",tab);
    ft_printf("%c\n",num);
    ft_printf("%c-%c-%c\n",multiple1, multiple2, multiple3);
    return (0);
}