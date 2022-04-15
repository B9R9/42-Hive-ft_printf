/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:06:52 by briffard          #+#    #+#             */
/*   Updated: 2022/02/03 19:31:30 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void		print_dlist(dlist li)
{
	t_dlistnode		*temp;

	if (is_empty_dlist(li))
	{
		ft_putstr("Nothing to print. Empty list\n");
	return;
	}
	temp = li->begin;
	while(temp->next != NULL)
	{
		ft_putnbr(temp->value);
		ft_putchar('\n');
		temp = temp-> next;
	}
	ft_putchar('\n');
}