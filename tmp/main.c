/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:20:07 by briffard          #+#    #+#             */
/*   Updated: 2022/03/01 13:56:50 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

typedef struct	s_flags
{
	char flag;
	char precision;
	int	lenght;
	t_bool conversion;



}

typedef int (*action_t)(char *str);
int bonjour(char *str);
int hello(char *str);

int bonjour(char *str)
{
	printf("%s\n", str);
	return (50);
}

int hello(char *str)
{
	printf("%s\n", str);
	return (25);
}

int	main(void)
{
	char *str;
	char *str2;

	str = "test";
	str2 = "test2";
	action_t test[] = {bonjour, hello};
	test[0](str);
	test[1](str2);
	return (0);
}