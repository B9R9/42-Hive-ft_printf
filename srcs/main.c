/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:42:38 by briffard          #+#    #+#             */
/*   Updated: 2022/02/18 14:24:46 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	main(void)
{
	char	*name;
	char	*lastname;

	name = "Joe";
	lastname = "Dassin";
	ft_printf("My name is %s et mon nom de famille est %s\n", name, lastname);
	return (EXIT_SUCCESS);
}

