/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:01:24 by briffard          #+#    #+#             */
/*   Updated: 2022/04/14 12:25:40 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_intwidth(t_parameter *option, int lenght);
int print_intprecision(int start, t_parameter *option, int lenght);
int format_intoa(t_parameter *option, char *dest);

int print_intprecision(int start, t_parameter *option, int lenght)
{
    int size;
    
    size = 0;
    while (start < (option->precision - lenght))
    {
        size += print_char('0');
        start++;
    }
    return (size);
}

int print_intwidth(t_parameter *option, int lenght)
{
    int size;

    size = 0;
    if (option->flags & F_PLUS && option->flags & F_ZERO)
        size += print_char('+');
    if (option->flags & F_PLUS && !(option->flags & F_ZERO))
            lenght += 1;
    while (size < (option->width - lenght))
    {
        if (option->flags & F_ZERO)
            size += print_char('0');
        else
            size += print_char(' ');
    }
    if (option->flags & F_PLUS && !(option->flags & F_ZERO))
        size += print_char('+');
    return (size);
}

int align(char *str, t_parameter *option)
{
    int size;

    size = 0;
    if (option->flags & F_SPACE)
    {
        size += print_char(' ');
        size += print_str(str, (int)ft_strlen(str));
        while ( size < option->width)
            size += print_char(' ');
        return (size);
    } 
    size += print_str(str, (int)ft_strlen(str));
    while ( size < option->width)
        size += print_char(' ');
    return (size);
}

int format_intoa(t_parameter *option, char *dest)
{
    int size;
    
    if(!option->precision || option->precision < (int)ft_strlen(dest))
        option->precision = ft_strlen(dest);
    size = 0;
    if (option->flags & F_MINUS)
    {
        size+= align(dest, option);
        return (size);
    }
    size += print_intwidth(option, option->precision);
    size += print_intprecision(0, option, (int)ft_strlen(dest));
    size += print_str(dest, (int)ft_strlen(dest));
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
    // while(((int)ft_strlen(source) < li.precision && (int)ft_strlen(source) < li.width) \
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