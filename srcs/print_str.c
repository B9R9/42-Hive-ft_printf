/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:29:25 by briffard          #+#    #+#             */
/*   Updated: 2022/04/26 09:24:50 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_width(t_parameter *option, int lenght);
int	print_str(const char *str, int lenght);
int	print_char(char c);
int	align_right(int start, int lenght);

int	align_right(int start, int lenght)
{
	int	size;

	size = 0;
	while (start < lenght)
	{
		size += print_char(' ');
		start++;
	}
	return (size);
}

/*
**print a char to stdout
*/
int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/*
**print a char* until pre
*/
int	print_str(const char *str, int lenght)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (i < lenght)
	{
		size += print_char(str[i]);
		i++;
	}
	return (size);
}

/*
** print width parameter for flag c & s
*/
int	print_width(t_parameter *option, int lenght)
{
	int	size;

	size = 0;
	while (size < (option->width - lenght) && option->flags ^ F_MINUS)
	{
		if (option->flags & F_ZERO)
			size += print_char('0');
		else
			size += print_char(' ');
	}
	return (size);
}
