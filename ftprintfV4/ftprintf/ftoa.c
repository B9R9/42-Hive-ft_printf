/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:18:48 by briffard          #+#    #+#             */
/*   Updated: 2022/03/23 17:08:24 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
/*
static long  ft_pow(int number, int pow)
{
    int i;
    long ret;
    //printf("NUMBER IN FTPOW = ->%d<-\n", number);
    //printf("POW IN FTPOW = ->%d<-\n", pow);
    i = 0;
    ret = number;
    while(i < (pow - 1))
    {
        ret =  ret * number; 
        i++;
    }
    //printf("RETOUR FT_pow = ->%ld<-\n", ret);
    return ret;
}*/
/*
static char *intToStr(int num, char *dest, int size)
{
    int i;

    i = 0;
    while(num)
    {
        dest[i++] = (num % 10) + '0';
        num = num / 10;
    }
    while (i < size)
        dest[i] = '0';
    reverse(dest,i);
    dest[i] = '\0';
    return i;
}
*/
static char *ftoa(t_parameter li, double number)
{ 
    int     ipart;
    size_t     i = 1;
    double   fpart = 0;
    char    *dest = NULL;
    size_t addspace = 0;
    // size_t lenght = 0;

    
    // printf("TEST00\n");
    ipart = (int)number;
    fpart = number - (float)ipart;
    printf("ipart = ->%d<-\n",ipart);
    printf("fpart = ->%.15f<-\n",fpart);
    if(!li.dot)
        li.precision = 6;
    printf("precision = ->%zu<-\n",li.precision);
    printf("Numlenght = ->%d<-\n",ft_numlenght(ipart));
    size_t minSizeBox = (ft_numlenght(ipart)) + 1 + li.precision;
    printf("minSizeBox = ->%zu<-\n", minSizeBox);
    if(li.width > minSizeBox)
       { dest = ft_itona(ipart, li.width - minSizeBox + ft_numlenght(ipart));
        addspace = li.width - minSizeBox;
        printf("ADDSPACE VALUE: ->%zu<-\n", addspace);
       }
    else
    {
        dest = ft_itona(ipart, ft_numlenght(ipart));
    }
    printf("DEST after ITOA= ->%s<-\n",dest);
    if(li.precision != 0)
    {
        dest = ft_strjoin(dest, ".");
        
        printf("@IN IF fpart = ->%.15f<-\n",fpart);
        while (i < li.precision + 1)
        {
            fpart = fpart * 10;
            printf("IN IF fpart = ->%.15f<-\n",fpart);
            dest = ft_strjoin(dest, ft_itoa((int)fpart));
            fpart = fpart - (int)fpart;
            i++;
        }
    }
    i = 0;
    if(addspace > 0)
    {
        while (addspace > li.positif)
        {
             dest[i] = ' ';
            addspace--;
            i++;
        }
            
    }
    if(li.positif && li.width > li.precision)
        dest[i] = '+';
    else if (li.positif) 
        dest = ft_strjoin("+", dest);
    printf("DEST = ->%s<-\n",dest);
    /*Calculer la taille du premiere containeur*/
    /* 1er partie :
    2eme partie : precision || par default 6
     precision + numlenght + '.'
    */
    
    // if (li.precision < lenght)
    //     li.precision = lenght;
    // if (li.precision < li.width)
    // {
    //     addspace = li.width - li.precision;
    //     li.precision = li.width;
    // }
    //dest = ft_strnew((li.precision) + ft_numlenght(ipart) + 1);
    //i = intToStr(ipart, dest, 0);
	return(dest);
}

char *argtofloat(t_parameter li, va_list ap)
{
    return (ftoa(li, va_arg(ap, double)));
}