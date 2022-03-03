/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispachtflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:31:19 by briffard          #+#    #+#             */
/*   Updated: 2022/03/03 14:56:32 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int		dispachtflag(t_parameter li, va_list  ap)
{
	int		i;

	i = 0;
	while(flags[i] != '\0')
	{
		if (li.flag == flags[i])
		{
			return (funcFlagsArray[i])
		}
	}
	return
}