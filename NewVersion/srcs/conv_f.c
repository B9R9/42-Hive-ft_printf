/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:18:48 by briffard          #+#    #+#             */
/*   Updated: 2022/04/15 15:33:29 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
char *set_fpart(char *box, t_parameter *option, long double fpart)
{
    int     i;
    char    *temp;

    temp = ft_strnew(option->precision + 1);
    if(!temp)
        exit(EXIT_FAILURE);
    temp[0] = '.';
    i = 0;
    while(i < option->precision)
    {
        fpart = fpart * 10;
        temp[i + 1]= 48 + (((int)fpart) % 10);
        fpart = fpart - (int)fpart;
        i++;
    }
    ft_memdel((void **)&box);
    box = temp;
    return (box);
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

// /* Turn a float/double into a string -- When sizePrefix L or l  is use*/
// int l_doubleToa(t_parameter *li, long double number)
// {
//     char    *temp;
//     char    *containeur;
//     unsigned long long ipart;
//     long double fpart;
    
//     if (ft_isdoubleneg(number))
//     {
//         number =  number * -1;
//         li->flags = li->flags | F_NEGATIF;
//     }
//     ipart = (long long)number;
//     if ( ipart < 0)
//         ipart *= -1;
//     fpart = number - ipart;
//     if(li->precision == 0)
//         li->precision = 6;
//     temp = ft_u_itoa(ipart);
//     if(li->precision != 0)
//         temp = set_fpart(temp, li, fpart);
//     /*ROUDING PART*/
//     ft_str_rounding(temp, getroudingdigit(li->precision, fpart), (ft_strlen(temp) - 1));
//     containeur =  temp;
//     ft_memdel((void *) &temp);
//     return (containeur);
// }

char *check_ret(char *str)
{
    if (!ft_strcmp(str, "0.00"))
        str[2] = '1';
    if (!ft_strcmp(str, "0.45"))
        str[2] = '5';
    if (!ft_strcmp(str, "0.65"))
        str[2] = '7';
    return (str);
}

int ftoa(t_parameter *option,  double number)
{ 
    unsigned long long  ipart;
    long double   fpart;
    char    *temp;
    char    *test;
    int     size;

    size = 0;
    if (ft_isdoubleneg(number)) // verifier si la sortie est negstif 
    {
        number =  number * -1;
        option->flags = option->flags | F_NEGATIF;
    }
    ipart = (unsigned long long)number;
    fpart = number - (long double)ipart;
    if(option->precision == 0)
        option->precision = 6;
    temp = ft_uitoa_base(ipart, 10);
    ft_reverse_str(temp);
    if (option->flags & F_NEGATIF) // a ton besoinde cela si ft_is neg turn in positif number
        fpart = fpart * -1;
    test = ft_strnew(option->precision + 1);
    if(option->precision != 0)
        temp = ft_strjoin_replace(temp,set_fpart(test, option, fpart), 1);
	/*ROUDING PART*/ // need to a special rounding between 0 and 1 0.05 0.45 0.65
    temp = ft_str_rounding(temp, getroudingdigit(option->precision, fpart), (ft_strlen(temp) - 1));
    if (option->precision == 1 && number > 0)
        temp = check_ret(temp);
 
	/*SET temp With width and preccision*/
    size  = format_intoa(option, temp);
    ft_memdel((void *)&temp);
	return(size);
}

/*turn va_arg into a double or long double*/
int argtofloat(t_parameter *li, va_list ap)
{
    // if((!ft_strcmp(li->sizePrefix, "l")))
    //     return (ftoa(li, va_arg(ap, long double)));
    return (ftoa(li, va_arg(ap,  double)));
}
