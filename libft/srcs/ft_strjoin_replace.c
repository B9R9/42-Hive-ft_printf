/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:25:04 by briffard          #+#    #+#             */
/*   Updated: 2022/04/13 16:45:27 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_replace(char *s0, char *s1, int choice )
{
	char	*tmp;

	tmp = ft_strjoin(s0, s1);
	if (choice == 1)
		ft_memdel((void *)&s1);
	else
		ft_memdel((void *)&s0);
	s0 = tmp;
	return (s0);
}
