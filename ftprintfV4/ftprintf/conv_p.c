/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:06:06 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 15:45:53 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char		*pointeraddress(t_parameter li, unsigned long long int c)
{
	char	*str;
	char	*temp;
	int		index;

    (void) li;
	index = 0 ;
	str = ft_strnew(sizeof(char) * 100);
	if (!str)
	{
		//ft_memdel((void **)&str);
		exit(EXIT_FAILURE);
	}
	str = ft_uitoa_base(c, 16);
	ft_reverse_str(str);
    str = parse_ptr(li, str);
	temp = str;
	ft_memdel((void *)&str);
	str = temp;
	return(str);
}

char *argtoptraddress(t_parameter li, va_list ap)
{
    return(pointeraddress(li, va_arg(ap, unsigned long long int)));
}