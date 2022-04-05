/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_inttoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:41:18 by briffard          #+#    #+#             */
/*   Updated: 2022/03/28 09:16:43 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char *ft_uitoa(t_parameter li, unsigned int c)
{
    char *str;
    (void)(li);
        str = ft_u_itoa(c);
    return str;
}

char *argto_u_int(t_parameter li, va_list ap)
{
    return(ft_uitoa(li, va_arg(ap, unsigned int)));
}