/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_Flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:47:35 by briffard          #+#    #+#             */
/*   Updated: 2022/04/22 15:42:12 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_uchar get_flag(char c);

static t_uchar get_flag(char c)
{
    if (c == '#')
		return (F_HASHTAG);
	else if (c == '+')
		return(F_PLUS);
	else if (c == '-')
		return (F_MINUS);
	else if (c == '0')
		return (F_ZERO);
    else
        return (F_SPACE);
}

t_parameter *handle_flag(char *str, t_parameter *li)
{
    int i;

    li->flags = 0x00;
    i = 0;
    while (str[i] == '#' || str[i] == '0' || str[i] == '+' || str[i] == '-' \
    || str[i] == ' ')
	{
        li->flags = li->flags | get_flag(str[i]);
		i++;
	}
    li->char_to_skip = i;
    return (li);
}

t_parameter     *handle_width(char *str, t_parameter *li, va_list ap)
{
    if (str[0] == '*')
    {
        li->width = va_arg(ap, int);
        li->char_to_skip += 1;
        /*What happend if width is negatif ???
        D apres la doc width  doit un entier non negatif
        a verifier avec printf*/
    }
    else
    {
        li->width = ft_atoi(str);
        // if(!li->width && isnot_precision(str[0]) && checkparams(str[0]) && isnot_sizePrefix(str))
        if(!li->width && isnot_precision(str[0]) && checkparams(str[0]))
            li->error = true;
        li->char_to_skip += skip(str);
    }
    return (li);
}

t_parameter     *handle_precision(char *str, t_parameter *li, va_list ap)
{
    if (str[0] == '.')
    {
        li->dot = true;
        if (str[1] == '*')
        {
            li->precision = va_arg(ap ,int);
            li->char_to_skip += 2;
        }
        else
        {
            li->precision = ft_atoi(&str[1]);
            // if(!li->precision && checkparams(str[1]))
            //     li->error = true;
            li->char_to_skip += skip(&str[1]) + 1;
        }
    }
    // else if (str[0] != '.' && checkparams(str[0]))
    //     li->error = true;
    return (li);
}

t_parameter *handle_size_prefix(char *str, t_parameter *li)
{
    int     i;

    i = 0;
    ft_bzero(li->sizePrefix, 5);
    if (str[0] == 'l' || str[0] == 'h' || str[0] == 'L' || str[0] == 'z') //inclure une error en cas de LL ou ZZ
    {
        li->sizePrefix[i] = str[i];
        i += 1;
        while (str[i - 1] == str[i] && i < 2)
        {
            li->sizePrefix[i] = str[i];
            i++;
        }
        // if (checkparams(str[i]))
        //     li->error = true;
        li->sizePrefix[i] = '\0';
        li->char_to_skip += ft_strlen(li->sizePrefix);
        li->flags = li->flags | F_MOD;
    }
    return (li);
}
