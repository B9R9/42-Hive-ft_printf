/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:23:58 by briffard          #+#    #+#             */
/*   Updated: 2022/03/16 15:11:20 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static t_bool		checkparams(char c);
static t_parameter	setup(char *str, t_parameter li, va_list ap);
static t_parameter	resetoption(t_parameter li, char *str);

static t_parameter	resetoption(t_parameter li, char *str)
{
	li.flag = str[ft_strlen(str) - 1];
	li.space = 0;
	li.spacelenght = 0;
	li.dot = 0;
	li.dotlenght = 0;
	li.star = 0;
	li.zero = 0;
	li.zerolenght = 0;
	li.hastag = 0;
	li.signe = 0;
	li.size = ft_strlen(str);
	li.contentsize = 0;
	return (li);
}
static t_parameter	setup(char *str, t_parameter li, va_list ap)// deux direction si str[0] == option go vers option si str[0] == h ou l on peut aussi voir pour ajouter ses lett
{
	int	i;
	int	x;

	i = 0;
	li = resetoption(li, str);
	while (str[i] != '\0')
	{
		//printf("VALEUR DE STR[%d] = %c\n", i, str[i]);
	//	printf("VALEUR DE STR debut while loop = ->%s<-\n", str);
		x = 0;
		while(option[x] != '\0')
		{
	//		printf("VALEUR DE STR[%d] =->%c<-\n", i, str[i]);
			if (str[0] == option[x])
			{
				li = funcOption[x](li, str);
				if (str [i + 1] == '*')
					{
						li.dotlenght = va_arg(ap, int);
						li.star = 1;
					}
				else
				{
					while((str[i + 1] >= '0' && str[i + 1] <= '9') && str[i] != '\0')
						i++;
				}
				if (i == 0)
					i++;
	//			printf("Valeur de I = %d\n", i);
				str = &str[i + 1];// bouger le debut de str apres le nombres
	//			printf("VALEUR DE STR  apres mouv pointer = ->%s<-\n", str);
				i = 0;
				break;
			}
			x++;
		}
		i++;
	}
	
	printf("li.space		= ->%d<-\n", li.space);
	printf("li.spacelenght		= ->%zu<-\n", li.spacelenght);
	printf("li.dot			= ->%d<-\n", li.dot);
	printf("li.dotlenght		= ->%zu<-\n", li.dotlenght);
	printf("li.star			= ->%d<-\n", li.star);
	printf("li.zero			= ->%d<-\n", li.zero);
	printf("li.zeroleng		= ->%zu<-\n", li.zerolenght);
	printf("li.#			= ->%d<-\n", li.hastag);
	printf("li.signe		= ->%d<-\n", li.signe);
	printf("li.flag			= ->%c<-\n", li.flag);
	printf("li.size			= ->%zu<-\n", li.size);
	printf("li.contentsize		= ->%d<-\n", li.contentsize);
	return (li);
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

t_parameter		init(const char *format, size_t index, t_parameter li, va_list ap)
{
	size_t		start;
	char		*str;

	start = index;
	index += 1;
	while (checkparams(format[index]))
		index++;
	str = ft_strsub(format, start + 1, (index - start));
	if (!str)
	{
		ft_errormem("structinit.c", 109);
		exit(EXIT_FAILURE);
	}
	li = setup(str, li, ap);
	ft_memdel((void**)&str);
	li = checkoptionerror(li);
	return (li);
}