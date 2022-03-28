/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_Flag_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:47:35 by briffard          #+#    #+#             */
/*   Updated: 2022/03/28 16:14:37 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

t_parameter handle_flag(char *str, t_parameter li)
{
    int i;

    i = 0;
    while (str[i] == '#' || str[i] == '0' || str[i] == '+' || str[i] == '-' || str[i] == ' ')
	{
		if (str[i] == '#')
			li.hastag = true;
		else if (str[i] == '+')
			li.positif = true;
		else if (str[i] == '-')
			li.negatif = true;
		else if (str[i] == ' ')
			li.space = true;
		else if (str[i] == '0')
			li.zero = true;
		i++;
	}
    li.char_to_skip = i;
    return (li);
}

t_parameter     handle_width(char *str, t_parameter li, va_list ap)
{
    if (str[0] == '*')
    {
        li.width = va_arg(ap, int);
        li.char_to_skip += 1;
        /*What happend if width is negatif ???*/
    }
    else
    {
        li.width = ft_atoi(str);
        li.char_to_skip += skip(str);
    }
    return (li);
}

t_parameter     handle_precision(char *str, t_parameter li, va_list ap)
{
    printf("->str %s<-\n",str);
    if (str[0] == '.')
    {
        li.dot = true;
        if (str[1] == '*')
            {
            li.precision = va_arg(ap ,int);
            li.char_to_skip += 2;
        }
        else
        {
            li.precision = ft_atoi(&str[1]);
            li.char_to_skip += skip(&str[1]) + 1;
        }
    }
    return (li);
}

t_parameter handle_size_prefix(char *str, t_parameter li)
{
    int i;
    
    i = 0;
    if (str[0] == 'l' || str[0] == 'h' || str[0] == 'L')
    {
        while (str[i] == str[i + 1])
            i++;
        i++;
        li.sizePrefix = ft_strsub(str, 0, (i - 0) + 1);
        li.char_to_skip += i;
    }
    return (li);
}
