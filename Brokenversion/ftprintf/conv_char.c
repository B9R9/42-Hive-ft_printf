/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:54:07 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 15:53:56 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

/*Convert char to a string*/

static char *chartoarr(t_parameter li, char c)
{
    char    *temp;
    char    *dest;

    if (li.conv == '%')
        return ("%");    
    temp = ft_strnew(1);
    if (!dest)
	{
		ft_errormem("chartoarr.c", 24);
		exit(EXIT_FAILURE);
	}
    temp[0] = c;
    temp = parse_str(dest, li, dest);
    dest = temp;
    // ft_memdel((void **) &temp);
    return(dest);    
}

/*Turn va_arg into an int*/
char *argtochar(t_parameter li, va_list ap)
{
    return(chartoarr(li, va_arg(ap, int)));
}