/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:54:07 by briffard          #+#    #+#             */
/*   Updated: 2022/03/28 16:47:48 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char *chartoarr(t_parameter li, char c)
{
    char    *temp;
    char    *dest;

    if (li.flag == '%')
        return ("%");    
    dest = ft_strnew(1);
    if (!dest)
	{
		ft_errormem("chartoarr.c", 22);
		exit(EXIT_FAILURE);
	}
    dest[0] = c;
    dest = parse_str(dest, li, dest);
    temp = dest;
    ft_memdel ((void **) &dest);
    dest = temp;
    return(dest);    
}

char *argtochar(t_parameter li, va_list ap)
{
    return(chartoarr(li, va_arg(ap, int)));
}