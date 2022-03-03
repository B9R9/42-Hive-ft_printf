/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:12:38 by briffard          #+#    #+#             */
/*   Updated: 2022/03/03 14:33:10 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	ft_printf(const char *format, ...)
{
	int				i;
	int				lenght;
	t_parameter 	parameter;
	va_list			ap;

	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			parameter = init(format, i, parameter);
			lenght += dispachtflag(parameter, ap);
			i++;
		}
		else
		{
			i++;
		}
	}
	va_end(ap);
	return (0); // retourne la taiile de la str imprimer
}