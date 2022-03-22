/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:23:58 by briffard          #+#    #+#             */
/*   Updated: 2022/03/22 14:43:59 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static t_bool		checkparams(char c);
static t_parameter	setup(char *str, t_parameter li, va_list ap);
static t_parameter	resetoption(t_parameter li, char *str);

static t_parameter	resetoption(t_parameter li, char *str)
{
	li.flag = str[ft_strlen(str) - 1];
	li.hastag = 0; 
	li.positif = 0; 
	li.space = 0; 
	li.width = 0; 
	li.zero = 0;
  	// check si le flag est Upper case OK
	li.precision = 0;
	li.char_to_skip = 0;
	li.size = ft_strlen(str);
	return (li);
}


static t_parameter	setup(char *str, t_parameter li, va_list ap)
{
	int		i;

	// ft_debug("yellow", "setup", 00,"NULL", -1 );

	i = 0;
	li = resetoption(li, str);
	
	 while (str[i] == '#' || str[i] == '0' || str[i] == '+' || str[i] == '-' || str[i] == ' ')
	{
		if(str[i] == '#')
			li.hastag = true;
		else if (str[i] == '+')
			li.positif = true;
		else if (str[i] == '-')
			li.negatif = true;
		else if (str[i] == ' ')
			li.space = true;
		else if (str[i] == '0')
			li.zero = true;
		i++;
	}
	if(str[i] == '*')
		{
			li.width = va_arg(ap, int);
			if(li.width < 0) // What happend if va_arg est negatif ?
				exit(EXIT_FAILURE);
			i++;
		}
	else 
	{
		li.width = ft_atoi(&str[i]);
		i += skip(&str[i]);
	}
	if(str[i] == '.')
	{
		i++;
		if (str[i] == '*')
		{
			li.precision = va_arg(ap, int);
			if(li.width < 0) // What happend if va_arg est negatif ?
				exit(EXIT_FAILURE);
			i++;	
		}
		else
		{
			li.precision =  ft_atoi(&str[i]);
			i += skip(&str[i]);
		}
		li.flag = str[i];
	}
	else 
	{
		li.flag = str[i];
	}
	printf("li.space		= ->%d<-\n", li.space); 
	printf("li.zero			= ->%d<-\n", li.zero); 
	printf("li.#			= ->%d<-\n", li.hastag); 
	printf("li.positif		= ->%d<-\n", li.positif); 
	printf("li.negatif		= ->%d<-\n", li.negatif);
	printf("li.flag			= ->%c<-\n", li.flag); 
	printf("li.width		= ->%zu<-\n", li.width); 
	printf("li.upper		= ->%d<-\n", li.upper); 
	printf("li.precision		= ->%zu<-\n", li.precision); 
	printf("li.size			= ->%zu<-\n", li.size); 
	return(li);	 
}
	// printf("li.size			= ->%zu<-\n", li.size); 
	// if(li.size == 1)
	// 	return li;
	// ft_debug("yellow", "setup", 01,"NULL", -1 );
	// i = 0;
	// while(str[i] != '\0')
	// {
		// ft_debug("yellow", "setup", 02,"NULL", -1 );
		// x = 0;
		// while(option[x] != '\0')
		// {
			// ft_debug("yellow", "setup", 03,"NULL", -1 );
		// 	printf("FLAG: ->%c<-\n", str[i]);
		// 	if (str[i] == option[x])
		// 		{
		// 			printf("setup STR ->%s<-\n", &str[i]);
		// 			li = funcOption[x](li, &str[i], ap);
		// 			break;
		// 		}
		// 	x++;
		// }
		// ft_debug("yellow", "setup", 04,"NULL", -1 );
	// 	if (str[0] >= '0' && str[0] <= '9' && i == 0)
	// 		{
	// 			li = setupspace(li, &str[i], ap);
	// 			i += skip(str);
	// 		}
	// 	else
	// 		i += li.char_to_skip;
	// }
	// ft_debug("yellow", "setup", 05,"NULL", -1 );
// 	printf("li.space		= ->%d<-\n", li.space); 
// 	printf("li.zero			= ->%d<-\n", li.zero); 
// 	printf("li.#			= ->%d<-\n", li.hastag); 
// 	printf("li.positif		= ->%d<-\n", li.positif); 
// 	printf("li.flag			= ->%c<-\n", li.flag); 
// 	printf("li.width		= ->%zu<-\n", li.width); 
// 	printf("li.upper		= ->%d<-\n", li.upper); 
// 	printf("li.precision		= ->%zu<-\n", li.precision); 
// 	printf("li.size			= ->%zu<-\n", li.size); 
// 	return(li);
// }
/*static t_parameter	setup(char *str, t_parameter li, va_list ap)// deux direction si str[0] == option go vers option si str[0] == h ou l on peut aussi voir pour ajouter ses lett
{
	int	i;
	int	x;

	i = 0;
	li = resetoption(li, str);
	while (str[i] != '\0')
	{
		printf("VALEUR DE STR[%d] = %c\n", i, str[i]);
		printf("VALEUR DE STR debut while loop = ->%s<-\n", str);
		x = 0;
		while(option[x] != '\0')
		{
			i = 0;
			printf("VALEUR DE STR[%d] =->%c<-\n", i, str[i]);
			
			if (str[0] == option[x])
			{
				li = funcOption[x](li, str);
				if (str [i + 1] == '*')
					{
						li.dotlenght = va_arg(ap, int);
						li.star = 1;
					}
				if (str[0] == '+')
					i++;
				else
				{
					while((str[i + 1] >= '0' && str[i + 1] <= '9') && str[i] != '\0')
						i++;
					i++;
				}
				if (i == 0)
					i++;
				printf("Valeur de I = %d\n", i);
				printf(" BEFORE TO MOVE POINTEURVALEUR DE STR[%d] =->%c<-\n", i, str[i]);
				str = &str[i];// bouger le debut de str apres le nombres
				printf("VALEUR DE STR  apres mouv pointer = ->%s<-\n", str);
				// i = 0;
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
*/
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
	// ft_debug("cyan", "init", 00,"NULL", -1 );
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
	ft_debug("cyan", "init", 01, str, -1 );
	li = setup(str, li, ap);
	ft_memdel((void**)&str);
	ft_debug("cyan", "init", 02,"NULL", -1 );
	/*if(checkoptionerror(li))
		exit(EXIT_FAILURE);*/
	 ft_debug("cyan", "init", 03,"NULL", -1 );
	return (li);
}