/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setuprecision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:33:44 by briffard          #+#    #+#             */
/*   Updated: 2022/03/17 15:40:13 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

t_parameter		setupdot(t_parameter li, char *str)
{
	li.dot = true;
	li.dotlenght = ft_atoi(&str[1]);

	if(li.zero)
		{
			if(li.dotlenght >= li.zerolenght)
				li.zerolenght = li.dotlenght;
			else if (li.zerolenght > li.dotlenght)
			{
				li.space = true;
				li.spacelenght = li.zerolenght - li.dotlenght;
				li.zerolenght = li.dotlenght;
			}
		}
	printf("Valeur de  0 %zu\n", li.zerolenght);
	printf("Valeur de  . %zu\n", li.dotlenght);
	printf("Valeur de  space  %u\n", li.space);
	return (li);
}

/*le 1er rgument de la list ap renvoie la widht */
t_parameter		setupstar(t_parameter li, char *str)
{
	(void)str;
	li.star = true;
	return(li);
}