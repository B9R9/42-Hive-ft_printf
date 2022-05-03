/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:11:05 by briffard          #+#    #+#             */
/*   Updated: 2022/05/03 14:33:26 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_str(const char *str, t_parameter *option);
static void	set_precision(t_parameter *option, const char *str);

static void	set_precision(t_parameter *option, const char *str)
{
	if ((!option->pre && str && !(option->dot)) || \
	(option->pre > (int)ft_strlen(str) && str))
		option->pre = ft_strlen(str);
	if (option->pre < 0)
		option->pre = ft_strlen(str);
}

/*
** Receive va_arg in char* format, apply all option
** Return number of char printed
*/
static int	format_str(const char *str, t_parameter *option)
{
	int	size;

	size = 0;
	if (str == NULL)
		return (print_str("(null)", (int)ft_strlen("(null)")));
	if (is_bonus(str))
	{
		ft_putstr(str);
		return (0);
	}
	set_precision(option, str);
	if (option->dot && !(option->pre))
		option->pre = 0;
	size += print_width(option, option->pre);
	size += print_str(str, option->pre);
	if (option->flags & F_MINUS)
		size += align_right(size, option->width);
	return (size);
}

/*
** TURN ARGUMENT TO STR
*/
int	conv_to_str(t_parameter *li, va_list ap)
{
	return (format_str(va_arg(ap, char *), li));
}
