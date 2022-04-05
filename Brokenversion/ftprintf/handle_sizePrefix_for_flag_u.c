/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sizePrefix_for_flag_u.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:37:02 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 15:42:53 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

/*creer une fucntion qui renvoie n dependant de li.sizePrefix flag
On peut auusi la placer dans conv_u_int elle renverrai un int n*/
char    *u_chartoa(t_parameter li, unsigned char number)
{
    char    *temp;
    char    *containeur;

    temp = ft_u_itoa(number);
    temp =  parse_int(li, temp);
    containeur = temp;
    ft_memdel((void *) &temp);    
    return (containeur);  
}

char    *u_short_intoa(t_parameter li, unsigned short number)
{
    char *temp;
    char *containeur;
    

    temp = ft_u_itoa(number);
    temp =  parse_int(li, temp);   
    containeur =  temp;
    ft_memdel((void *)&temp);
    return (containeur);
}

char    *u_ll_intoa(t_parameter li, unsigned long long number)
{
    char *temp;
    char *containeur;
    
    temp = ft_u_itoa(number);
    temp =  parse_int(li, temp);    
    containeur =  temp;
    ft_memdel((void *)&temp);
    return (containeur);
    
}

