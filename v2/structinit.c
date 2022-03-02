/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:23:58 by briffard          #+#    #+#             */
/*   Updated: 2022/03/02 13:40:47 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static t_bool		checkparams(char c);
static t_parameter	setup(char *str, t_parameter li);

static t_parameter	setup(char *str, t_parameter li)// deux direction si str[0] == option go vers option si str[0] == h ou l on peut aussi voir pour ajouter ses lett
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		x = 0;
		while(option[x] != '\0')
		{
			if (str[i] == option[x])
			{
				li = funcOption[x](li, str)
				while(str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
					i++;
				str = // bouger le debut de str apres le nombres
				break;
			}
			x++;
		}
	}

	/*IDEE POUR ARRAY POINTEUR FUNCTION OPTION*/
/*	int	i;

	i = 0;
	while(option[i] != '\0')
	{
		if(str[0] == option[i])
		{
			li = funcOption[i](li, str);
			break;
		}
		i++;
	}
	printf("li.space %d\n",li.space);
	printf("li.lenght %d\n",li.lenght);
	printf("li.size %d\n",li.size);
	printf("li.flag %c\n",li.flag);
	printf("li.content %d\n",li.contentsize);

	return (li);*/
}

static t_bool	checkparams(char c)
{
	size_t	i;

	i = 0;
	while (flags[i] != '\0')
	{
		if (c == flags[i])
			return (false);
		i++;
	}
	return (true);
}

t_parameter		init(const char *format, int index, t_parameter li)
{
	int		start;
	char	*str;

	start = index;
	index += 1;
	while (checkparams(format[index]))
		index++;
	str = ft_strsub(format, start + 1, (index - start));
	if (!str)
	{
		printf("Error: Allocation memory\nLocated in strucinit.c Line 40\n");
		exit(EXIT_FAILURE);
	}
	printf("VALEUR DE STR IN INIT = %s\n", str);
	li = setup(str, li);
	ft_memdel((void**)&str);
	return (li);
}