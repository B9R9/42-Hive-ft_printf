/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sizePrefix_for_flag_u.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:37:02 by briffard          #+#    #+#             */
/*   Updated: 2022/03/29 17:41:43 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char    *u_chartoa(t_parameter li, unsigned char number)
{
    char    *temp;
    char    *containeur;
    int n = 256;
    int count = 0;
    
    if ( number > 255 )
    {
        while ((n * count) <= number)
            count++;
        temp = ft_itoa(number - (256 * count));
    }
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