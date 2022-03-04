/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:12:38 by briffard          #+#    #+#             */
/*   Updated: 2022/03/04 16:49:32 by briffard         ###   ########.fr       */
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
	lenght = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			parameter = init(format, i, parameter);
			lenght += dispachtflags(parameter, ap);

			i += parameter.size;
			//i++;
		}
		else
			lenght += printchar(format[i]);
		i++;
	}
	va_end(ap);
	return (lenght); // retourne la taiile de la str imprimer
}