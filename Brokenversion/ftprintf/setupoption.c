/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupoption.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:28:01 by briffard          #+#    #+#             */
/*   Updated: 2022/03/21 16:36:17 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
/*si le carractere * est presenet apres le option utilise va_arg int*/


t_parameter		setupspace(t_parameter li, char *str, va_list ap)
{
	li.space = true;
	if(str[1] == '*')
		{
			li.width = va_arg(ap, int);
			li.char_to_skip = 1;
			return li;
		}
	li.width = ft_atoi(str);
	li.char_to_skip = skip(str);	
	return (li);
}

t_parameter		setupzero(t_parameter li, char *str, va_list ap)
{
	(void) ap;
	li.zero = true;
	if(str[1] == '*')
	{
		li.width = va_arg(ap, int);
		li.char_to_skip = 1;
	}
	else
	{
		li.width = ft_atoi(&str[1]);
		li.char_to_skip = skip(&str[1]);
	}	
	return (li);
}

t_parameter		setuphastag(t_parameter li, char *str, va_list ap)
{
	(void)str;
	(void) ap;
	li.hastag = true;
	if(li.flag == 'X')
		li.upper = true;
	else 
		li.upper = false;
	li.char_to_skip = 1;
	return (li);
}

t_parameter		setupnum(t_parameter li, char *str, va_list ap)// when %12d width  == 12
{
	(void) ap;
	li.space = true;
	li.width = ft_atoi(str);
	return (li);
}

t_parameter		setuppositif(t_parameter li, char *str, va_list ap)
{
	(void)str;
	(void)ap;
	li.positif = true; //impact sur la width du containeur 
	li.char_to_skip = 1;
	return (li);
}
/* check le 1er str[0] retour ser une option
 * derriere regarder les nombre et les attribuer a la lenght 
 * puis recommencer a l index
 * */ 
