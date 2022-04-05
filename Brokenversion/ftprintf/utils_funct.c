/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:16:48 by briffard          #+#    #+#             */
/*   Updated: 2022/04/04 09:18:13 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char	*align_right(char *dest);
int	skip(char *str);

char	*align_right(char *dest)
{
	int	x;

	x = 0;
	while (dest[0] == ' ')
	{
		x = 0;
		while (dest[x + 1] != '\0')
		{
			ft_swap(&dest[x], &dest[x + 1]);
			x++;
		}
	}
	return (dest);
}

int	skip(char *str)
{
	int		index = 0;
	while (str[index] >= '0' && str[index] <= '9')
		index++;
	return index;
}