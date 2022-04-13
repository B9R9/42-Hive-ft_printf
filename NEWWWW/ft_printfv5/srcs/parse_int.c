/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:01:24 by briffard          #+#    #+#             */
/*   Updated: 2022/04/13 17:19:01 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    format_precision(char *str, t_parameter li)
{
    while((int)ft_strlen(str) <= li.width)
        str = ft_strjoin_replace("0", str, 1);   
}

void    format_width(char *str, t_parameter li)
{
    int     i;
    int     x = 0;
    i = li.precision;
    if (li.flags & F_PLUS)
    {
        if((int)ft_strlen(str) == li.width)
            str[0] = '+';
        else
            str = ft_strjoin_replace("+", str, 1);
    }
    while(i < li.width )
        {
            str[x] = ' ';
            i++;
            x++;
        }
}
char    *parse_int(t_parameter li, char *source)
{
    char    *tmp;
    
    if(!li.precision)
        li.precision = ft_strlen(source);
    tmp = ft_strnew(ft_abs_int(li.width - li.precsion));
    format_precision(source,li);
    format_width(source,li);
    // while(((int)ft_strlen(source) < li.precision && (int)ft_strlen(source) < li.width) \
    // || (int)ft_strlen(source) < li.width)
    //         source = ft_strjoin_replace("0", source);
    // if (li.width >= li.precision)
    // {
    //     if(li.flags & F_PLUS)
    //     {
    //         if((int)ft_strlen(source) == li.width)
    //             source[0] = '+';
    //         else
    //             source = ft_strjoin_replace("+", source, 1);
    //     }
    // }
    if (li.flags & F_SPACE && (int)ft_strlen(source) > li.width)
        source = ft_strjoin_replace(" ", source, 1);
    if (li.flags & F_MINUS)
    {
        if(li.flags & F_SPACE)
            align_right(&source[1]);
        else
            align_right(source);
    }
    return (source);
}