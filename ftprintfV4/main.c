/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:13:18 by briffard          #+#    #+#             */
/*   Updated: 2022/03/18 17:13:01 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include<limits.h>

int		main(void)
{

	// char *str;
	int number;

	number = 73;
	// str = "Mais putain !!!!!";
	//ft_printf("MAX_INT = %d || MIN_INT = %d\n",INT_MAX, INT_MIN);

	ft_printf("%+010.8d\n", number);

	return 0;
}