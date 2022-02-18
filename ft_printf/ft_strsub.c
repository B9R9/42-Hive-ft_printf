/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:07:38 by briffard          #+#    #+#             */
/*   Updated: 2022/02/18 13:32:04 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char	*ft_strsub(char const	*s, unsigned int start, size_t len)
{
	unsigned char	*d;
	char			*new;
	size_t			i;

	d = (unsigned char *)s;
	i = 0;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	else
	{
		while (i < len)
		{
			new[i] = d[start];
			i++;
			start++;
		}
		new[i] = '\0';
	}
	return (new);
}
