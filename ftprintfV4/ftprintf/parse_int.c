/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:01:24 by briffard          #+#    #+#             */
/*   Updated: 2022/04/01 17:06:27 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char    *parse_int(t_parameter li, char *source)
{
    while(ft_strlen(source) < li.precision || ft_strlen(source) < li.width)
            source = ft_strjoin("0", source);
    if (li.flags & F_SPACE || li.width > li.precision)
    {
        if(li.flags & F_PLUS)
            source = ft_strjoin("+", source);
        while(ft_strlen(source) < li.width)
            source = ft_strjoin(" ", source);
    }
    if (li.flags & F_MINUS)
        ft_reverse_str(source);
    return (source);
}