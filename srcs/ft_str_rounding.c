/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rounding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:00:18 by briffard          #+#    #+#             */
/*   Updated: 2022/04/29 13:07:22 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_for_zero(char *number, int last_index)
{
	if (last_index == 0)
		number = ft_strjoin_replace("1", number, 1);
	else
		number[last_index - 1] = number[last_index - 1] + 1;
	return (number);
}

char	*formatrounding(char *number, int last_index)
{
	while (last_index >= 0)
	{
		if (number[last_index] == ':')
		{
			number[last_index] = '0';
			if (number[last_index - 1] == '.')
				last_index--;
			number = check_for_zero(number, last_index);
		}
		if ((number[0] == ':' || number[0] == '.') && (int)last_index == 0)
		{
			number[0] = '0';
			number = ft_strjoin_replace("1", number, 1);
		}
		last_index--;
	}
	return (number);
}

char	*rounding(char *number, int fpart, int last_index)
{
	if (fpart > 5)
	{
		number[last_index] = number[last_index] + 1;
		number = formatrounding(number, last_index);
	}
	else if (fpart == 5)
		if ((number[last_index] + '0') % 2 == 1)
			number[last_index] = number[last_index] + 1;
	return (number);
}
