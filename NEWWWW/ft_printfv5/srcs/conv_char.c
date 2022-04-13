/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:54:07 by briffard          #+#    #+#             */
/*   Updated: 2022/04/13 15:27:54 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *chartoarr(t_parameter li, char c);
/*Convert char to a string*/

static char *chartoarr(t_parameter li, char c)
{
    char    *dest;

    if (li.conv == '%')
        return ("%");    
    dest = ft_strnew(1);
    if (!dest)
		exit(EXIT_FAILURE);
    dest[0] = c;
    dest = setstr(dest, li, dest); 
    return(dest);    
}

/*Turn va_arg into an int*/
char *argtochar(t_parameter li, va_list ap)
{
    return(chartoarr(li, va_arg(ap, int)));
}