/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttoarr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:03:31 by briffard          #+#    #+#             */
/*   Updated: 2022/03/17 15:33:11 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char *inttoarr(t_parameter li, int number)
{
    char *dest;

    dest = ft_itoa(number);
    if(li.zero || li.dot)
        dest = ft_strjoin(fillit('0', (li.zerolenght - ft_strlen(dest))), dest);
    if(li.space)
        dest = ft_strjoin(fillit(' ', li.spacelenght), dest);
    return(dest);
}

char    *argtoint(t_parameter li, va_list ap)
{
     ft_debug("green", "argtoint", 00, "NULL", -1);
    return (inttoarr(li, va_arg(ap, int)));
}