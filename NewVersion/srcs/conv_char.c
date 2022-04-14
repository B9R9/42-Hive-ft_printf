/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:54:07 by briffard          #+#    #+#             */
/*   Updated: 2022/04/14 10:46:05 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  format_char(t_parameter *option, char c);

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