/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupoption.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:28:01 by briffard          #+#    #+#             */
/*   Updated: 2022/03/02 13:40:50 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

t_parameter		setupspace(t_parameter li, char *str)
{
	li.space = true;
	li.lenght = ft_atoi(str);
	li.optionlenght = ft_strlen(str);
	li.size = 0;
	li.contentsize = 0;
	li.flag = str[li.optionlenght - 1];
	return (li);
}

/* check le 1er str[0] retour ser une option
 * derriere regarder les nombre et les attribuer a la lenght 
 * puis recommencer a l index 
