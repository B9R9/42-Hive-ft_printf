/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 08:48:46 by briffard          #+#    #+#             */
/*   Updated: 2022/03/04 17:23:52 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	error(const char *str)
{
	write(2, str, ft_strlen(str));
}

int		printchar(char c)
{
	write(1, &c, 1);
	return(1);
}

int		print(t_parameter li, const char *str)
{
	size_t	index;
	size_t	strlenght;

	strlenght = ft_strlen(str);
	index = 0;
	/*cimprime str suivant les parameter*/
	if (li.dotlenght == 0 || li.dotlenght > strlenght)
		li.dotlenght = strlenght;
	while (index < li.dotlenght)
		write(1, &str[index++], 1);
	//ft_memdel((void**)str);
	return(index);
}