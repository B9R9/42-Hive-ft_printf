/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex_or_oct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:05:21 by briffard          #+#    #+#             */
/*   Updated: 2022/03/31 16:22:18 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char		*decimaltohexoroct(t_parameter li, int number)
{
	char	*str;
	int		index;
	int     base;

	index = 0 ;
	if(li.flag == 'X' || li.flag == 'x')
		base = 16;
	else if (li.flag == 'o')
		base = 8;
	else
		base = 10;
	str = ft_itoa_base(number, base);
	if (!str)
	{
		ft_memdel((void **)&str);
		exit(EXIT_FAILURE);
	}
	// while (number != 0)
	// {
	// 	if (li.flag == 'x' || li.flag == 'X')
	// 		str[index] = hexa[number % 16];
	// 	else if (li.flag == 'o')
	// 		str = ft_strjoin(str, ft_itoa(number % 8));
	// 	if (!str)
	// 	{
	// 		ft_memdel((void **)&str);
	// 		exit(EXIT_FAILURE);
	// 	}
	// 	if (li.flag == 'X')
	// 		str[index] = (char)ft_toupper(str[index]);
	// 	number  = number / coef;
	// 	index++;
	// }
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
	if(!ft_strcmp(li.sizePrefix,"ll"))
        return(ll_int_to_arr(li, va_arg(ap, long long)));
    else if(!ft_strcmp(li.sizePrefix, "l"))
        return(l_int_to_arr(li, va_arg(ap, long)));
    else if(!ft_strcmp(li.sizePrefix, "h"))
        return(short_int_to_arr(li, (short)va_arg(ap, int)));
    else if(!ft_strcmp(li.sizePrefix, "hh"))
        return(char_to_arr(li, (char)va_arg(ap, int)));
    else
    	return (decimaltohexoroct(li, va_arg(ap, int)));
}
