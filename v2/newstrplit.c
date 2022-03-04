/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newstrplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:45:59 by briffard          #+#    #+#             */
/*   Updated: 2022/03/05 01:03:37 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static int	moveindex(const char *str, int index)
{
	int x;

	while(str[index] != '\0')
	{
		x = 0;
		while(flags[x] != '\0')
		{
			if (str[index] == flags[x])
				return (index + 1);
			x++;
		}
		index++;
	}
	printf("error: spurious trailling '%%' in formart\n");
	exit(EXIT_FAILURE);
}

static int	countwords(const char *str, char delimiter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if(str[i] == delimiter)
		{
			count++;
			i = moveindex(str, i);
		}
		else
		{
			while (str[i] != delimiter && str[i])
				i++;
			count++;
		}
	}
	return (count);
}



char	**newstrsplit(char *str, va_list ap)
{
	char	**dest;
	if(!str)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * countwords(str, '%')) + 1;
	if(!dest)
		return (NULL);
	return(dest);
}