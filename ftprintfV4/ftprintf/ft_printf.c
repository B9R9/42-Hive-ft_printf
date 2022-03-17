/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:31:52 by briffard          #+#    #+#             */
/*   Updated: 2022/03/17 13:39:54 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char			*dispacht(va_list ap, t_parameter li)
{
	int index;

	index = 0;
	while(flags[index] != '\0')
	{
		//printf("VALEUR DU FLAG = %c\n", li.flag);
		if(li.flag == flags[index])
		{
			ft_debug("yellow", "DISPACHT", 01, "NULL", -1);
			return(funcFlagsArray[index](li, ap));
			//ft_debug("yellow", "DISPACHT", 02,funcFlagsArray[index](li, ap), -1);
			//return ("OK");
		}
		index++;
	}
	exit(EXIT_FAILURE);
	/*error message no flag fiunction found*/
}
/*
static int		moveindex(const char *str, int index)
{
	int	x;

	while (str[index] != '\0')
	{
		x = 0;
		while (flags[x] != '\0')
		{
			if (str[index] == flags[x])
				return(index + 1);
			x++;
		}
		index++;
	}
	return an error in case there is no flags at the end 
	}
*/

/* Decoupe formart en une liste*/
static t_containeur	*split(const char *str, va_list ap, t_containeur *li)
{
	t_parameter		new;
	size_t	index;
	int		start;
	
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '%')
		{
			ft_debug("red", "SPLIT", 00,"NULL", index );
			new = init(str, index, new, ap);
			//printf("%c\n", new.flag);
			start = index;
			ft_debug("red", "SPLIT", 03,"NULL", index );
			
			li = push_back(li, dispacht(ap, new));
			index += (new.size + 1); // Function move index do the same
			//printf("%c\n", str[index]);
			ft_debug("red", "SPLIT", 02,li->box, index );
		}
		else
		{
			//printf("%zu\n", index);
			start = index;
			while (str[index] != '%' && str[index])
				index++;
			//printf("%zu\n", index);
			ft_debug("red", "SPLIT", 03,ft_strsub(str, start, (index - start)), index );
			li = push_back(li, ft_strsub(str, start, index - start));	
			//ft_debug("red", "SPLIT", 03,li->box, index );
		}
	}
	return(li);
}

int		ft_printf(const char *format, ...)
{
	t_containeur	*containeur;
	va_list			ap;
	int length;

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
		// ft_putstr(containeur->box);
		// length += ft_strlen(containeur->box);
	return (length);
}
