/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:10:45 by briffard          #+#    #+#             */
/*   Updated: 2022/04/13 12:09:31 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_containeur    *split(t_containeur *list, va_list ap, const char *format);
static void    printlist(t_containeur *li);
static char    *dispacht(va_list ap, t_parameter new);

/*PRINT PARAMETER*/
void    check_parameter(t_parameter li)
{
    printf("WIDTH           -->%d\n", li.width);
    printf("FLAG            -->%c\n", li.conv);
    printf("upper           -->%d\n", li.upper);
    printf("precision       -->%d\n", li.precision);
    printf("char_to_skip    -->%d\n", li.char_to_skip);
    printf("size_Prefix     -->%s\n", li.sizePrefix);
    printf("size            -->%d\n", li.size);
}

/*DIPSPACHT FLAG INTO THE RIGHT FUNCTION*/
static char    *dispacht(va_list ap, t_parameter new)
{
	return (funcFlagsArray[new.conv - 'a'](new, ap));
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
static t_containeur    *split(t_containeur *list, va_list ap, const char *str)
{
    t_parameter new;
    char        *temp;
    int         index;
    int         start;

    index = 0;
    while(str[index] != '\0')
    {
        if (str[index] == '%')
        {
            new = init(&str[index], new, ap);
            check_parameter(new);
            temp = dispacht(ap, new);
            list = push_back(list, temp);
            index += new.size + 1 ;
        }
        else
        {
            start = index;
			while (str[index] != '%' && str[index] != '\0')
				index++;
			temp = ft_strsub(str, start, index - start);
			list = push_back(list,temp);
        }
        // ft_bzero(temp, ft_strlen(temp)); Created a problem I dont why ?
    }
    ft_memdel((void *)&temp);
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
    clearlist(containeur);
    containeur = NULL;
    return(0);
}