/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:42:38 by briffard          #+#    #+#             */
/*   Updated: 2022/02/21 15:29:40 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	main(void)
{
	char	*name;
	char	*str;
	char	*lastname;
	int		ret;

	str = NULL;
	name = "Joe";
	lastname = "Dassin";
	ret = ft_printf("My name is %s et mon nom de famille est %s.\nMy age is %d\n", name, lastname, 36);
	ft_printf("Le retour est = %d\n", ret);
	ft_printf("Essayons d impimer un char: %c\n", 'c');
	ft_printf("Display %%\n");

	return (EXIT_SUCCESS);
}

