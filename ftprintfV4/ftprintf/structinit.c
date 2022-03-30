/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:23:58 by briffard          #+#    #+#             */
/*   Updated: 2022/03/30 15:12:20 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static t_bool		checkparams(char c);
static t_parameter	setup(char *str, t_parameter li, va_list ap);
static t_parameter	resetoption(t_parameter li, char *str);

static t_parameter	resetoption(t_parameter li, char *str)
{
	li.upper = false;
	if (ft_isupper(str[ft_strlen(str) - 1]))
		li.upper = true;
	li.hastag = 0;
	li.addspace = 0;
	li.dot = 0;
	li.positif = 0;
	li.space = 0;
	li.width = 0;
	li.zero = 0;
	li.precision = 0;
	li.size = ft_strlen(str);
	li.char_to_skip = 0;
	li.negatif = 0; // a changer pour left align
	li.signeneg = 0;
	return (li);
}

static t_parameter	setup(char *str, t_parameter li, va_list ap)
{
	li = resetoption(li, str);
	li = handle_flag(str, li);

	li = handle_width(&str[li.char_to_skip], li, ap);

	li = handle_precision(&str[li.char_to_skip], li, ap);

	li = handle_size_prefix(&str[li.char_to_skip], li);

	li.flag = ft_tolower(str[li.char_to_skip]);
	
	// printf("li.dot		= ->%d<-\n", li.dot); 
	// printf("li.space		= ->%d<-\n", li.space); 
	// printf("li.zero			= ->%d<-\n", li.zero); 
	// printf("li.#			= ->%d<-\n", li.hastag); 
	// printf("li.positif		= ->%d<-\n", li.positif); 
	// printf("li.negatif		= ->%d<-\n", li.negatif);
	// printf("li.flag			= ->%c<-\n", li.flag); 
	// printf("li.width		= ->%zu<-\n", li.width); 
	// printf("li.upper		= ->%d<-\n", li.upper); 
	// printf("li.precision		= ->%zu<-\n", li.precision); 
	// printf("li.size			= ->%zu<-\n", li.size); 
	// printf("li.size.Prefix 		= ->%s<-\n", li.sizePrefix);
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

t_parameter	init(const char *format, size_t index, t_parameter li, va_list ap)
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
	ft_memdel((void **) &str);
	// if(checkoptionerror(li))
	// 	exit(EXIT_FAILURE);
	return (li);
}
