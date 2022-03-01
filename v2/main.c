/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:57:27 by briffard          #+#    #+#             */
/*   Updated: 2022/03/01 16:25:46 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	main(void)
{
	char	*name;

	name = "Joe";

	ft_printf("My name is %s\n", name);
	return (EXIT_SUCCESS);
}