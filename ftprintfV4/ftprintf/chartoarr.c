/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartoarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:54:07 by briffard          #+#    #+#             */
/*   Updated: 2022/03/17 08:17:37 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char *chartoarr(t_parameter li, char c)
{
    int     index;
    char    *dest;
    (void)  li;

    index = 0;
    dest = ft_strnew(1);
    if (!dest)
	{
		ft_errormem("chartoarr.c", 19);
		exit(EXIT_FAILURE);
	}
    dest[0] = c;
    return(dest);    
}

char *argtochar(t_parameter li, va_list ap)
{
    return(chartoarr(li, va_arg(ap, int)));
}