/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:27:52 by briffard          #+#    #+#             */
/*   Updated: 2022/04/14 14:21:23 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	checkparams(char c);
// static void	resetoption(t_parameter *li, char *str);
static t_parameter	*setup(char *str, t_parameter *li, va_list ap);


/*RESET ALL PARAMETERS*/
static void	resetoption(t_parameter *option, char *str)
{
	option->upper = 0;
	if (ft_isupper(str[ft_strlen(str) - 1]))
		option->upper = 1;
	option->width = 0;
	option->precision = 0;
	option->char_to_skip = 0;
	option->sizePrefix = NULL;
	option->size = ft_strlen(str);

}

/*PARSE PARAMETERS STR TO DEFINE THEM INTO THE STRUCT*/
static t_parameter	*setup(char *str, t_parameter *li, va_list ap)
{
	resetoption(li, str);
	handle_flag(str, li);
	handle_width(&str[li->char_to_skip], li, ap);
	handle_precision(&str[li->char_to_skip], li, ap);
	handle_size_prefix(&str[li->char_to_skip], li);
	li->conv = ft_tolower(str[li->char_to_skip]);
	checkoptionerror(li);
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

t_parameter	*init(const char *format,t_parameter *option, va_list ap)
{
	char		*parameters;
	char		*temp;
    int         index;

	index = 1;
	while (checkparams(format[index]))
		index++;
	parameters = ft_strsub(format, 1, index);
	if (!parameters)
		exit(EXIT_FAILURE);
	if (!option)
	{
		option = (t_parameter *)malloc(sizeof(*option));
		if (!option)
			exit(EXIT_FAILURE);
	}
	temp = parameters;
	ft_memdel((void *)&parameters);
	parameters = temp;
	setup(parameters, option, ap);
	return (option);
}