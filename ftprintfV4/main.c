/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:13:18 by briffard          #+#    #+#             */
/*   Updated: 2022/03/16 15:15:54 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int		main(void)
{
	//char	*test;
	char	*name;
	char	*lastname;

	//test = "Hello World!";
	name = "Bender";
	lastname = "Rodriguez";
	//ft_printf(test);
	ft_printf("My name is %*s\n", 5, lastname);
	return 0;
}