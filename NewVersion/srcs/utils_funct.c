/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:16:48 by briffard          #+#    #+#             */
/*   Updated: 2022/04/20 11:47:57 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	skip(char *str);
int	define_base(t_parameter *option);
// int	print_width(t_parameter *option, int lenght);

int	define_base(t_parameter *option)
{
	if (option->conv == 'x' || option->conv == 'X' || option->conv == 'p')
		return (16);
	if (option->conv == 'o')
		return (8);
	return (10);
}

int	skip(char *str)
{
	int		index = 0;
	while (str[index] >= '0' && str[index] <= '9')
		index++;
	return index;
}

int align(char *str, t_parameter *option)
{
    int size;

    size = 0;
	if ( option->flags & F_SPACE && (!(option->flags & F_NEGATIF) && !(option->flags & F_PLUS)))
		size += print_char(' ');
	if (option->flags & F_HASHTAG)
		size += print_0x(option);
	if (option->flags & F_PLUS || option->flags & F_NEGATIF)
		size += print_sign(option);
	size += print_precision(0, option, (int)ft_strlen(str));
	size += print_str(str, (int)ft_strlen(str));
	while (size < option->width)
		size += print_char(' ');
	// // lenght = adjust_lenght(option, option->precision);
	// // if (option->flags & F_SPACE)
	// // 	size += print_char(' ');
	// if((option->negatif || option->flags & F_PLUS) && option->conv != 'o')
	// 	size += print_sign_2(option);
	// // if (option->conv == 'o')
    // //     size += print_char('0');
    // if (option->flags & F_HASHTAG)
    //     {size += print_0x(option);}
	// size += print_intprecision(0,option, (int)ft_strlen(str));
    // size += print_str(str, (int)ft_strlen(str));
	// while (size < option->width )
	// 	size += print_char(' ');
	return (size);
}





// int align(char *str, t_parameter *option)
// {
//     int size;

//     size = 0;
//     if (option->flags & F_SPACE)
//     {
//         size += print_char(' ');
//         size += print_str(str, (int)ft_strlen(str));
//         while ( size < option->width)
//             size += print_char(' ');
//         return (size);
//     }
//     else if (option->width <= option->precision)
//     {
//         while (size < (option->precision - (int)ft_strlen(str)))
//             size += print_char('0');
//     }
//     if (option->flags & F_HASHTAG)
//         size += print_0x(option);
// 	if (option->flags & F_ZERO)
// 	{
// 		while ()
// 	}
//     size += print_str(str, (int)ft_strlen(str));
//     while (size < option->width)
//         size += print_char(' ');
//     return (size);
// }
