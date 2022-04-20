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

static int format_int(t_parameter *li, int number);
int  format_char(t_parameter *option, char c);
static int  format_bool(int number);

static int format_int(t_parameter *option, int number)
{
	char    *dest;
    int     size;

    size = 0;
    if (number == 0)
    {
        if (option->dot)
            return (format_char(option,' '));
        return (format_char(option,'0'));
    }
    if (number < 0 && number > -2147483648)
    {
        number *= -1;
        // check_flasgbit(option);
        option->flags = option->flags | F_NEGATIF;
        if (option->flags & F_PLUS)
            option->flags = option->flags ^ F_PLUS;
        // check_flasgbit(option);
    }
    dest = ft_itoa(number);
    size += print_int(option, dest);
    // size += format_intoa(option, dest);
    ft_memdel((void *)&dest);
	return (size);
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

/*
** Receive va_arg as int
** printf a char* true or false
*/
static int  format_bool(int number)
{
    if (number > 0)
        return (print_str("True", ft_strlen("True")));
    return (print_str("False", ft_strlen("False")));
}

int conv_to_int(t_parameter *option, va_list ap)
{
    if(option->conv == 'c')
        return(format_char(option, va_arg(ap, int)));
    else if (option->conv == 't')
        return (format_bool(va_arg(ap, int)));
    else if (option->flags & F_MOD)
        return (dispach_to_SizePrefix(option, ap));
    else
        return (format_int(option, va_arg(ap, int)));
    }


