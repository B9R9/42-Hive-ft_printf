/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttoarr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:03:31 by briffard          #+#    #+#             */
/*   Updated: 2022/03/22 13:00:50 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char *inttoarr(t_parameter li, int number)
{
    char    *dest;
    size_t    lenght;
    size_t      addspace;
    int i = 0;
    addspace = 0;
    lenght = ft_numlenght(number);
    if (li.precision < lenght)
        li.precision = lenght;
    if (li.precision < li.width)
    {
        addspace = li.width - li.precision;
        li.precision = li.width;
    }
    // printf("LENGHT: ->%zu<-\n", lenght);
    dest = ft_itona(number, li.precision);
    // printf("DEST: ->%s<-\n", dest);
    /*
    if(li.zero || li.dot)
        dest = ft_strjoin(fillit('0', (li.zerolenght - ft_strlen(dest))), dest);
    */
    printf("TEST: ->%s<-\n", dest);
    printf("ADDSPACE VALUE: ->%zu<-\n", addspace);
    if(addspace > 0)
        {
            while (addspace > li.positif)
            {
                dest[i] = ' ';
                addspace--;
                printf("ADDSPACE VALUE: ->%zu<-\n", addspace);
                i++;
            }
            
        }
    printf("TEST: ->%s<-\n", dest);
    if(li.positif && number >= 0 && li.width >= (lenght))
        dest[i] = '+';
    else if (li.positif && number >= 0 && ft_strlen(dest) == li.precision)
        dest = ft_strjoin("+", dest);
    printf("FOCUS TEST: ->%s<-\n", dest);
    int x = 0;
    if (li.negatif)
    {
        printf("FOCUS TEST: ->%s<-\n", dest);
        while (dest[0] == ' ')
        {
            x = 0;
            while(dest[x + 1] != '\0')
            {
                ft_swap(&dest[x], &dest[x + 1]);
                printf("RESULT FOCUS TEST: ->%s<-\n", dest);
                x++;
            }
            printf("TEST LOOP\n");    
        }
    }
    printf("Result TEST: ->%s<-\n", dest);

    return(dest);
}

char    *argtoint(t_parameter li, va_list ap)
{
     //ft_debug("green", "argtoint", 00, "NULL", -1);
    return (inttoarr(li, va_arg(ap, int)));
}