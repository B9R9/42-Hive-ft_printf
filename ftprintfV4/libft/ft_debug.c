/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:00:09 by briffard          #+#    #+#             */
/*   Updated: 2022/03/16 12:31:13 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_debug(char *color,char *where, int position, char *str, int num)
{
    ft_color(color);
    ft_putstr("=======================\n");
    ft_putstrcolor("Position: ", "normal");
    ft_color(color);
    ft_putnbr(position);
    ft_putstrcolor("\nFucntion = ","normal");
    ft_putstrcolor(where, color);
    ft_putstrcolor("\nValeur de str = ","normal");
    ft_putstrcolor(str, color);
    ft_putstrcolor("\nValeur de int = ","normal");
    ft_putnbr(num);
    ft_putchar('\n');
    ft_color(color);
    ft_putstr("=======================\n");
    ft_color("normal");
}