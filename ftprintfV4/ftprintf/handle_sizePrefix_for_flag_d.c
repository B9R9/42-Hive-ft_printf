/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sizePrefix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:15:55 by briffard          #+#    #+#             */
/*   Updated: 2022/03/29 16:34:17 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char    *char_to_arr(t_parameter li, char number)
{
    char    *temp;
    char    *containeur;
    

    if ( number < -128 )
        temp = ft_itoa( number + 255 + 1); 
    else if (number > 127)
        temp = ft_strjoin("-",ft_itoa( number - 255 - 1)); 
    else
        temp = ft_itoa(number);
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

char    *short_int_to_arr(t_parameter li, short int number)
{
    char    *containeur;
    char    *temp;
    
    temp = ft_u_short_itoa(number);
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

char    *l_int_to_arr(t_parameter li, long number)
{
    char    *containeur;
    char    *temp;
    
    temp = ft_ll_itoa(number);
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

char    *ll_int_to_arr(t_parameter li, long long number)
{
    char    *containeur;
    char    *temp;
    
    temp = ft_ll_itoa(number);
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