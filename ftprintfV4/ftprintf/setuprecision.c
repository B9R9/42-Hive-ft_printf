/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setuprecision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:33:44 by briffard          #+#    #+#             */
/*   Updated: 2022/03/18 17:44:02 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

t_parameter		setupdot(t_parameter li, char *str)
{
	li.dot = true;
	li.dotlenght = ft_atoi(&str[1]);
	
	if(li.zero && li.flag == 'd')
		{
			printf("@Valeur de  0 %zu\n", li.zerolenght);
			printf("@Valeur de  . %zu\n", li.dotlenght);
			printf("@Valeur de  space  %zu\n", li.spacelenght);
			if(li.dotlenght >= li.zerolenght || li.zerolenght == (li.dotlenght + 1))
				li.zerolenght = li.dotlenght;
			else if ((li.zerolenght - li.dotlenght) >= 2)
			{
				printf("@Valeur de  0 %zu\n", li.zerolenght);
				printf("@Valeur de  . %zu\n", li.dotlenght);
				printf("@Valeur de  space  %zu\n", li.spacelenght);
				li.space = true;
				li.spacelenght = ((li.zerolenght - li.dotlenght) - 1);
				li.zerolenght = li.dotlenght;
			}
		}
	printf("Valeur de  0 %zu\n", li.zerolenght);
	printf("Valeur de  . %zu\n", li.dotlenght);
	printf("Valeur de  space  %zu\n", li.spacelenght);
	
	return (li);
}

/*le 1er rgument de la list ap renvoie la widht */
t_parameter		setupstar(t_parameter li, char *str)
{
	(void)str;
	li.star = true;
	return(li);
}