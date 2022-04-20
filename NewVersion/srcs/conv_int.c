/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:03:31 by briffard          #+#    #+#             */
/*   Updated: 2022/04/20 12:54:42 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int intoa(t_parameter *li, int number);
int  format_char(t_parameter *option, char c);

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
    if (number == 0)
    {
        if (option->dot)
            return (format_char(option,' '));
        return (format_char(option,'0'));
    }
    if (number < 0 && number > -2147483648)
    {
        number *= -1;
        option->negatif = true;
        option->flags = option->flags ^ F_PLUS;
    }
    dest = ft_itoa(number);
    size += format_intoa(option, dest);
    ft_memdel((void *)&dest);
	return (size);
}

int argtoint(t_parameter *option, va_list ap)
{
    if(!ft_strcmp(option->sizePrefix,"ll"))
        return(ll_int_to_arr(option, va_arg(ap, long long)));
    else if(!ft_strcmp(option->sizePrefix, "l"))
        return(ll_int_to_arr(option, va_arg(ap, long)));
    else if(!ft_strcmp(option->sizePrefix, "h"))
        return(short_int_to_arr(option, (short)va_arg(ap, int)));
    else if(!ft_strcmp(option->sizePrefix, "hh"))
        return(char_to_arr(option, (char)va_arg(ap, int)));
    else
		return (intoa(option, va_arg(ap, int)));
}

/*
**Receive va_arg as int and print a char
*/
int  format_char(t_parameter *option, char c)
{
    int size;

    size = 0;
    if (option->conv == '%')
        c = '%';
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