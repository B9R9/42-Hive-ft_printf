/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:08:04 by briffard          #+#    #+#             */
/*   Updated: 2022/03/30 10:37:28 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	numlenght(unsigned long long int n)
{
	int	count;

	count = 0;
/*	if (n < 0) Oasa necessaire vu unsigned est tiujours possitif 
	{
		n = n * -1;
		count++;
	}*/
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_u_itoa(unsigned long long int n)
{
	unsigned long long		i;
	char					*str;

	i = numlenght(n);
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	// if (n < 0) pass necessaire car U_INt est toujours positif
	// {
	// 	str[0] = '-';
	// 	n = n * -1;
	// }
	while (n > 0)
	{
		str[i--] = 48 + (n % 10);
		n = n / 10;
	}
	return (str);
}