/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupoption.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:28:01 by briffard          #+#    #+#             */
/*   Updated: 2022/03/03 14:17:43 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

t_parameter		setupspace(t_parameter li, char *str)
{
	li.space = true;
	li.spacelenght = ft_atoi(str);
	li.size = 0;
	li.contentsize = 0;
	return (li);
}

t_parameter		setupzero(t_parameter li, char *str)
{
	li.zero = true;
	li.zerolenght = ft_atoi(str);
	return (li);
}

t_parameter		setuphastag(t_parameter li, char *str)
{
	(void)str;
	li.hastag = true;
	return (li);
}

t_parameter		setupnum(t_parameter li, char *str)
{
	li.space = true;
	li.spacelenght = ft_atoi(str);
	return (li);
}

t_parameter		setupsigned(t_parameter li, char *str)
{
	(void)str;
	li.signe = true;
	return (li);
}
/* check le 1er str[0] retour ser une option
 * derriere regarder les nombre et les attribuer a la lenght 
 * puis recommencer a l index
 * */ 
