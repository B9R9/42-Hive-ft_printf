/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 08:48:46 by briffard          #+#    #+#             */
/*   Updated: 2022/03/15 10:51:46 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"


/*PRINNT ERROR ON STDERR*/
void	error(const char *str)
{
	write(2, str, ft_strlen(str));
}

/*PRINT CONTAINEUR AND RETURN TOTAL SIZE OF EVERY BOX*/
int		printbox(char **str)
{
	size_t		box;
	size_t		count;

	box = 0;
	count = 0;
	while (str[box])
	{
		count += ft_strlen(str[box]);
		write (1, str[box], ft_strlen(str[box]));
		box++;
	}
	return (count);
}




int		printchar(char c)
{
	write(1, &c, 1);
	return(1);
}

char		*turnto(t_parameter li, char *str)
{
	size_t	index;
	size_t	strlenght;
	char	*dest;

	strlenght =  ft_strlen(str);
	dest = ft_strnew(strlenght);
	if (!dest)
	{
		error("In printf.c: line 54\nerror: Allocation memory\n");
		exit(EXIT_FAILURE);
	}
	index = 0;
	/*cimprime str suivant les parameter*/
	if (li.dotlenght == 0 || li.dotlenght > strlenght)
		li.dotlenght = strlenght;
	while (index < li.dotlenght)
	{
		dest[index] = str[index];
		index++;
	}
	ft_memdel((void**)str);
	return(dest);
}