/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:20:04 by briffard          #+#    #+#             */
/*   Updated: 2022/02/03 18:24:58 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int		dlist_first(dlist li)
{
	if (is_empty_dlist(li))
		exit(1);
	return li->begin->value;
}

int		dlist_end(dlist li)
{
	if (is_empty_dlist(li))
		exit(1);
	return li->end->value;
}