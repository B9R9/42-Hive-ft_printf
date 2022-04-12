/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:06:06 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 13:43:10 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	char			*temp;
	unsigned int	i;

	i = 0;
	temp = (char *)malloc((sizeof(char) * size) + 1);
	if (temp == NULL)
		return (NULL);
	while (i < size)
	{
		temp[i] = '\0';
		i++;
	}
	temp[i] = '\0';
	str = temp;
	ft_memdel((void *) &temp);
	return (str);
}
