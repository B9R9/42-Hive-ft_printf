/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:31:52 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 15:43:45 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"


/*Dispacht table to converrsion flags*/
static char	*dispacht(va_list ap, t_parameter li)
{
	return (funcFlagsArray[li.conv - 'a'](li, ap));
}

/* Split format in strs  in a chained list*/
static t_containeur	*split(const char *str, va_list ap, t_containeur *li)
{
	
	t_parameter		new;
	char			*temp;
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
			temp = ft_strsub(str, start, index - start);
			li = push_back(li,temp);
			ft_strdel(&temp);
		}	
		ft_memdel((void *)&new.sizePrefix);
		//ft_memdel((void **) &new);  error for object 0xa00000000: pointer being freed was not allocated
	}
	return (li);
}

int	ft_printf(const char *format, ...)
{
	t_containeur	*containeur;
	t_containeur	*temp;
	va_list			ap;
	int				length;

	
	length = 0;
	containeur = newlist();
	va_start(ap, format);
	containeur = split(format, ap, containeur);
	va_end(ap);
	temp =  containeur;
	while (temp != NULL) // Peut etre l objet dune fucntion
	{
		ft_putstr(temp->box);
		length += ft_strlen(temp->box);
		//ft_strdel(&temp->box);
		temp = temp->next;
	}
	//ft_strdel(&temp->box);
	//free(containeur);
	// free(containeur);
	//containeur  = NULL;
	return (length);
}
