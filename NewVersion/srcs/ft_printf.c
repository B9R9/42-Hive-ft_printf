/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:24:41 by briffard          #+#    #+#             */
/*   Updated: 2022/04/15 14:10:47 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    check_parameter(t_parameter *li); //  -> to remove
static int    dispacht(va_list ap, t_parameter *new);

/*
** Receive va_list and send to the right function
*/
static int    dispacht(va_list ap, t_parameter *new)
{
	return (funcFlagsArray[new->conv - 'a'](new, ap));
}


int ft_printf(const char *format, ...)
{
    t_parameter *option;
    va_list     ap;
    int         size;
    int         i;

    size = 0;
    i = 0;
    option = NULL;
    va_start(ap, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            option = init(&format[i], option, ap);
            // check_parameter(option);
            size += dispacht(ap, option);
            i += option->size + 1;
        }
        else
        {
            size += print_char(format[i]);
            i++;
        }
    }
    va_end(ap);
    return (size);
}

/*TO REMOVE*/
/*PRINT PARAMETER*/
void    check_parameter(t_parameter *li)
{
    printf("WIDTH           -->%d\n", li->width);
    printf("FLAG            -->%c\n", li->conv);
    printf("upper           -->%d\n", li->upper);
    printf("precision       -->%d\n", li->precision);
    printf("char_to_skip    -->%d\n", li->char_to_skip);
    printf("size_Prefix     -->%s\n", li->sizePrefix);
    printf("size            -->%d\n", li->size);
}
