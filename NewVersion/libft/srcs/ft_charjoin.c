/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:11:06 by briffard          #+#    #+#             */
/*   Updated: 2022/04/01 14:46:43 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_charjoin(char c, char *dest)
{
    char    *temp;
    size_t  i;
    
    i = 0;
    temp =  ft_strjoin(" ", dest);
    if(!temp)
        return (NULL);
    temp[0] = c;
    ft_memdel((void **)&dest);
    dest = temp;
    return (dest);
}