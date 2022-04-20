/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:01:24 by briffard          #+#    #+#             */
/*   Updated: 2022/04/20 13:46:00 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_intwidth(t_parameter *option, int lenght);
int print_intprecision(int start, t_parameter *option, int lenght);
int format_intoa(t_parameter *option, char *dest);
int print_0x(t_parameter *option);
int adjust_lenght(t_parameter *option, int lenght);

int print_0x(t_parameter *option)
{
    int size;

    size = 0;
    if (option->upper && option->conv == 'x' && option->flags & F_ZERO)
        {
            size += print_str("0X", ft_strlen("0X"));
            option->flags = option->flags ^ F_HASHTAG;
        }
    else if (!option->upper && option->conv == 'x' && option->flags & F_ZERO)
        {
            size += print_str("0x", ft_strlen("0x"));
            option->flags = option->flags ^ F_HASHTAG;
        }
    else if (option->conv == 'o' && option->width <= 1)
        {
            size += print_char('0');
            option->flags = option->flags ^ F_HASHTAG;
        }
    return (size);
}
int print_0x_2(t_parameter *option)
{
    int size;

    size = 0;
    if (option->upper && option->conv == 'x' )
        {
            size += print_str("0X", ft_strlen("0X"));
            option->flags = option->flags ^ F_HASHTAG;
        }
    else if (!option->upper && option->conv == 'x')
        {
            size += print_str("0x", ft_strlen("0x"));
            option->flags = option->flags ^ F_HASHTAG;
        }
    else if (option->conv == 'o' && option->flags & F_HASHTAG)
        {
            size += print_char('0');
            option->flags = option->flags ^ F_HASHTAG;
        }
    return (size);
}

int print_intprecision(int start, t_parameter *option, int lenght)
{
    int size;

    size = 0;
    while (start < (option->precision - lenght) && option->conv != 'f')
    {
        size += print_char('0');
        start++;
    }
    return (size);
}

int adjust_lenght(t_parameter *option, int lenght)
{
    if (option->flags & F_PLUS /*&& !(option->flags & F_ZERO)*/)
        lenght += 1;
    else if (option->flags & F_PLUS && !(option->flags & F_SPACE))
        lenght -= 1;
    else if (option->flags & F_HASHTAG && !(option->flags & F_ZERO))
{        if (option->conv == 'o')
            lenght += 1;
        else
            lenght += 2;}
    if (option->flags == F_SPACE && option->negatif)
        lenght += 1;
    return (lenght);
}

int print_intwidth(t_parameter *option, int lenght)
{
    int size;

    // printf("-->%d", (option->flags & F_SPACE));
    // printf("-->%d", (option->flags & F_PLUS));
    size = 0;
    if ((option->negatif && option->flags & F_ZERO) || \
    (option->negatif && option->flags & F_SPACE && option->width == 1))
        size += print_char('-');
    if ((option->flags & F_PLUS && option->flags & F_ZERO) ||\
     (option->flags & F_PLUS && option->width == 1) ||\
     (option->flags == F_PLUS && !option->negatif))
        size += print_char('+');
    lenght = adjust_lenght(option, lenght);
    if (option->flags & F_HASHTAG && option->flags & F_ZERO)
        size += print_0x(option);
    // if (option->width <= option->precision)
    //         option->width = option->precision;
    // printf("W %d || P %d || L %d\n", option->width, option->precision, lenght);
    while (size < (option->width - lenght))
    {
        if (option->flags & F_ZERO)
            size += print_char('0');
        else
            size += print_char(' ');
    }
    if (option->flags & F_PLUS && !(option->flags & F_ZERO) && \
        (option->flags & F_HASHTAG))
        size += print_char('+');
    if (option->negatif && !(option->flags & F_ZERO))
        size += print_char('-');
    if (option->flags & F_HASHTAG && !(option->flags & F_ZERO))
        size += print_0x(option);
    return (size);
}

int  print_sign(t_parameter *option)
{
    int size;

    size = 0;
    if (option->negatif && (option->flags & F_ZERO || option->part_1 == 0))
    {
        size += print_char('-');
        option->negatif = false;
        // if (option->flags & F_PLUS)
        // printf("\nVALUE (-) -->%d<--\n",option->flags);
        // option->flags = option->flags ^ F_PLUS;
    }
    else if(option->flags & F_PLUS && (option->flags & F_ZERO || option->part_1== 0))
    {
        size += print_char('+');
        // option->negatif = false;
        option->flags = option->flags ^ F_PLUS;
    }
    else if (option->width > option->precision || (option->flags & F_SPACE))
    {
        if (option->flags & F_ZERO)
            size += print_char('0');
        else
            size += print_char(' ');
    }

    return (size);
}

