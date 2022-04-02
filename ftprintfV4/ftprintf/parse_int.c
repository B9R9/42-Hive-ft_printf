/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:01:24 by briffard          #+#    #+#             */
/*   Updated: 2022/04/02 16:05:14 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char    *parse_int(t_parameter li, char *source)
{
    //printf("LENGHT = %zu || PRECI = %d || width = %d\n", ft_strlen(source), li.precision, li.width);
    while((ft_strlen(source) < li.precision && ft_strlen(source) < li.width) \
    || ft_strlen(source) < li.width)
            source = ft_strjoin("0", source);
    if (li.width > li.precision)
    {
        if(li.flags & F_PLUS)
        {
            if(ft_strlen(source) == li.width)
                source[0] = '+';
            else
                source = ft_strjoin("+", source);
        }
        while(ft_strlen(source) < li.width )
            source = ft_strjoin(" ", source);
    }
    if (li.flags & F_SPACE && ft_strlen(source) > li.width)
        source = ft_strjoin(" ", source);
    if (li.flags & F_MINUS)
    {
        if(li.flags & F_SPACE)
            ft_reverse_str(&source[1]);
        else
            ft_reverse_str(source);
    }
    return (source);
}