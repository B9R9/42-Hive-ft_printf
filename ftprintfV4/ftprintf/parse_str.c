/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:13:09 by briffard          #+#    #+#             */
/*   Updated: 2022/03/28 17:15:05 by briffard         ###   ########.fr       */
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