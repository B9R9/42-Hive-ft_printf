/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:59:59 by briffard          #+#    #+#             */
/*   Updated: 2022/04/20 13:40:47 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char    *ft_uitoa_base(unsigned long long number, int base)
{
    int                     index;
	char					*str;

    index = 0;
    str = ft_strnew(ft_numlenght(number));
    if (!str)
        return (NULL);
    if (number == 0)
        return (ft_strdup("0"));
    while (number != 0)
    {
        str[index] = BASE[number % base];
        number = number / base;
        index++;
    }
	return (str);
}