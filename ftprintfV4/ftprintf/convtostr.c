/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convtostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:13:13 by briffard          #+#    #+#             */
/*   Updated: 2022/03/22 08:58:23 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char		*strtoarr(t_parameter li, char *str)
{
	size_t	index;
	size_t	strlenght;
	char	*dest;
	

    // ft_debug("green", "converttostr", 01, str, -1);
	strlenght =  ft_strlen(str);
	if(!str)// what happend if str == NULL
		return(ft_strdup("NULL"));
	dest = ft_strnew(strlenght);
	if (!dest)
	{
		ft_errormem("convtostr.c", 22);
		exit(EXIT_FAILURE);
	}
	index = 0;
	
	/*imprime str suivant les parameter*/
	if (li.precision == 0 || li.precision > strlenght)
		li.precision = strlenght;
	while (index < li.precision)
	{
		dest[index] = str[index];
		index++;
	}
	//ft_memdel((void**)str);
    // ft_debug("green", "converttostr", 02, dest, -1);
	return(dest);
}

char		*argtostr(t_parameter li, va_list ap)
{
	return(strtoarr(li,va_arg(ap, char *)));
}