int print_sign_2(t_parameter *option)
{
    int size;

    size = 0;
    if ((option->negatif > 0) || (option->flags & F_PLUS) > 0)
    {
        if (option->negatif)
            size += print_char('-');
        else if (option->flags & F_PLUS)
            size += print_char('+');
    }
    return (size);
}

int print_part_1(t_parameter *option, int lenght)
{
    int size;

    size = 0;
    lenght = adjust_lenght(option, lenght);
    if((option->negatif || option->flags & F_PLUS || option->flags & F_SPACE) && option->conv != 'o')
        size += print_sign(option);
    // if (option->conv == 'o')
    //     size += print_char('0');
    if (option->flags & F_HASHTAG)
        size += print_0x(option);
    while (size < (option->width - lenght))
    {
        if (option->flags & F_ZERO)
            size += print_char('0');
        else
            size += print_char(' ');
    }
    size += print_sign_2(option);
    if (option->flags & F_HASHTAG)
        size += print_0x_2(option);
    return (size);
}

void    define_part_1(t_parameter *option, char *dest)
{
    if ((!option->precision || option->precision < (int)ft_strlen(dest)) && option->conv != 'f')
        option->precision = ft_strlen(dest);
    option->part_1 = option->width - option->precision;
    if (option->part_1 <= 0)
        option->part_1 = 0;
    if (option->precision > (int)ft_strlen(dest))
        option->flags = option->flags ^ F_ZERO;
}




int format_intoa(t_parameter *option, char *dest)
{
    int size;

    size = 0;
    define_part_1(option, dest); // Not USE
    if ((!option->precision || option->precision < (int)ft_strlen(dest)) && option->conv != 'f')
        option->precision = ft_strlen(dest);
    if (option->flags & F_MINUS)
        return (align(dest, option));
    size += print_part_1(option, option->precision);
    size += print_intprecision(0,option, (int)ft_strlen(dest));
    size += print_str(dest, (int)ft_strlen(dest));


    // if ((option->flags & F_SPACE) && option->width == 1 )
    //     option->width = (int)ft_strlen(dest) + 1;
    // if (option->flags & F_MINUS)
    //     return (align(dest, option));
    // if (option->conv == 'f')
    //     option->precision = ft_strlen(dest);
    // // size += print_intwidth(option, option->precision);
    // size += print_intprecision(0, option, (int)ft_strlen(dest));
    // size += print_str(dest, (int)ft_strlen(dest));
    return (size);
}

















// void    format_precision(char *str, t_parameter li)
// {
//     while((int)ft_strlen(str) <= li.width)
//         str = ft_strjoin_replace("0", str, 1);
// }

// void    format_width(char *str, t_parameter li)
// {
//     int     i;
//     int     x = 0;
//     i = li.precision;
//     if (li.flags & F_PLUS)
//     {
//         if((int)ft_strlen(str) == li.width)
//             str[0] = '+';
//         else
//             str = ft_strjoin_replace("+", str, 1);
//     }
//     while(i < li.width )
//         {
//             str[x] = ' ';
//             i++;
//             x++;
//         }
// }
// char    *parse_int(t_parameter li, char *source)
// {
//     char    *tmp;

//     if(!li.precision)
//         li.precision = ft_strlen(source);
//     tmp = ft_strnew(ft_abs_int(li.width - li.precsion));
//     format_precision(source,li);
//     format_width(source,li);
    // while(((int)ft_strlen(source) < li.precision && (int)ft_strlen(source) < li.width)
    // || (int)ft_strlen(source) < li.width)
    //         source = ft_strjoin_replace("0", source);
    // if (li.width >= li.precision)
    // {
    //     if(li.flags & F_PLUS)
    //     {
    //         if((int)ft_strlen(source) == li.width)
    //             source[0] = '+';
    //         else
    //             source = ft_strjoin_replace("+", source, 1);
    //     }
    // }
//     if (li.flags & F_SPACE && (int)ft_strlen(source) > li.width)
//         source = ft_strjoin_replace(" ", source, 1);
//     if (li.flags & F_MINUS)
//     {
//         if(li.flags & F_SPACE)
//             align_right(&source[1]);
//         else
//             align_right(source);
//     }
//     return (source);
// }
