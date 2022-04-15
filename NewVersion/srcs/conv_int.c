/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:03:31 by briffard          #+#    #+#             */
/*   Updated: 2022/04/15 12:03:20 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int intoa(t_parameter *li, int number);
static int  format_char(t_parameter *option, char c);

static int intoa(t_parameter *option, int number)
{
	char    *dest;
    int     size;
    
    size = 0;
    if (option->conv == 't')
    {
        if (number > 0)
            return (print_str("True", ft_strlen("True")));
        return (print_str("False", ft_strlen("False")));
    }
    dest = ft_itoa(number);
    size += format_intoa(option, dest);
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

/*
**Receive va_arg as int and print a char
*/
static int  format_char(t_parameter *option, char c)
{
    int size;

    size = 0;
    
    size += print_width(option, 1);
    size += print_char(c);
	if (option->flags & F_MINUS)
		size += align_right(size, option->width); 
    return (size); 
}

/*Turn va_arg into an int*/
int argtochar(t_parameter *li, va_list ap)
{
    return(format_char(li, va_arg(ap, int)));
}
