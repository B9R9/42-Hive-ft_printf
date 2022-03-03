/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:57:27 by briffard          #+#    #+#             */
/*   Updated: 2022/03/03 14:56:15 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	main(void)
{
	char	*name;
	int		essai;

	name = "Joe";
	essai = 123;
	
	ft_printf("My name is %d\n", name);
	printf("TEST: % 5.4d\n", essai);
	printf("TEST: % 6d\n", essai);
	printf("TEST: 00000000");
	return (EXIT_SUCCESS);
}