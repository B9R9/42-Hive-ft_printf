/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:57:27 by briffard          #+#    #+#             */
/*   Updated: 2022/03/15 09:47:20 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	main(void)
{
	char	*name;
	int		essai;
//	int		ret;

	name = "Joe";
//	essai = 123;
	
	essai = ft_printf("My name is %s\n", name);
//	ret = printf("My name is %.2s\nAnd his last anme is % 5.5s\n", name, "Dassin");
//	ret = printf("My name is %s\nLA suite\n", name);
	printf("\nValeur d essai = %d\n", essai);
//	printf("\nValeur de ret = %d\n", ret);
//	printf("TEST: % 5.4d\n", essai);
//	printf("TEST: % 6d\n", essai);
//	printf("TEST: 00000000");
	return (EXIT_SUCCESS);
}