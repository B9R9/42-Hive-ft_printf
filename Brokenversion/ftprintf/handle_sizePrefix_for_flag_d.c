/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sizePrefix_for_flag_d.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:15:55 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 15:43:01 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char    *char_to_arr(t_parameter li, char number)
{
    char    *temp;
    char    *containeur;
    

    if ( number < -128 )
        temp = ft_itoa(number + 255 + 1); 
    else if (number > 127)
        temp = ft_strjoin("-",ft_itoa( number - 255 - 1)); 
    else
        temp = ft_itoa(number);
    temp =  parse_int(li, temp);
    containeur = temp;
    ft_memdel((void *) &temp);    
    return (containeur); 
}

char    *short_int_to_arr(t_parameter li, short int number)
{
    char    *containeur;
    char    *temp;
    
    temp = ft_u_itoa(number);
    temp =  parse_int(li, temp);
    containeur = temp;
    ft_memdel((void *) &temp);
    return (containeur); 
}

char    *l_int_to_arr(t_parameter li, long number)
{
    char    *containeur;
    char    *temp;
    
    temp = ft_ll_itoa(number);
    temp =  parse_int(li, temp);
    containeur = temp;
    ft_memdel((void *) &temp);
    return (containeur);
}

char    *ll_int_to_arr(t_parameter li, long long number)
{
    char    *containeur;
    char    *temp;
    
    temp = ft_ll_itoa(number);
    temp =  parse_int(li, temp);
    containeur = temp;
    ft_memdel((void *) &temp);
    return (containeur);
}