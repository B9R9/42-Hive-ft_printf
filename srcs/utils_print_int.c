/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:38:24 by briffard          #+#    #+#             */
/*   Updated: 2022/05/02 12:58:40 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_character_f_hashatg(char conv);
int		set_space(t_parameter *option, char *str);
int		set_zero(t_parameter *option, char *str);
void	adjust_lenght(t_parameter *option, char *str, int to_remove);
int		align(char *str, t_parameter *option);

int	add_character_f_hashtag(char conv)
{
	if (conv == 'o')
		return (1);
	else
		return (2);
}

int	set_space(t_parameter *option, char *str)
{
	int	size;

	size = 0;
 	// printf("\nLENGTH-->%d<--\n", option->lenght);
	if (option->lenght == 0)
		size += print_char(' ');
	while (size < option->lenght)
		size += print_char(' ');
	if (option->flags & F_HASHTAG)
		size += print_0x(option, str);
	if (option->flags & F_PLUS || option->flags & F_NEGATIF)
		size += print_sign(option);
	return (size);
}

int	set_zero(t_parameter *option, char *str)
{
	int	size;

	size = 0;
	if (option->flags & F_HASHTAG)
		size += print_0x(option, str);
	if (option->flags & F_PLUS || option->flags & F_NEGATIF)
		size += print_sign(option);
	if (option->flags & F_SPACE && option->lenght >= 1 && !(option->flags & F_NEGATIF))
	{
		size += print_char(' ');
		option->lenght -= 1;
	}
	while (option->lenght > 0)
	{
		size += print_char('0');
		option->lenght -= 1;
	}
	return (size);
}

void	adjust_lenght(t_parameter *option, char *str, int to_remove)
{
	if (option->conv == 'f')
		option->pre += (ft_numlenght(ft_atoi(str)) + 1);
	if (option->pre > option->width && option->conv != 'f')
		option->width = 0;
	else
	{
		option->lenght = (option->width - to_remove) - option->pre;
		if (option->lenght < 0)
			option->lenght = 0;
	}
	if (option->width == 0 && option->pre == (int)ft_strlen(str) && \
	option->flags & F_SPACE && (!(option->flags & F_NEGATIF) && \
	!(option->flags & F_PLUS)))
		option->lenght += 1;
	if (option->conv == 'u' && option->flags & F_HASHTAG && \
	option->width > option->pre)
		option->lenght += 2;
}

int	align(char *str, t_parameter *option)
{
	int	size;

	size = 0;
	if (option->flags & F_SPACE && (!(option->flags & F_NEGATIF) && \
	!(option->flags & F_PLUS)))
		size += print_char(' ');
	if (option->flags & F_HASHTAG)
		size += print_0x(option, str);
	if (option->flags & F_PLUS || option->flags & F_NEGATIF)
		size += print_sign(option);
	size += print_precision(0, option, (int)ft_strlen(str));
	size += print_str(str, (int)ft_strlen(str));
	while (size < option->width)
		size += print_char(' ');
	return (size);
}
