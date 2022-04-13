/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:11:05 by briffard          #+#    #+#             */
/*   Updated: 2022/04/13 15:22:59 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *strtoa(char *str, t_parameter li);

/*SET STR WITH PARAMETER*/
char *setstr(char *dest, t_parameter li, char *source)
{
    char    *temp;
    size_t  i;

    i = 0;
    while (i < (size_t)li.precision || i < ft_strlen(dest))
    {
        dest[i] = source[i];
        i++;
    }
    while ((int)ft_strlen(dest) < li.width )
    {
        if(li.flags & F_ZERO)
            temp = ft_strjoin("0", dest);
        else
            temp = ft_strjoin(" ", dest);
        ft_memdel((void **)&dest);
        dest = temp;
        i++;
    }
    if(li.flags & F_MINUS)
        align_right(dest);
    return (dest);
}

static char    *strtoa(char *str, t_parameter li)
{
    char    *dest;
    
    if(!str)
        return (ft_strdup("NULL"));
    if (!li.precision)
        li.precision = ft_strlen(str);
    dest = ft_strnew(li.precision);
    if (!dest)
        exit(EXIT_FAILURE);
    dest = setstr(dest, li, str);
    return (dest);
}

/*TURN ARGUMENT TO STR*/
char    *argtostr(t_parameter li, va_list ap)
{
    return (strtoa(va_arg(ap, char *), li));
}