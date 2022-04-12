/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:10:45 by briffard          #+#    #+#             */
/*   Updated: 2022/04/12 14:52:37 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_containeur    *split(t_containeur *list, va_list ap, const char *format);
static void    printlist(t_containeur *li);
static char    *dispacht(va_list ap, t_parameter *new);

/*DIPSPACHT FLAG INTO THE RIGHT FUNCTION*/
static char    *dispacht(va_list ap, t_parameter *new)
{
	return (funcFlagsArray[new->conv - 'a'](new, ap));
}

/*PRINT LIST*/
static void    printlist(t_containeur *li)
{
    while (li != NULL)
        {
            ft_putstr(li->box);
            li = li->next;
        }
}

/*SLIPT FORMAT TO A CHAINED LIST*/
static t_containeur    *split(t_containeur *list, va_list ap, const char *format)
{
    t_parameter *new;
    char        *temp;
    int         index;

    index = 0;
    while(format[index] != '\0')
    {
        if (format[index] == '%')
        {
            new = init(&format[index], new, ap);
            temp = dispacht(ap, new);
            printf("->%s",temp);
            list = push_back(list, temp);
            index += new->size;
        }
        else
        {
            
        }
        index++;
    }
    return (list);
}

int ft_printf(const char *format, ...)
{
    t_containeur    *containeur;
    va_list         ap;
    
    containeur = NULL;
    va_start(ap, format);
    containeur =  split(containeur, ap, format);
    va_end(ap);
    printlist(containeur);
    return(0);
}