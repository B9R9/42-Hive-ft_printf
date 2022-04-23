/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_dlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:29:30 by briffard          #+#    #+#             */
/*   Updated: 2022/02/03 19:28:47 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

dlist		push_back_dlist(dlist li, int x)
{
	t_dlistnode		*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
	{
		ft_putendl_fd("Error: Dynamic allocation memory.", 2);
		exit(EXIT_FAILURE);
	}
	element->value = x;
	element->next = NULL;
	element->back = NULL;
	if (is_empty_dlist(li))
	{
		li = malloc(sizeof(*li));
		if (li == NULL)
		{
			ft_putendl_fd("Error: Dynamic allocation memory.", 2);
			exit(EXIT_FAILURE);
		}
		li->length = 0;
		li->begin = element;
		li->end = element;
	}
	else
	{
		li->end->next = element;
		element->back = li->end;
		li->end = element;
	}
	li->length++;
	return(li);
}