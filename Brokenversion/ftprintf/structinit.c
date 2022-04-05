/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:23:58 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 13:56:52 by briffard         ###   ########.fr       */
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
	li.width = 0;
	li.precision = 0;
	li.char_to_skip = 0;
	li.size = ft_strlen(str);
	return (li);
}

static t_parameter	setup(char *str, t_parameter li, va_list ap)
{
	li = resetoption(li, str);
	li = handle_flag(str, li);
	li = handle_width(&str[li.char_to_skip], li, ap);
	li = handle_precision(&str[li.char_to_skip], li, ap);
	li = handle_size_prefix(&str[li.char_to_skip], li);
	li.conv = ft_tolower(str[li.char_to_skip]);
	li = checkoptionerror(li);
	return (li);
}

static t_bool	checkparams(char c)
{
	size_t	i;

	i = 0;
	while (ARRFLAGS[i] != '\0')
	{
		if (c == ARRFLAGS[i])
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
		ft_errormem("structinit.c", 66);
		exit(EXIT_FAILURE);
	}
	li = setup(str, li, ap);
	//ft_memdel((void *) &str);
	return (li);
}
