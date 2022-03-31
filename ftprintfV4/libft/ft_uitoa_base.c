/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:59:59 by briffard          #+#    #+#             */
/*   Updated: 2022/03/31 16:25:20 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_uitoa_base(unsigned long long number, int base)
{
    int                     index;
	char					*str;

    index = 0;
    str = ft_strnew(ft_numlenght(number));
    /*verifier si MAlloc a focntionner*/
    while (number != 0)
    {
        str[index] = BASE[number % base];
        number = number / base;
        index++;
    }
	return (str);
}