/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttoarr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:03:31 by briffard          #+#    #+#             */
/*   Updated: 2022/03/18 18:13:13 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char *inttoarr(t_parameter li, int number)
{
    char    *dest;
    int     lenght;

    ft_debug("yellow", "inttoarr", 00, "NULL", number);
    lenght = ft_numlenght(number);
    ft_debug("yellow", "inttoarr", 01, "NULL", lenght);
    ft_debug("yellow", "inttoarr", 02, "NULL", li.zerolenght);
    ft_debug("yellow", "inttoarr", 03, "NULL", lenght);
    if(li.zero || li.dot)
        lenght += li.zerolenght - lenght;
    ft_debug("yellow", "inttoarr", 04, "NULL", lenght);
    dest = ft_itona(number, lenght);
    ft_debug("yellow", "inttoarr", 05, dest, lenght);
    /*
    if(li.zero || li.dot)
        dest = ft_strjoin(fillit('0', (li.zerolenght - ft_strlen(dest))), dest);
    */
    if(li.signe && number >= 0)
        dest = ft_strjoin("+", dest);
    /*if(li.space)
        dest = ft_strjoin(fillit(dest, ' ', li.spacelenght), dest);
   
    */
    return(dest);
}

char    *argtoint(t_parameter li, va_list ap)
{
     //ft_debug("green", "argtoint", 00, "NULL", -1);
    return (inttoarr(li, va_arg(ap, int)));
}