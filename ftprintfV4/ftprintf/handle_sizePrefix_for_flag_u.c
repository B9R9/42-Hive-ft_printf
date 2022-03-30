/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sizePrefix_for_flag_u.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:37:02 by briffard          #+#    #+#             */
/*   Updated: 2022/03/30 11:00:49 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

/*creer une fucntion qui renvoie n dependant de li.sizePrefix flag
On peut auusi la placer dans conv_u_int elle renverrai un int n*/
char    *u_chartoa(t_parameter li, unsigned char number)
{
    char    *temp;
    char    *containeur;
    // int n = 256; NOT NEEDED
    // int count = 0;
    
    // if ( number > 255 )
    // {
    //     while ((n * count) <= number)
    //         count++;
    //     temp = ft_u_itoa(number - (n * count));
    // }
    // else 
        temp = ft_u_itoa(number);
        
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

char    *u_short_intoa(t_parameter li, unsigned short number)
{
    char *temp;
    char *containeur;
    
    // int n = 65536; PAS NECESSAIRE 
    // int count = 0;
    
    // if ( number > (n - 1) )
    // {
    //     printf("TEST\n");
    //     while ((n * count) <= number)
    //         count++;
    //     temp = ft_u_itoa(number - (n * count));
    // }
    // else 
        temp = ft_u_itoa(number);
        
    
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
    containeur =  temp;
    ft_memdel((void **)&temp);
    return (containeur);
}

char    *u_ll_intoa(t_parameter li, unsigned long long number)
{
    char *temp;
    char *containeur;
    
    temp = ft_u_itoa(number);
        
    
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
    containeur =  temp;
    ft_memdel((void **)&temp);
    return (containeur);
    
}

