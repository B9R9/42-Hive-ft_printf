/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:25:04 by briffard          #+#    #+#             */
/*   Updated: 2022/04/25 16:35:12 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_replace(char *s0, char *s1, int choice)
{
	char	*tmp;

	choice = 0;
	tmp = ft_strjoin(s0, s1);
	ft_memdel((void *)&s1);
	ft_memdel((void *)&s0);
	s0 = tmp;
	return (s0);
}
