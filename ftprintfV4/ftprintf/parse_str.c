/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:13:09 by briffard          #+#    #+#             */
/*   Updated: 2022/03/29 10:01:03 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"


char *parse_str(char *dest, t_parameter li, char *source)
{ 
    size_t i;
    
    i = 0;
    while (i < li.precision)
    {
        dest[i] = source[i];
        i++;
    }
    while (ft_strlen(dest) < li.width)
    {
        if(li.negatif)
            dest = ft_strjoin(dest, " ");
        else
            dest = ft_strjoin(" ", dest);
    }
    return (dest);
}

char *addspaces(char *str, t_parameter li, size_t space)
{
    int i;

    i = 0;
    while (space > li.positif)
    {
        str[i] = ' ';
        space--;
        i++;
    }
    return (str);
}

char	*ft_reverse_str(char *dest)
{
	int	x;

	x = 0;
	while (dest[0] == ' ')
	{
		x = 0;
		while (dest[x + 1] != '\0')
		{
			ft_swap(&dest[x], &dest[x + 1]);
			x++;
		}
	}
	return (dest);
}