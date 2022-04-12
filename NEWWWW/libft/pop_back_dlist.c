/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_back_dlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:47:52 by briffard          #+#    #+#             */
/*   Updated: 2022/02/03 18:57:07 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

dlist		pop_back_dlist(dlist li)
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
		return new_dlist();
	}
	temp = li->end;
	li->end = li->end->back;
	li->end->next = NULL;
	temp->next = NULL;
	temp->back = NULL;
	free(temp);
	temp =NULL;
	li->length--;
	return (li);
}