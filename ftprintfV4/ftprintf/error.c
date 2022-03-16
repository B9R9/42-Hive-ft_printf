/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:53:13 by briffard          #+#    #+#             */
/*   Updated: 2022/03/16 15:18:31 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

t_parameter		optionflag_s(t_parameter li)
{
	if (li.space)
		{
			ft_errormes("error: ' 'flag used with '%s'\n");
			exit(EXIT_FAILURE);
		}
	else if(li.zero)
		{
			ft_errormes("error: '0'flag used with '%s'\n");
			exit(EXIT_FAILURE);
		}
	else if(li.hastag)
		{
			ft_errormes("error: '#'flag used with '%s'\n");
			exit(EXIT_FAILURE);
		}
	else if(li.signe)
		{
			ft_errormes("error: '+'flag used with '%s'\n");
			exit(EXIT_FAILURE);
		}
	else if (li.star && (li.space == false || li.zero == false || \
	 li.dot == false || li.signe == false || li.hastag == false))
		{
			ft_errormes("error: '*'flag used without width or precision\n");
			exit(EXIT_FAILURE);
		}
	return (li);
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
