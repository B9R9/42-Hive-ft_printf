/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:20:07 by briffard          #+#    #+#             */
/*   Updated: 2022/03/02 13:39:02 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<float.h>


int	main(void)
{
	int i = 0;
	double test = DBL_MAX;
	int x = (int)test;
	if (test > 2)
		printf ("true\n");
	while (i < 100)
	{
		test = test - (double)x;
		test = test / 100000000;
		i++;
	}
	printf("%f\n", test);

	return (0);
}