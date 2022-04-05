/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:13:13 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 15:45:39 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char		*strtoarr(t_parameter li, char *str)
{
	char	*dest;
	char	*temp;

	if(!str)// what happend if str == NULL
		return(ft_strdup("NULL"));
	if(!li.precision)
        li.precision = ft_strlen(str);
	
	dest = ft_strnew(li.precision);
	if (!dest)
	{
		ft_errormem("conv_str.c", 26);
		exit(EXIT_FAILURE);
	}
	/*imprime str suivant les parameter*/
	dest = parse_str(dest, li, str);
	temp = dest;
	ft_memdel((void*)&dest);
	dest = temp;
	return(dest);
}

char		*argtostr(t_parameter li, va_list ap)
{
	return(strtoarr(li,va_arg(ap, char *)));
}
