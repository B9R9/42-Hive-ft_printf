/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:53:13 by briffard          #+#    #+#             */
/*   Updated: 2022/04/01 15:48:27 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

t_parameter		checkoptionerror(t_parameter li)
{
	if (li.flags & F_ZERO && li.flags & F_MINUS)
		li.flags = li.flags ^ F_ZERO;
	if (li.flags & F_SPACE && li.flags & F_PLUS)
		li.flags = li.flags ^ F_SPACE;
	if (li.flags & F_SPACE && \
		(li.conv != 'd' && li.conv != 'i' && \
		li.conv != 'f'))
		li.flags = li.flags ^ F_SPACE;
	return (li);
}

