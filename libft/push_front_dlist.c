/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front_dlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:38:18 by briffard          #+#    #+#             */
/*   Updated: 2022/02/03 19:27:08 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

dlist		push_front_dlist(dlist li, int x)
{
	t_dlistnode		*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
	{
		ft_putendl_fd("Error: dynamic allocation memory.", 2);
		exit(EXIT_FAILURE);
	}
	element->value = x;
	element->next = NULL;
	element->back = NULL;
	if(is_empty_dlist(li))
	{
		li = malloc(sizeof(*li));
		if(li == NULL)
		{
			ft_putendl_fd("Error: dynamic allocation memory.", 2);
			exit(EXIT_FAILURE);
		}
		li->length = 0;
		li->begin = element;
		li->end = element;
	}
	else
	{
		li->begin->back = element;
		element->next = li->begin;
		li->begin = element;
	}
	li->length++;
	return(li);

}