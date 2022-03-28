/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:03:31 by briffard          #+#    #+#             */
/*   Updated: 2022/03/28 18:08:07 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char	*ft_reverse_str(char *dest);

static char	*addsigne(char *dest)
{
	int	i;

	i = 0;
	while (dest[i] == ' ')
		i++;
	dest[i] = '+';
	return (dest);
}

static char	*ft_reverse_str(char *dest)
{
	int	x;

	x = 0;
	while (dest[0] == ' ')
	{
		x = 0;
		while (dest[x + 1] != '\0')
		{
			ft_swap(&dest[x], &dest[x + 1]);
			x++;
		}
	}
	return (dest);
}

static char	*inttoarr(t_parameter li, int number)
{
	char	*dest;
	char	*temp;
	size_t	lenght;

	lenght = ft_numlenght(number);
	if (li.precision < lenght)
		li.precision = lenght;
	if (li.precision < li.width)
	{
		li.addspace = li.width - li.precision;
		li.precision = li.width;
	}
	dest = ft_itona(number, li.precision);
	if (li.addspace > 0)
		dest = addspaces(dest, li, li.addspace);
	if (li.positif && number >= 0 && li.width >= (lenght))
		dest = addsigne(dest);
	else if (li.positif && number >= 0 && ft_strlen(dest) == li.precision)
		dest = ft_strjoin("+", dest);
	if (li.negatif)
		dest = ft_reverse_str(dest);
	temp = dest;
	ft_memdel((void **) &dest);
	dest = temp;
	return (dest);
}

char	*argtoint(t_parameter li, va_list ap)
{
    // if(ft_strcmp(li.sizePrefix,"ll"))
    //     return(ll_int_to_arr(li, va_arg(ap, long long int)));
    // else if(ft_strcmp(li.sizePrefix, "l"))
    //     return(l_int_to_arr(li, va_arg(ap, long int)));
    // else if(ft_strcmp(li.sizePrefix, "h"))
    //      return(u_short_int_to_arr(li, va_arg(ap, unsigned short int)));
    // else if(ft_strcmp(li.sizePrefix, "hh"))
    //      return(u_char_to_arr(li, va_arg(ap, unsigned char)));
    // else
	return (inttoarr(li, va_arg(ap, int)));
}
