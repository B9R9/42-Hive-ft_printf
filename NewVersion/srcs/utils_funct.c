/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:16:48 by briffard          #+#    #+#             */
/*   Updated: 2022/04/22 15:52:29 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	skip(char *str);
t_bool	isnot_sizePrefix(char *str);
int	define_base(t_parameter *option);
int align(char *str, t_parameter *option);
t_bool	isnot_precision(int c);


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
	return (size);
}

t_bool	isnot_sizePrefix(char *str)// return 0 si c est sieprefix 1 si cest diffetem
{
	int	i;

	i = 0;
 	if (str[0] != 'l' || str[0] != 'h' || str[0] != 'L' || str[0] != 'z')
		return (true);
	if (str[0] == 'l' || str[0] == 'h')
	{
		if (str[0] == str[1] && str[1] != 'l' && str[1] != 'h')
			return (true);
		if (str[0] == str[1])
	}

}
t_bool	isnot_precision(int c)
{
	if(c == '.')
		return (false);
	if(c == '*')
		return (false);
	return (true);
}