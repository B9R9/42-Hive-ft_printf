/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:13:09 by briffard          #+#    #+#             */
/*   Updated: 2022/04/01 15:57:00 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

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

char *parse_str(char *dest, t_parameter li, char *source)
{
    char *temp;
    size_t i;

    temp = dest;
    i = 0;
    while (i < li.precision || i < ft_strlen(temp))
    {
        temp[i] = source[i];
        i++;
    }
    while (ft_strlen(temp) < li.width )
    {
        if(li.flags & F_ZERO)
            temp = ft_strjoin("0",temp);
        else if(li.flags & F_GRAVE)
            temp = ft_charjoin(li.char_to_print, temp);
        else
            temp = ft_strjoin(" ", temp);
        i++;
    }
    if(li.flags & F_MINUS)
        ft_reverse_str(temp);
    dest = temp;
    return (dest);
}

// char *addspaces(char *str, t_parameter li, size_t space)
// {
//     int i;

//     i = 0;
//     while (space > l)
//     {
//         str[i] = ' ';
//         space--;
//         i++;
//     }
//     return (str);
// }
