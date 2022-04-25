/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:24:41 by briffard          #+#    #+#             */
/*   Updated: 2022/04/25 12:16:26 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dispacht(va_list ap, t_parameter *new);

/*
** Receive va_list and send to the right function
*/
static int	dispacht(va_list ap, t_parameter *new)
{
	if (new->conv == '%')
		return (conv_to_int(new, ap));
	else
		return (g_funcflagsarray[new->conv - 'a'](new, ap));
}

int	ft_printf(const char *format, ...)
{
	t_parameter	*option;
	va_list		ap;
	int			size;
	int			i;

	size = 0;
	i = 0;
	option = NULL;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			option = init(&format[i], option, ap);
			if (option->error)
				return (error ("(Error founded.The output will be altered)\n"));
			size += dispacht(ap, option);
			i += option->size + 1;
		}
		else
			size += print_char(format[i++]);
	}
	va_end(ap);
	free(option);
	return (size);
}

/*TO REMOVE*/
/*PRINT PARAMETER*/
void	check_parameter(t_parameter *li)
{
    printf("WIDTH           -->%d\n", li->width);
    printf("FLAG            -->%c\n", li->conv);
    printf("upper           -->%d\n", li->upper);
    printf("precision       -->%d\n", li->precision);
    printf("char_to_skip    -->%d\n", li->char_to_skip);
    printf("size_Prefix     -->%s\n", li->sizeprefix);
    printf("size            -->%d\n", li->size);
}

/*PRINT VALEUR DE option->flags*/
void    check_flasgbit(t_parameter *option)
{
    printf("F_NEGATIF ->%d<-\n", option->flags & F_NEGATIF);
    printf("F_HASHTAG ->%d<-\n", option->flags & F_HASHTAG);
    printf("F_ZERO ->%d<-\n", option->flags & F_ZERO);
    printf("F_PLUS ->%d<-\n", option->flags & F_PLUS);
    printf("F_MINUS ->%d<-\n", option->flags & F_MINUS);
    printf("F_SPACE ->%d<-\n", option->flags & F_SPACE);
    printf("BOOL Negatif ->%d<-\n", option->negatif);
}
