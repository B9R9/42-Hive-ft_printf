/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:11:05 by briffard          #+#    #+#             */
/*   Updated: 2022/04/15 12:24:41 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_str(const char *str,t_parameter *option);

/*
** Receive s and check if s == a color
** Return True or False
*/
t_bool	is_color(const char *s)
{
	if (!ft_strcmp(s, "red") || !ft_strcmp(s, RED))
		return (true);
	if (!ft_strcmp(s, "normal") || !ft_strcmp(s, DEFAULT))
		return (true);
	if (!ft_strcmp(s, "green") || !ft_strcmp(s, GREEN))
		return (true);
	if (!ft_strcmp(s, "yellow") || !ft_strcmp(s, YELLOW))
		return (true);
	if (!ft_strcmp(s, "blue") || !ft_strcmp(s, BLUE))
		return (true);
	if (!ft_strcmp(s, "magenta") || !ft_strcmp(s, MAGENTA))
		return (true);
	if (!ft_strcmp(s, "cyan") || !ft_strcmp(s, CYAN))
		return (true);
	if (!ft_strcmp(s, "white") || !ft_strcmp(s, WHITE))
		return (true);
	return(false);
}

/*
** Receive va_arg in char* format, apply all option
** Return number of char printed
*/
static int	format_str(const char *str,t_parameter *option)
{
	int	size;

	size = 0;
	if(is_color(str))// ajouter une branche qui va gerer les option tels que la couleur underlined et blink
	{
		ft_color(str);
		return (0);
	}
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