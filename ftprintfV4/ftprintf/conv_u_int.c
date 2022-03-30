/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:41:18 by briffard          #+#    #+#             */
/*   Updated: 2022/03/30 10:55:37 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char *ft_uitoa(t_parameter li, unsigned int c)
{
    char    *temp;
    char    *containeur;
    unsigned long     n = c + 1;
    int count = 0;
    
    if ( c > 4294967295)
    {
        while ((n * count) <= c)
            count++;
        temp = ft_u_itoa(c - (n * count));
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
        return(u_ll_intoa(li, va_arg(ap, unsigned long long)));
    else if(!ft_strcmp(li.sizePrefix, "l"))
        return(u_ll_intoa(li, va_arg(ap, unsigned long)));
    else if(!ft_strcmp(li.sizePrefix, "h"))
        return(u_short_intoa(li, (unsigned short)va_arg(ap, int)));
    else if(!ft_strcmp(li.sizePrefix, "hh"))
        return(u_chartoa(li, (unsigned char)va_arg(ap, int)));
    else
        return(ft_uitoa(li, va_arg(ap, unsigned int)));
}