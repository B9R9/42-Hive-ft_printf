/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:03:31 by briffard          #+#    #+#             */
/*   Updated: 2022/04/13 15:44:16 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*inttoarr(t_parameter li, int number)
{
	char   *dest;
    
    dest = ft_itoa(number);
    dest = parse_int(li, dest);
	return (dest);
}

char	*argtoint(t_parameter li, va_list ap)
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
		return (inttoarr(li, va_arg(ap, int)));
}
