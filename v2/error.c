/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:53:13 by briffard          #+#    #+#             */
/*   Updated: 2022/03/04 17:25:09 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

t_parameter		optionflag_s(t_parameter li)
{
	if (li.space)
		error("error: ' 'flag used with '%s'\n");
	else if(li.zero)
		error("error: '0'flag used with '%s'\n");
	else if(li.hastag)
		error("error: '#'flag used with '%s'\n");
	else if(li.signe)
		error("error: '+'flag used with '%s'\n");
	exit(EXIT_FAILURE);

}


t_parameter		checkoptionerror(t_parameter li)
{
	int	i;

	i = 0;
	while(flags[i] != '\0')
	{
		if (li.flag == flags[i])
			li = funcErrorArray[i](li);
		i++;
	}
	return (li);
}
