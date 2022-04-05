/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex_or_oct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:05:21 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 15:46:15 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char		*decimaltohexoroct(t_parameter li, unsigned int number)
{
	char	*str;
	char	*temp;
	int		index;
	int     base;

	index = 0 ;
	if(li.conv == 'X' || li.conv == 'x')
		base = 16;
	else if (li.conv == 'o')
		base = 8;
	else
		base = 10;
	str = ft_uitoa_base(number, base);
	if (!str)
	{
		ft_memdel((void **)&str);
		exit(EXIT_FAILURE);
	}
	ft_reverse_str(str);
	str = parse_hexa_or_oct(li, str);
	temp = str;
	ft_memdel((void *) &str);
	str =  temp;
	return(str);
}

char *argtohexoroct(t_parameter li, va_list ap)
{
	if(!ft_strcmp(li.sizePrefix,"ll"))
        return(ll_int_to_hex_or_oct(li, va_arg(ap, long long)));
    else if(!ft_strcmp(li.sizePrefix, "l"))
        return(l_int_to_hex_or_oct(li, va_arg(ap, long)));
    else if(!ft_strcmp(li.sizePrefix, "h"))
        return(short_int_to_hex_or_oct(li, (short)va_arg(ap, int)));
    else if(!ft_strcmp(li.sizePrefix, "hh"))
        return(char_to_hex_or_oct(li, (char)va_arg(ap, int)));
    else
    	return (decimaltohexoroct(li, va_arg(ap, unsigned int)));
}
