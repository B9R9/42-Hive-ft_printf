/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispachtflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:31:19 by briffard          #+#    #+#             */
/*   Updated: 2022/03/15 13:55:39 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"


char		*argtostr(t_parameter li, va_list ap)
{
	return(turnto(li,va_arg(ap, char *)));
}

char		*dispachtflags(t_parameter li,va_list  ap)
{
	int		i;
	
	i = 0;
	while(flags[i] != '\0')
	{
		if (li.flag == flags[i])
			 return(funcFlagsArray[i](li, ap));
	}
	error("In dispachtflag.c: line 29\nerror: No flag function found\n");
	exit(EXIT_FAILURE);
}