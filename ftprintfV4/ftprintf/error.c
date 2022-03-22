/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:53:13 by briffard          #+#    #+#             */
/*   Updated: 2022/03/21 10:48:11 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

t_bool	optionflag_c(t_parameter li)
{
	if(li.dot)
		return ft_errormes("Error: precision used with 'c' conversion specifier\n");
	else if(li.positif)
		return ft_errormes("error: '+'flag used with 'c'\n");
	else if(li.zero)
		return ft_errormes("error: '0'flag used with 'c'\n");
	else if (li.space)
		return ft_errormes("error: ' 'flag used with 'c'\n");
	else if(li.hastag)
		return ft_errormes("error: '#'flag used with 'c'\n");
	return (0);
}

t_bool	optionflag_s(t_parameter li)
{
	if (li.space)
			return ft_errormes("error: ' 'flag used with 's'\n");
	else if(li.zero)
			return ft_errormes("error: '0'flag used with 's'\n");
	else if(li.hastag)
			return ft_errormes("error: '#'flag used with 's'\n");
	else if(li.positif)
			return ft_errormes("error: '+'flag used with 's'\n");
	else if (li.star && (li.space == false && li.zero == false && \
	 li.dot == false && li.positif == false && li.hastag == false))
			return ft_errormes("error: '*'flag used without width or precision\n");
	return (0);
}

t_bool		optionflag_d(t_parameter li)
{
	if(li.negatif && li.zero)// li.signe is for add + or - in front of the number TO NOT CONFONDRE WITH OPTION '-'
		return ft_errormes("error: flag '0' is ignored when flag '-' is present\n");
	else if(li.space && li.positif)
		return ft_errormes("error: flag ' ' is ignored when flag '+' is present\n");
	else if (li.hastag)
		return ft_errormes("error: flag '#' results in undefined behavior with 'd' converion specifier\n");
	return (0);
}
t_bool		checkoptionerror(t_parameter li)
{
	int	i;

	i = 0;
	while(flags[i] != '\0')
	{
		if (li.flag == flags[i])
			return (funcErrorArray[i](li));
		i++;
	}
	return (0);
}
