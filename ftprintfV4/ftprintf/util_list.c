/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:59:19 by briffard          #+#    #+#             */
/*   Updated: 2022/03/22 14:41:39 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char	*revstr(char *str)
{
	int	index;
	int	max;
	int	i;
	int x = 1;
	
	i = 0;
	index = 1;
	max = ft_strlen(str);
	// printf("ORIGINAL ->%s<-\n",str);
// 	printf("MAX : ->%d<-\n", max);
	while (index < max)
	{
		i = 0;
		while( i < (max - x) && str[i + 1] != '\0')
		// printf("INDEX : ->%d<-\n", max);
		// printf("MAX : ->%d<-\n", max);
		{
			
			ft_swap(&str[i], &str[i + 1]);
			i++;
		}
		// printf("SWAP ->%s<-\n",str);
		x++;
		index++;
	}
	return (str);
}


int	skip(char *str)
{
	int		index = 0;
	while (str[index] >= '0' && str[index] <= '9')
		index++;
	return index;
}

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

int		list_lenght(t_containeur *li)
{
	int size;

	size = 0;
	if (!is_empty(li))
		while (li != NULL)
		{
			size++;
			li = li->next;
		}
	return size;
}

void	printlist(t_containeur *li)
{
	if(is_empty(li))
		printf("Nothing to print. List is empty\n");
	while (li != '\0')
	{
		printf("->%s<-", li->box);
		li = li->next;
	}
	printf("\n");
}

t_containeur	*push_back(t_containeur *li, char *str)
{
	t_containeur	*element;
	t_containeur	*tmp;
	//ft_debug("cyan", "push_back", 01, str, -1);
	element = (t_containeur*)malloc(sizeof(*element));
	/*chechk for malloc error*/

	//element->box = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	/*chechk for malloc error*/

	element->box = ft_strdup(str);
	//ft_debug("cyan", "push_back", 02, element->box, -1);
	element->next = NULL;
	if(is_empty(li))
		return element;
	//ft_debug("cyan", "push_back", 03, element->box, -1);
	tmp = li;
	//ft_debug("cyan", "push_back", 04, tmp->box, -1);
	while(tmp->next != NULL)
			tmp = tmp->next;
	tmp->next = element;
	//ft_debug("cyan", "push_back", 07, li->box, -1);
	return li;
}

t_containeur	*push_front(t_containeur *li, char *str)
{
	t_containeur	*element;

	element = malloc(sizeof(*element));
	/*chechk for malloc error*/

	//element->box = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	/*chechk for malloc error*/

	element->box = ft_strdup(str);
	if(is_empty(li))
		return element = NULL;
	else
		element->next = li;
	return element;
}
/*
t_containeur	*pop_back(t_containeur *li)
{
	t_containeur	*temp;
	t_containeur	*before;
	
	if(is_empty(li))
		return newlist();
	if(li->next == NULL)
	{
		free(li);
		li = NULL;
		return newlist();
	}
	temp = li;
	before = li;
	while(temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}
	before->next;
	free(temp);
	temp = NULL;
	return li;
}
*/

t_containeur	*pop_front(t_containeur *li)
{
	t_containeur	*element;

	if(is_empty(li))
		return li;
	element = malloc(sizeof(*element));
	/*check for malloc error*/

	element = li->next;
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