/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointertoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:06:06 by briffard          #+#    #+#             */
/*   Updated: 2022/03/22 15:27:38 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char		*pointeraddress(t_parameter li, unsigned long long int c)
{
	char	*str;
	int		index;

    (void) li;
	index = 0 ;
	str = ft_strnew(sizeof(char) * 100);
	if (!str)
	{
		ft_memdel((void **)&str);
		exit(EXIT_FAILURE);
	}
	if (c == 0)
		str[0] = '0';
	while (c != 0)
	{
			str[index] = hexa[c % 16];
		if (!str)
		{
			ft_memdel((void **)&str);
			exit(EXIT_FAILURE);
		}
		c  = c / 16;
		index++;
	}
	index = 0;
	revstr(str);
    str = ft_strjoin("0x", str);
	return(str);
}

char *argtoptraddress(t_parameter li, va_list ap)
{
    return(pointeraddress(li, va_arg(ap, unsigned long long int)));
}