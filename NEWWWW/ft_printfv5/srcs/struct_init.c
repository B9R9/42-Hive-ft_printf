/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:27:52 by briffard          #+#    #+#             */
/*   Updated: 2022/04/13 10:18:20 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	checkparams(char c);
static t_parameter	resetoption(t_parameter li, char *str);
static t_parameter	setup(char *str, t_parameter li, va_list ap);


/*RESET ALL PARAMETERS*/
static t_parameter	resetoption(t_parameter li, char *str)
{
	if (ft_isupper(str[ft_strlen(str) - 1]))
		li.upper = true;
	else
		li.upper = false;
	li.width = 0;
	li.precision = 0;
	li.char_to_skip = 0;
	li.size = ft_strlen(str);
	return (li);
}

/*PARSE PARAMETERS STR TO DEFINE THEM INTO THE STRUCT*/
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
/*LOOKING FOR THE FLAG*/
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

t_parameter	init(const char *format,t_parameter li, va_list ap)
{
	char		*parameters;
	char		*temp;
    int         index;

	index = 1;
	while (checkparams(format[index]))
		index++;
    /*if (index >= ft_strlen(format))//If TRUE (CAD -> no flags detected)
    {
        ft_putstr("ERROR NO FLAG DETECTED\n");
        exit(EXIT_FAILURE);
    }*/
	parameters = ft_strsub(format, 1, index);
	if (!parameters)
		exit(EXIT_FAILURE);
	temp = parameters;
	ft_memdel((void *)&parameters);
	parameters = temp;
	li = setup(parameters, li, ap);
	// ft_memdel((void *) &parameters);
	return (li);
}

/*
ft_printf("%")
*/