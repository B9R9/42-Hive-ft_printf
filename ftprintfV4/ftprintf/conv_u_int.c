/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:41:18 by briffard          #+#    #+#             */
/*   Updated: 2022/03/29 17:29:39 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char *ft_uitoa(t_parameter li, unsigned int c)
{
    char    *temp;
    char    *containeur;

    if ( c > 4294967295)// ne compilera probablement pas
    {
        ft_errormes(" error: implicit conversion from 'long' to 'unsigned int' changes value\n");
        exit(EXIT_FAILURE);
    }
    else
        temp = ft_u_itoa(c);
    while(ft_strlen(temp) < li.precision && li.width > li.precision)
            temp = ft_strjoin("0", temp);
    if((li.space || li.width > li.precision) && !li.positif)
        while(ft_strlen(temp) < li.width)
            temp = ft_strjoin(" ", temp);
    if(li.positif)
    {
        temp = ft_strjoin("+", temp);
        while(ft_strlen(temp) < li.width)
            temp = ft_strjoin(" ", temp);
    }
    if(li.negatif)
        ft_reverse_str(temp);
    containeur = temp;
    ft_memdel((void **) &temp);    
    return (containeur);
}

char *argto_u_int(t_parameter li, va_list ap)
{
        if(!ft_strcmp(li.sizePrefix,"ll"))
        return(ll_int_to_arr(li, va_arg(ap, long long)));
    else if(!ft_strcmp(li.sizePrefix, "l"))
        return(l_int_to_arr(li, va_arg(ap, long)));
    else if(!ft_strcmp(li.sizePrefix, "h"))
        return(short_int_to_arr(li, (short)va_arg(ap, int)));
    else if(!ft_strcmp(li.sizePrefix, "hh"))
        return(u_chartoa(li, (unsigned char)va_arg(ap, int)));
    else
        return(ft_uitoa(li, va_arg(ap, unsigned int)));
}