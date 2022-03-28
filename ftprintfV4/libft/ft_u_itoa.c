/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:08:04 by briffard          #+#    #+#             */
/*   Updated: 2022/03/28 09:08:24 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlenght(long n)
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
	return (count);
}

char	*ft_u_itoa(unsigned int n)
{
	long	k;
	int		i;
	char	*str;

	k = n;
	i = numlenght(k);
	if (k == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (k < 0)
	{
		str[0] = '-';
		k = k * -1;
	}
	while (k > 0)
	{
		str[i--] = 48 + (k % 10);
		k = k / 10;
	}
	return (str);
}