/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_front_dlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:57:22 by briffard          #+#    #+#             */
/*   Updated: 2022/02/03 19:06:16 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

dlist		pop_front_dlist(dlist li)
{
	t_dlistnode		*temp;

	if (is_empty_dlist(li))
	{
		ft_putstr("Nothing to delete\n");
		return new_dlist();
	}
	if (li->begin == li->end)
	{
		free(li);
		li = NULL;
		return(li);
	}
	temp = li->begin;
	li->begin = li->begin->next;
	li->begin->back = NULL;
	temp->next = NULL;
	temp->back = NULL;
	free(temp);
	temp = NULL;
	li->length--;
	return(li);
}