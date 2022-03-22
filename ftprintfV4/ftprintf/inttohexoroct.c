/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttohexoroct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:05:21 by briffard          #+#    #+#             */
/*   Updated: 2022/03/22 14:50:54 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char		*decimaltohexoroct(t_parameter li, int number)
{
	char	*str;
	int		index;
	int     coef;

    printf("TEST00\n");
	coef = 8;
	index = 0 ;
	str = ft_strnew(sizeof(char) * 100);
	if (!str)
	{
		ft_memdel((void **)&str);
		exit(EXIT_FAILURE);
	}
    printf("TEST01\n");
	if (li.flag == 'x' || li.flag == 'X')
		coef = 16;
    printf("TEST02\n");
	while (number != 0)
	{
		if (li.flag == 'x' || li.flag == 'X')
			str[index] = hexa[number % 16];
		else if (li.flag == 'o')
			str = ft_strjoin(str, ft_itoa(number % 8));
		if (!str)
		{
			ft_memdel((void **)&str);
			exit(EXIT_FAILURE);
		}
		if (li.flag == 'X')
			str[index] = (char)ft_toupper(str[index]);
		number  = number / coef;
		index++;
	}
    printf("TEST05\n");
	revstr(str);
    if(li.hastag && li.flag == 'x')
        str =ft_strjoin("0x", str);
    else if (li.hastag && li.flag == 'X')
        str = ft_strjoin("0X", str);
    
    printf("VALEUR STR = %s\n", str);
	//ft_memdel((void**)&str);
	return(str);
}

char *argtohexoroct(t_parameter li, va_list ap)
{
    return (decimaltohexoroct(li, va_arg(ap, int)));
}
