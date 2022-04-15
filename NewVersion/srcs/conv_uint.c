/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:05:21 by briffard          #+#    #+#             */
/*   Updated: 2022/04/15 08:39:20 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int format_uint(t_parameter *option, unsigned int number);
int	define_base(t_parameter *option);

int	define_base(t_parameter *option)
{
	if (option->conv == 'x' || option->conv == 'X' || option->conv == 'p')
		return (16);
	if (option->conv == 'o')
		return (8);
	return (10);
}

int format_uint(t_parameter *option, unsigned int number)
{
	char	*str;
	int		size;

	size = 0;

	str = ft_uitoa_base(number, define_base(option));
	if (!str)
		exit(EXIT_FAILURE);
	ft_reverse_str(str);
	if (option->upper)
		ft_strtoupper(str);
	size += format_intoa(option, str);
    ft_memdel((void **)&str);
	return(size);
}

int	argtohexoroct(t_parameter *li, va_list ap)
{
	// if(!ft_strcmp(li.sizePrefix,"ll"))
    //     return(ll_int_to_hex_or_oct(li, va_arg(ap, long long)));
    // else if(!ft_strcmp(li.sizePrefix, "l"))
    //     return(l_int_to_hex_or_oct(li, va_arg(ap, long)));
    // else if(!ft_strcmp(li.sizePrefix, "h"))
    //     return(short_int_to_hex_or_oct(li, (short)va_arg(ap, int)));
    // else if(!ft_strcmp(li.sizePrefix, "hh"))
    //     return(char_to_hex_or_oct(li, (char)va_arg(ap, int)));
    // else
    	return (format_uint(li, va_arg(ap, unsigned int)));
}

int argto_u_int(t_parameter *li, va_list ap)
{
    // if(!ft_strcmp(li.sizePrefix,"ll"))
    //     return(u_ll_intoa(li, va_arg(ap, unsigned long long)));
    // else if(!ft_strcmp(li.sizePrefix, "l"))
    //     return(u_ll_intoa(li, va_arg(ap, unsigned long)));
    // else if(!ft_strcmp(li.sizePrefix, "h"))
    //     return(u_short_intoa(li, (unsigned short)va_arg(ap, int)));
    // else if(!ft_strcmp(li.sizePrefix, "hh"))
    //     return(u_chartoa(li, (unsigned char)va_arg(ap, int)));
    // else
        return(format_uint(li, va_arg(ap, unsigned int)));
}
