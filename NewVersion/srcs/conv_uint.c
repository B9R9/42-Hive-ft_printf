/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:05:21 by briffard          #+#    #+#             */
/*   Updated: 2022/04/20 14:17:51 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int format_uint(t_parameter *option, unsigned int number);
int	u_ll_itoa(t_parameter *option, unsigned long long int number);

int	u_ll_itoa(t_parameter *option, unsigned long long int number)
{
	char	*temp;
	int		size;

	size = 0;
	if (number == 0)
    {
        if (option->dot)
            return (format_char(option,' '));
        return (format_char(option,'0'));
    }
	temp = ft_uitoa_base(number, define_base(option));
	if (!temp)
		exit(EXIT_FAILURE);
	if (option->upper)
		ft_strtoupper(temp);
	size += print_int(option, temp);
    ft_memdel((void **)&temp);
	return (size);
}

int format_uint(t_parameter *option, unsigned int number)
{
	char	*str;
	int		size;

	size = 0;

    if (number == 0)
    {
        if (option->dot)
            return (format_char(option,' '));
        return (format_char(option,'0'));
    }
	str = ft_uitoa_base(number, define_base(option));
	if (!str)
		exit(EXIT_FAILURE);
    if (option->upper)
		ft_strtoupper(str);
	size += print_int(option, str);
    ft_memdel((void **)&str);
	return(size);
}

int conv_to_uint(t_parameter *option, va_list ap)
{
	if(!ft_strcmp(option->sizePrefix,"ll"))
        return(	u_ll_itoa(option, va_arg(ap, unsigned long long)));
    else if(!ft_strcmp(option->sizePrefix, "l"))
        return(u_ll_itoa(option, va_arg(ap, unsigned long)));
    else if(!ft_strcmp(option->sizePrefix, "h"))
        return(u_ll_itoa(option, (unsigned short)va_arg(ap, int)));
    else if(!ft_strcmp(option->sizePrefix, "hh"))
        return(u_ll_itoa(option, (unsigned char)va_arg(ap, int)));
    else
    	return (format_uint(option, va_arg(ap, unsigned int)));
}
