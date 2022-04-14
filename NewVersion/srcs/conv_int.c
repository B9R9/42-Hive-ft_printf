/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:03:31 by briffard          #+#    #+#             */
/*   Updated: 2022/04/14 11:19:28 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int intoa(t_parameter *li, int number);

static int intoa(t_parameter *li, int number)
{
	char    *dest;
    int     size;
    
    size = 0;
    dest = ft_itoa(number);
    size += format_intoa(li, dest);
    ft_memdel((void *)&dest);
	return (size);
}

int argtoint(t_parameter *li, va_list ap)
{
    // if(!ft_strcmp(li->sizePrefix,"ll"))
    //     return(ll_int_to_arr(li, va_arg(ap, long long)));
    // else if(!ft_strcmp(li->sizePrefix, "l"))
    //     return(l_int_to_arr(li, va_arg(ap, long)));
    // else if(!ft_strcmp(li->sizePrefix, "h"))
    //     return(short_int_to_arr(li, (short)va_arg(ap, int)));
    // else if(!ft_strcmp(li->sizePrefix, "hh"))
    //     return(char_to_arr(li, (char)va_arg(ap, int)));
    // else
		return (intoa(li, va_arg(ap, int)));
}
