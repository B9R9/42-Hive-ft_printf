/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:16:48 by briffard          #+#    #+#             */
/*   Updated: 2022/04/27 14:50:51 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			skip(char *str);
t_bool		isnot_sizeprefix(char *str);
int			define_base(t_parameter *option);
t_bool		isnot_precision(int c);
long double	set_dbl_negtif(long double number, t_parameter *option);

long double	set_dbl_negtif(long double number, t_parameter *option)
{
	if (ft_isdoubleneg(number) && number != 0.00)
	{
		number *= -1;
		option->flags = option->flags | F_NEGATIF;
		return (number);
	}
	return (number);
}

int	define_base(t_parameter *option)
{
	if (option->conv == 'x' || option->conv == 'X' || option->conv == 'p')
		return (16);
	if (option->conv == 'o')
		return (8);
	return (10);
}

int	skip(char *str)
{
	int		index;

	index = 0;
	while (str[index] >= '0' && str[index] <= '9')
		index++;
	return (index);
}

t_bool	isnot_sizeprefix(char *str)
{
	if ((str[0] == 'l' || str[0] == 'h' || str[0] == 'L' || str[0] == 'z') && \
	!checkparams(str[1]))
		return (false);
	if (str[0] == 'l' && str[1] == 'l' && !checkparams(str[2]))
		return (false);
	if (str[0] == 'h' && str[1] == 'h' && !checkparams(str[2]))
		return (false);
	return (true);
}

t_bool	isnot_precision(int c)
{
	if (c == '.')
		return (false);
	if (c == '*')
		return (false);
	return (true);
}
