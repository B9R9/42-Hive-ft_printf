/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:23:58 by briffard          #+#    #+#             */
/*   Updated: 2022/03/01 16:25:04 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static t_bool		checkparams(char c);
static t_parameter	setup(char *str, t_parameter li);

static t_parameter	setup(char *str, t_parameter li)
{
	if (str[0] == ' ');
	else if (str[0] == '.')
	else if (str[0] == '*')
	else if (str[0] == ' ')
	else if (str[0] == '0')
	else if (str[])
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

t_parameter		init(const char *format, int index, t_parameter li)
{
	int		start;
	char	*str;

	start = index;
	index += 1;
	while (checkparams(format[index]))
		index++;
	str = ft_strsub(format, start + 1, (index - start) + 1);
	if (!str)
	{
		printf("Error: Allocation memory\nLocated in strucinit.c Line 40\n");
		exit(EXIT_FAILURE);
	}
	li = setup(str, li);
	ft_memdel((void**)&str);
	return (li);
}