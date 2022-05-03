/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:26:18 by briffard          #+#    #+#             */
/*   Updated: 2022/05/03 14:38:33 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_sign(t_parameter *option);
int		print_0x(t_parameter *option, char *str);
int		print_precision(int start, t_parameter *option, char *str);
void	set_length(t_parameter *option, char *str);
int		print_int(t_parameter *option, char *str);

int	print_0x(t_parameter *option, char *str)
{
	int	size;

	size = 0;
	if (option->conv == 'x' || option->conv == 'p')
	{
		if (option->upper)
			size += print_str("0X", ft_strlen("0X"));
		else
			size += print_str("0x", ft_strlen("0x"));
		option->flags = option->flags ^ F_HASHTAG;
	}
	else if (option->conv == 'o' && \
	option->pre <= (int)ft_numlength(ft_atoi(str)))
	{
		size += print_char('0');
		option->flags = option->flags ^ F_HASHTAG;
	}
	return (size);
}

int	print_sign(t_parameter *option)
{
	int	size;

	size = 0;
	if (option->flags & F_NEGATIF)
	{
		size += print_char('-');
		// option->flags = option->flags ^ F_NEGATIF;
	}
	else if (option->flags & F_PLUS)
	{
		size += print_char ('+');
		// option->flags = option->flags ^ F_PLUS;
	}
	return (size);
}

int	print_precision(int start, t_parameter *option, char *str)
{
	int	size;

	size = 0;
	// if (option->flags & F_NEGATIF)
	// 	size += print_sign(option);
	while (start < (option->pre - (int)ft_strlen(str))  && option->conv != 'f')
	{
		size += print_char('0');
		start++;
	}
	return (size);
}
/*
void	set_length(t_parameter *option, char *str)
{
	int	to_remove;

	to_remove = 0;
	if (option->pre < (int)ft_strlen(str) && option->conv != 'f')
		option->pre = (int)ft_strlen(str);
	if ((option->flags & F_HASHTAG && option->conv != 'o') || \
	(option->conv == 'o' && option->pre <= (int)ft_numlength(ft_atoi(str))))
		to_remove += add_character_f_hashtag(option->conv);
	if ((option->flags & F_NEGATIF || option->flags & F_PLUS) && \
	option->width >= option->pre)
		to_remove += 1;
	if (option->flags & F_ZERO && (option->conv != 'f') && \
	option->pre >= (int)ft_strlen(str))
		option->flags = option->flags ^ F_ZERO;
	adjust_length(option, str, to_remove);
}
*/

void	adjust_flags(t_parameter *option, char *str)
{
	(void)str;
	if (option->flags & F_ZERO && (option->conv != 'f') && \
	option->pre > 0)
		option->flags = option->flags ^ F_ZERO;
	
}

void	set_length(t_parameter *option, char *str)
{
	int	to_remove;

	to_remove = 0;
	if ((option->flags & F_HASHTAG && option->conv != 'o') || \
	(option->conv == 'o' && option->pre <= (int)ft_numlength(ft_atoi(str))))
		to_remove += add_character_f_hashtag(option->conv);
	if ((option->flags & F_NEGATIF || option->flags & F_PLUS) && \
	option->width >= option->pre)
		to_remove += 1;
	if (option->pre > option->width && option->conv != 'f')
		option->width = 0;
		
	option->length = (option->width - to_remove) - option->pre;
	if (option->length < 0)
		option->length = 0;
}

void	set_precision(t_parameter *option, char *str)
{
	// printf("\nPRE->%d<-\n", option->pre);
	if (option->pre < (int)ft_strlen(str) && option->conv != 'f')
		option->pre = (int)ft_strlen(str);
	if (option->conv == 'f' && option->pre > 0)
	{
		if (ft_numlength(ft_atoi(str)))
			option->pre += (int)ft_numlength(ft_atoi(str)) + 1;
		else 
			option->pre += 2;
	}
	if (option->conv == 'f' && option->pre == 0)
	{
		if (ft_numlength(ft_atoi(str)) == 0)
			option->pre += 1;
		else
			option->pre += (int)ft_numlength(ft_atoi(str));
	}
	// printf("\nPRE->%d<-\n", option->pre);
	
}


int	print_int(t_parameter *option, char *str)
{
	int	size;

	size = 0;
	adjust_flags(option, str);
	set_precision(option, str);
	set_length(option, str);
	// printf("\nLENGTH->%d<-\n", option->length);
	// printf("\nWIDTH->%d<-\n",option->width);
	// printf("\nFLAS->%d<-\n",option->flags & F_ZERO);
	if (option->flags & F_MINUS)
		return (align(str, option));
	// if ((option->flags & F_SPACE && !(option->flags & F_ZERO)) || \
	// (!(option->flags & F_SPACE) && !(option->flags & F_ZERO) && \
	// option->width > 0))
	// 	size += set_space(option, str);
	// else
	// 	size += set_zero(option, str);
	if(option->flags & F_SPACE && option->width == 0 && !(option->flags & F_NEGATIF))
	{
		size += print_char(' ');
		option->length -= 1;
	}
	if (option->flags & F_ZERO)
		size += set_zero(option, str);
	else
		size += set_space(option, str);
	size += print_precision(0, option, str);
	if (!str)
		size += print_char('0');
	else
		size += print_str(str, (int)ft_strlen(str));
	return (size);
}
