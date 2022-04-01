/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:03:31 by briffard          #+#    #+#             */
/*   Updated: 2022/04/01 16:13:39 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

// static char	*addsigne(char *dest)
// {
// 	int	i;

// 	i = 0;
// 	while (dest[i] == ' ')
// 		i++;
// 	dest[i] = '+';
// 	return (dest);
// }

static char	*inttoarr(t_parameter li, int number)
{
	char    *containeur;
    char    *temp;
    
    
    temp = ft_itoa(number);
    temp = parse_int(li, temp);
    // while(ft_strlen(temp) < li.precision && li.width > li.precision)
    //         temp = ft_strjoin("0", temp);
    // if((li.space || li.width > li.precision) && !li.positif)
    //     while(ft_strlen(temp) < li.width)
    //         temp = ft_strjoin(" ", temp);
    // if(li.positif)
    // {
    //     temp = ft_strjoin("+", temp);
    //     while(ft_strlen(temp) < li.width)
    //         temp = ft_strjoin(" ", temp);
    // }
    // if(li.signeneg)
    //     ft_reverse_str(temp);
    containeur = temp;
    ft_memdel((void **) &temp);
	return (containeur);
}

char	*argtoint(t_parameter li, va_list ap)
{
    if(!ft_strcmp(li.sizePrefix,"ll"))
        return(ll_int_to_arr(li, va_arg(ap, long long)));
    else if(!ft_strcmp(li.sizePrefix, "l"))
        return(l_int_to_arr(li, va_arg(ap, long)));
    else if(!ft_strcmp(li.sizePrefix, "h"))
        return(short_int_to_arr(li, (short)va_arg(ap, int)));
    else if(!ft_strcmp(li.sizePrefix, "hh"))
        return(char_to_arr(li, (char)va_arg(ap, int)));
    else
		return (inttoarr(li, va_arg(ap, int)));
}
