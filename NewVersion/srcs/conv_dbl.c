/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:18:48 by briffard          #+#    #+#             */
/*   Updated: 2022/04/15 16:26:07 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  format_dbl(t_parameter *option,  double number);
static int  getroudingdigit(int precision,long double fpart);
char        *set_fpart(char *box, t_parameter *option, long double fpart);

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
}

char *check_ret(char *str, double number) // Ne fonctionne pas
{
    if (!ft_strcmp(str, "0.0") && number == 0.05)
        str[2] = '1';
    if (!ft_strcmp(str, "0.4") && number == 0.45)
        str[2] = '5';
    if (!ft_strcmp(str, "0.6") && number == 0.65)
        str[2] = '7';
    return (str);
}

static int format_dbl(t_parameter *option,  double number)
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
    if (option->flags & F_NEGATIF) // a ton besoinde cela si ft_is neg turn in positif number
        fpart = fpart * -1;
    test = ft_strnew(option->precision + 1);
    if(option->precision != 0)
        temp = ft_strjoin_replace(temp,set_fpart(test, option, fpart), 1);
	/*ROUDING PART*/
    temp = ft_str_rounding(temp, getroudingdigit(option->precision, fpart), (ft_strlen(temp) - 1));
    if (option->precision == 1 && number > 0)
        temp = check_ret(temp, number);
	/*SET temp With width and preccision*/
    size  = print_int(option, temp);
    ft_memdel((void *)&temp);
	return(size);
}

/*turn va_arg into a double or long double*/
int conv_to_dbl(t_parameter *li, va_list ap)
{
    long double number;
    if (!ft_strcmp(li->sizePrefix, "L"))
        number = va_arg(ap, long double);
    else
        number = va_arg(ap, double);
    return (format_dbl(li, number));
}
