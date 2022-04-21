/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sizePrefix_for_flag_d.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:15:55 by briffard          #+#    #+#             */
/*   Updated: 2022/04/20 13:44:40 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int char_to_arr(t_parameter *option, char number)
{
    char    *temp;
    int     size;

    size = 0;
    if (number < 0 && number > -127)
    {
        number *= -1;
        option->flags = option->flags | F_NEGATIF;
    }
    temp = ft_itoa(number);
    size = print_int(option, temp);
    ft_memdel((void *) &temp);
    return (size);
}

int short_int_to_arr(t_parameter *option, short int number)
{
    char    *temp;
    int     size;

    size = 0;
    temp = ft_itoa(number);
    size =  print_int(option, temp);
    ft_memdel((void *) &temp);
    return (size);
}

int ll_int_to_arr(t_parameter *option, long long number)
{
    char    *temp;
    int     size;

    if (number < 0)
    {
        number *= -1;
        option->flags = option->flags | F_NEGATIF;
    }
    size = 0;
    temp = ft_uitoa_base(number, 10);
    size =  print_int(option, temp);
    ft_memdel((void *) &temp);
    return (size);
}

int dispach_to_intSizePrefix(t_parameter *option, va_list ap)
{
    if(!ft_strcmp(option->sizePrefix,"ll"))
        return(ll_int_to_arr(option, va_arg(ap, long long)));
    else if(!ft_strcmp(option->sizePrefix, "l"))
        return(ll_int_to_arr(option, va_arg(ap, long)));
    else if(!ft_strcmp(option->sizePrefix, "h"))
        return(short_int_to_arr(option, (short)va_arg(ap, int)));
    else if(!ft_strcmp(option->sizePrefix, "hh"))
        return(char_to_arr(option, (char)va_arg(ap, int)));
    return(-1);
}
