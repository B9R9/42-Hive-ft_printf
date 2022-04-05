/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:18:48 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 16:43:18 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

/*Get digit == precision + 1 to make the rouding*/
static int     getroudingdigit(int precision,long double fpart)
{
    int     i;

    i = 0;
    while (i < precision)
    {
        fpart = fpart * 10;
        fpart = fpart - (long long) fpart;
        i++;
    }
    return (fpart * 10);
}

/*ADD float part to the str*/
static char    *set_fpart(char *str, t_parameter li, long double fpart)
{
    int     i;
    char    *tempo;


    str = ft_strjoin(str, ".");

    printf("STR--> %s\n", str);
    while(i < li.precision)
    {
        fpart = fpart * 10;
        printf("IN SET_FPART Fpart -> %Lf\n", fpart);
        tempo = ft_itoa((int)fpart);
        printf("->%s<-\n", tempo);
        str = ft_strjoin(str,tempo);
        printf("->%s<-\n", str);
        fpart = fpart - (int)fpart;
        i++;
    }


    return (str);
    // int     i;
    // char *temp;
    
    // i = 0;
    // str = ft_strjoin(str, ".");
    // printf("IN SET_FPART 1str -> %s\n", str);
    // printf("PRECISION == %d || i == %d\n", li.precision, i);
    // while (i < li.precision)
    // {
    //     fpart = fpart * 10;
    //     printf("IN SET_FPART Fpart -> %Lf\n", fpart);
    //     if ((int)fpart == 0)
    //         str = ft_strjoin(str, "0");
    //     else
    //         {
    //             temp = ft_itoa((int) fpart);
    //             printf("IN SET_FPART temp -> %s\n", temp);
    //             printf("IN SET_FPART 2str -> %s\n", str);
    //             str = ft_strjoin(str, temp);
    //         }
    //     printf("IN SET_FPART 3str -> %s\n", str);
    //     fpart = fpart - (long long)fpart;
    //     i++;
    // }
    // return (str);
}

/* Turn a float/double into a string -- When sizePrefix L or l  is use*/
char *l_doubleToa(t_parameter li, long double number)
{
    char    *temp;
    char    *containeur;
    unsigned long long ipart;
    long double fpart;
    
    if (ft_isdoubleneg(number))
    {
        number =  number * -1;
        li.flags = li.flags | F_NEGATIF;
    }
    ipart = (long long)number;
    if ( ipart < 0)
        ipart *= -1;
    fpart = number - ipart;
    if(li.precision == 0)
        li.precision = 6;
    temp = ft_u_itoa(ipart);
    if(li.precision != 0)
        temp = set_fpart(temp, li, fpart);
    /*ROUDING PART*/
    ft_str_rounding(temp, getroudingdigit(li.precision, fpart), (ft_strlen(temp) - 1));
    containeur =  temp;
    ft_memdel((void *) &temp);
    return (containeur);
}

static char *ftoa(t_parameter li, double number)
{ 
    unsigned long long  ipart;
    long double   fpart;
    char    *temp;
    char    *containeur;

    printf("IN FTOA.C\n");
    if (ft_isdoubleneg(number)) // verifier si la sortie est negstif 
    {
        number =  number * -1;
        li.flags = li.flags | F_NEGATIF;
    }
    printf("IN FTOA.C number -> %f\n", number);
    printf("IN FTOA.C -> 00\n");
    ipart = (unsigned long long)number;
    printf("IN FTOA.C ipart -> %llu\n", ipart);
    fpart = number - (long double)ipart;
    printf("IN FTOA.C fpart -> %Lf\n", fpart);
    if(li.precision == 0)
        li.precision = 6;
    temp = ft_u_itoa(ipart);
    printf("IN FTOA.C temp -> %s\n", temp);
    if (li.flags & F_NEGATIF) // a ton besoinde cela si ft_is neg turn in positif number
        fpart = fpart * -1;
    if(li.precision != 0)
        temp = set_fpart(temp, li, fpart);
    printf("IN FTOA.C AFTER SET FPART temp -> %s\n", temp);
	/*ROUDING PART*/
    ft_str_rounding(temp, getroudingdigit(li.precision, fpart), (ft_strlen(temp) - 1));
	/*SET temp With width and preccision*/
    temp = parse_int(li, temp);
    containeur = temp;
    ft_memdel((void *)&temp);
	return(containeur);
}

/*turn va_arg into a double or long double*/
char *argtofloat(t_parameter li, va_list ap)
{
    if((!ft_strcmp(li.sizePrefix, "l")))
         return (l_doubleToa(li, va_arg(ap, long double)));
    return (ftoa(li, va_arg(ap, double)));
}
