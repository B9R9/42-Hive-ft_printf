/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itona.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:54:07 by briffard          #+#    #+#             */
/*   Updated: 2022/01/07 09:31:55 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlenght_variant(long n, int size)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	if(size > count)
		return size;
	return (count);
}

char	*ft_itona(int n, int size)
{
	long	k;
	int		i;
	char	*str;

	// ft_debug("cyan", "itona", 00, "NULL", size);
	k = n;
	i = ft_numlenght_variant(k, size);
	// ft_debug("cyan", "itona", 01, "NULL", i);
	if (k == 0)
		return (ft_strdup("0"));
	str = ft_strnew(i);
	str = fillit(str, '0', i);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (k < 0)
	{
		str[0] = '-';
		k = k * -1;
	}
	// ft_debug("cyan", "itona", 03, str, (int) k);
	while (k > 0)
	{
		str[i--] = 48 + (k % 10);
		k = k / 10;
	}
	// ft_debug("cyan", "itona", 04, str, i);
	return (str);
}
