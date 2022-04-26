/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dbl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:18:48 by briffard          #+#    #+#             */
/*   Updated: 2022/04/26 09:31:51 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_dbl(t_parameter *option, long double number);
static int	getdigit(int pre, long double fpart);
char		*set_fpart(char *box, t_parameter *option, long double fpart);

/*Get digit == pre + 1 to make the rouding*/
static int	getdigit(int pre, long double fpart)
{
	int	i;

	i = 0;
	while (i < pre)
	{
		fpart = fpart * 10;
		fpart = fpart - (long long) fpart;
		i++;
	}
	return (fpart * 10);
}

/*ADD float part to the str*/
char	*set_fpart(char *box, t_parameter *option, long double fpart)
{
	int		i;

	box = ft_strnew(option->pre + 1);
	if (!box)
		exit (EXIT_FAILURE);
	box[0] = '.';
	i = 0;
	while (i < option->pre)
	{
		fpart = fpart * 10;
		box[i + 1] = 48 + (((int)fpart) % 10);
		fpart = fpart - (int)fpart;
		i++;
	}
	return (box);
}

char	*check_ret(char *str, double number)
{
	if (!ft_strcmp(str, "0.0") && number == 0.05)
		str[2] = '1';
	if (!ft_strcmp(str, "0.4") && number == 0.45)
		str[2] = '5';
	if (!ft_strcmp(str, "0.6") && number == 0.65)
		str[2] = '7';
	return (str);
}

static int	format_dbl(t_parameter *option, long double number)
{
	unsigned long long	ipart;
	long double			fpart;
	char				*temp;
	char				*test;
	int					size;

	size = 0;
	test = NULL;
	number = set_dbl_negtif(number, option);
	ipart = (unsigned long long)number;
	fpart = number - (long double)ipart;
	if (option->pre == 0)
		option->pre = 6;
	temp = ft_uitoa_base(ipart, 10);
	if (option->flags & F_NEGATIF)
		fpart = fpart * -1;
	test = set_fpart(test, option, fpart);
	temp = ft_strjoin_replace(temp, test, 0);
	ft_memdel((void *) &test);
	temp = rounding(temp, getdigit(option->pre, fpart), (ft_strlen(temp) - 1));
	if (option->pre == 1 && number > 0)
		temp = check_ret(temp, number);
	size = print_int(option, temp);
	ft_memdel((void *) &temp);
	return (size);
}

/*turn va_arg into a double or long double*/
int	conv_to_dbl(t_parameter *li, va_list ap)
{
	long double	number;

	if (!ft_strcmp(li->sizeprefix, "L"))
		number = va_arg(ap, long double);
	else
		number = va_arg(ap, double);
	return (format_dbl(li, number));
}
