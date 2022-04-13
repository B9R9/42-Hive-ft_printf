/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:59:19 by briffard          #+#    #+#             */
/*   Updated: 2022/04/13 12:09:22 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_containeur 	*newlist(void)
{
	return(NULL);
}

t_bool	is_empty(t_containeur *li)
{
	if(li == NULL)
		return true;
	return false;
}

t_containeur	*push_back(t_containeur *li, char *str)
{
	t_containeur	*element;
	t_containeur	*tmp;
	
	element = (t_containeur *)malloc(sizeof(*element));
	if(!element)
		exit(EXIT_FAILURE);
	element->box = ft_strdup(str);
	if(!element->box)
		exit(EXIT_FAILURE);
	element->next = NULL;
	if(is_empty(li))
		return element;
	tmp = li;
	while(tmp->next != NULL)
			tmp = tmp->next;
	tmp->next = element;
	return (li);
}

t_containeur	*pop_front(t_containeur *li)
{
	t_containeur	*element;

	if(is_empty(li))
		return li;
	element = malloc(sizeof(*element));
	if(!element)
		exit(EXIT_FAILURE);
	element = li->next;
	ft_memdel((void *)&li->box);
	free(li);
	li = NULL;
	return element;
}

t_containeur	*clearlist(t_containeur *li)
{
	if (is_empty(li))
		return li;
	while(li != NULL)
		li = pop_front(li);
	return li;
}