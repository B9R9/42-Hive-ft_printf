/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:53:13 by briffard          #+#    #+#             */
/*   Updated: 2022/04/19 17:30:49 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_parameter	*checkoptionerror(t_parameter *li)
{
	if (li->flags & F_ZERO && li->flags & F_MINUS)
		li->flags = li->flags ^ F_ZERO;
	if (li->flags & F_SPACE && li->flags & F_PLUS && \
		(li->conv == 'x' || li->conv == 'X'))
		li->flags = li->flags ^ F_SPACE;
	if (li->flags & F_SPACE && \
		(li->conv != 'd' && li->conv != 'i' && \
		li->conv != 'f'))
		li->flags = li->flags ^ F_SPACE;
	if (li->flags & F_PLUS && \
	 (li->conv == 'p' || li->conv == 'x' || li->conv == 'u'))
		li->flags = li->flags ^ F_PLUS;
	if ((li->conv == 'x' || li->conv == 'X') && li->flags & F_HASHTAG && \
		li->flags & F_PLUS)
		li->flags = li->flags ^ F_PLUS;
	if (li->flags & F_HASHTAG && (li->conv == 'u' || li->conv == 'd' || \
	li->conv == 'i' || li->conv == 'f'))
		li->flags = li->flags ^ F_HASHTAG;
	if (li->flags & F_SPACE && li->width == 0)
		li->part_1 = 1;
	// if (li->flags & F_SPACE && li->flags & F_PLUS && (li->conv == 'd' || li->conv == 'i'))
	// 	li->flags = li->flags ^ F_SPACE;
	return (li);
}
