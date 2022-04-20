/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:53:13 by briffard          #+#    #+#             */
/*   Updated: 2022/04/20 14:07:23 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_parameter	*checkoptionerror(t_parameter *options)
{
	if (options->flags & F_ZERO && options->flags & F_MINUS)
		options->flags = options->flags ^ F_ZERO;
	if (options->flags & F_SPACE && options->flags & F_PLUS)
		options->flags = options->flags ^ F_SPACE;
	if (options->flags & F_SPACE && \
		(options->conv != 'd' && options->conv != 'i' && \
		options->conv != 'f'))
		options->flags = options->flags ^ F_SPACE;
	return (options);
}
