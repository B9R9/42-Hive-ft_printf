/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:01:24 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 14:33:22 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char    *parse_int(t_parameter li, char *source)
{
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
            align_right(&source[1]);
        else
            align_right(source);
    }
    return (source);
}

char    *parse_ptr(t_parameter li, char *source)
{
    while(ft_strlen(source) < li.precision)
            source = ft_strjoin("0", source);
    source = ft_strjoin("0x", source);
    while(ft_strlen(source) < li.width )
            source = ft_strjoin(" ", source);
    if (li.flags & F_SPACE && ft_strlen(source) > li.width)
        source = ft_strjoin(" ", source);
    if (li.flags & F_MINUS)
    {
        if(li.flags & F_SPACE)
            align_right(&source[1]);
        else
            align_right(source);
    }
    return (source);
}

char    *parse_hexa_or_oct(t_parameter li, char *source)
{
    while(ft_strlen(source) < li.precision)
        source = ft_strjoin("0", source);
    if (li.flags & F_HASHTAG)
        source = ft_strjoin("0x", source);
        while(ft_strlen(source) < li.width )
            source = ft_strjoin(" ", source);
    if (li.flags & F_SPACE && ft_strlen(source) > li.width)
        source = ft_strjoin(" ", source);
    if (li.flags & F_MINUS)
    {
        if(li.flags & F_SPACE)
            align_right(&source[1]);
        else
            align_right(source);
    }
    if(li.upper)
        ft_strtoupper(source);
    return (source);  
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
        // else if(li.flags & F_GRAVE)
        //     temp = ft_charjoin(li.char_to_print, temp);
        else
            temp = ft_strjoin(" ", temp);
        i++;
    }
    if(li.flags & F_MINUS)
        ft_reverse_str(temp);
    dest = temp;
    return (dest);
}