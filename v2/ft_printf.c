/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:12:38 by briffard          #+#    #+#             */
/*   Updated: 2022/03/15 12:27:02 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
/*
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
*/
static char	*ft_strdup(char *str)
{
	size_t	index;
	char	*dest;

	index = 0;
	dest = (char *)malloc((sizeof(char) * ft_strlen(str)) + 1);
	if (!dest)
	{
		error("In ft_printf.c: line 49\nerror: Allocation memory\n");
		exit(EXIT_FAILURE);
	}
	while (str[index] != '\0')
	{
		dest[index] = str[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_charjoinstr(char **str, char c)
{
	size_t		index;
	char		*dest;
	size_t		size;
	

	printf("TEST05\n");
	if(!str)
		return (NULL);
	index = 0;
	printf("TEST06\n");
	if (ft_strlen(*str) == 0)
		size = 1;
	else
		size = ft_strlen(*str);
	printf("TEST05\n");
	dest =(char *)malloc(sizeof(char) * size + 1);
	printf("TEST06\n");
/*	if (dest == NULL)
	{
		printf("TEST06.1\n");
		error("in ft_printf.c: line: 49\nerror: Allocation memory\n");
		exit(EXIT_FAILURE);
	}*/
	printf("TEST07\n");
	while (*str[index] != '\0')
	{
		printf("TEST08\n");
		dest[index] = *str[index];
		index++;
	}
	dest[index] = c;
	dest[index + 1] = '\0';
	printf("DEST = %s\n", dest);
	return (dest);
}	

int		ft_printf(const char *format, ...)
{
	t_parameter		parameter;
	va_list			ap;
	char			**containeur;
	size_t			index;
	size_t			box;

	index = 0;
	box = 0;
	va_start(ap, format);
	containeur = newstrsplit(format);
	printf("TEST00\n");
	while (format[index] != '\0')
	{
		printf("TEST01\n");
		if (format[index] == '%')
		{
			printf("TEST02\n");
			parameter = init(format, index, parameter);
			box++;
			containeur[box] = ft_strdup(dispachtflags(parameter, ap));
			index += parameter.size;
			box++;
		}
		else
		{
			printf("TEST04\n");
			containeur[box] = ft_charjoinstr(&containeur[box], format[index]);
		}
		printf("%s\n", containeur[box]);
		index++;
		printf("TEST03\n");
	}
	va_end(ap);
	printf("TEST\n");
	return (printbox(containeur));
}