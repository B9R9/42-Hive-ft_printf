/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setuprecision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:33:44 by briffard          #+#    #+#             */
/*   Updated: 2022/03/03 14:56:48 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

t_parameter		setupdot(t_parameter li, char *str)
{
	printf("Valeur de STR in SETUP DOT = %s\n", str);
	li.dot = true;
	li.dotlenght = ft_atoi(&str[1]);
	return (li);
}

/*le 1er rgument de la list ap renvoie la widht */
t_parameter		setupstar(t_parameter li, char *str)
{
	(void)str;
	li.star = true;
	return(li);
}