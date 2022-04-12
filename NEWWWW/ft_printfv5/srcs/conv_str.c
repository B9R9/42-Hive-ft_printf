/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:11:05 by briffard          #+#    #+#             */
/*   Updated: 2022/04/12 17:08:41 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *strtoa(char *str, t_parameter li);
static char *setstr(char *dest, t_parameter li, char *source);

/*SET STR WITH PARAMETER*/
static char *setstr(char *dest, t_parameter li, char *source)
{
    char    *temp;
    size_t  i;

    temp = dest;
    i = 0;
    while (i < (size_t)li.precision || i < ft_strlen(temp))
    {
        temp[i] = source[i];
        i++;
    }
    while ((int)ft_strlen(temp) < li.width )
    {
        if(li.flags & F_ZERO)
            temp = ft_strjoin("0",temp);
        else
            temp = ft_strjoin(" ", temp);
        i++;
    }
    if(li.flags & F_MINUS)
        ft_reverse_str(temp);
    dest = temp;
    return (dest);
}

static char    *strtoa(char *str, t_parameter li)
{
    char    *temp;
    char    *dest;
    
    if(!str)
        return (ft_strdup("NULL"));
    if (!li.precision)
        li.precision = ft_strlen(str);
    temp = ft_strnew(li.precision);
    if (!temp)
        exit(EXIT_FAILURE);
    temp = setstr(temp, li, str);
    dest = temp;
    ft_memdel((void *)&temp);
    return (dest);
}

/*TURN ARGUMENT TO STR*/
char    *argtostr(t_parameter li, va_list ap)
{
    return (strtoa(va_arg(ap, char *), li));
}