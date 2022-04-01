/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:31:52 by briffard          #+#    #+#             */
/*   Updated: 2022/04/01 15:45:32 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char	*dispacht(va_list ap, t_parameter li)
{
	return (funcFlagsArray[li.conv - 'a'](li, ap));
}

/* Decoupe formart en une liste*/
static t_containeur	*split(const char *str, va_list ap, t_containeur *li)
{
	t_parameter		new;
	size_t			index;
	int				start;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '%')
		{
			new = init(str, index, new, ap);
			start = index;
			li = push_back(li, dispacht(ap, new));
			index += (new.size + 1);
		}
		else
		{
			start = index;
			while (str[index] != '%' && str[index])
				index++;
			li = push_back(li, ft_strsub(str, start, index - start));
		}
	}
	return (li);
}

int	ft_printf(const char *format, ...)
{
	t_containeur	*containeur;
	va_list			ap;
	int				length;

	length = 0;
	containeur = newlist();
	va_start(ap, format);
	containeur = split(format, ap, containeur);
	va_end(ap);
	while (containeur != NULL)
	{
		ft_putstr(containeur->box);
		length += ft_strlen(containeur->box);
		containeur = containeur->next;
	}
	return (length);
}
