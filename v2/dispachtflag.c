/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispachtflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:31:19 by briffard          #+#    #+#             */
/*   Updated: 2022/03/04 16:39:11 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"


int		argtostr(t_parameter li, va_list ap)
{
	return(print(li,va_arg(ap, char *)));
}

int		dispachtflags(t_parameter li,va_list  ap)
{
	int		i;
	int test;
	i = 0;
	while(flags[i] != '\0')
	{
		if (li.flag == flags[i])
		{
			test = funcFlagsArray[i](li, ap);
			return (test);
		}
	}
	return(0);
}