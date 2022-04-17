/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rounding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:00:18 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 15:50:02 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char    *ft_str_rounding(char *number, int fpart, size_t last_index)
{
    if(fpart > 5)
    {
        number[last_index] = number[last_index] + 1;
        while(last_index >= 0)
        {
            if(number[last_index] == ':')
            {
                number[last_index] = '0';
                if(number[last_index - 1] == '.')
                    last_index--;
                if (last_index == 0)
                    number = ft_strjoin("1", number);
                else
                    number[last_index - 1] = number[last_index - 1] + 1;
            }
            if((number[0] == ':' || number[0] == '.') && (int)last_index == 0)
            {
                number[0] = '0';
                number = ft_strjoin("1", number);
            }
            last_index--;
        }
    }
    else if (fpart == 5)
        if ((number[last_index] + '0') % 2 == 1)
            number[last_index] = number[last_index] + 1;
    return(number);
}