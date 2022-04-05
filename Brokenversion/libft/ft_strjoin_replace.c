/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:25:04 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 15:22:04 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>

char	*ft_strjoin_replace(char *s1, char *s2, int first_str)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (first_str)
		ft_memdel((void *) &s1);
	else
		ft_memdel((void *) &s2);
	return (tmp);
}