/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:20:07 by briffard          #+#    #+#             */
/*   Updated: 2022/03/04 14:51:16 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<float.h>


int	main(void)
{
	char	*test;
	int		num;

	num = 73;
	test = "essai";

	printf("->%.8s<-\n", test);
	printf("->%12d<-\n", num);
	return (0);
}