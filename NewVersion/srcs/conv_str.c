/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:11:05 by briffard          #+#    #+#             */
/*   Updated: 2022/04/14 11:28:37 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_str(const char *str,t_parameter *option);

/*
** Receive va_arg in char* format, apply all option
** Return number of char printed
*/
static int	format_str(const char *str,t_parameter *option)
{
	int	size;

	size = 0;
    if(!option->precision && str)
        option->precision = ft_strlen(str);
	if (str != NULL)
	{
		size += print_width(option, option->precision);
		size += print_str(str, option->precision);
		if (option->flags & F_MINUS)
			size += align_right(size, option->width);
		return (size);
	}
	else
		return (print_str("(null)", (int)ft_strlen("(null)")));
}
/*
** TURN ARGUMENT TO STR
*/
int argtostr(t_parameter *li, va_list ap)
{
    return (format_str(va_arg(ap, char *), li));
}