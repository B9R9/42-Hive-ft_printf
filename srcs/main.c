/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:42:38 by briffard          #+#    #+#             */
/*   Updated: 2022/02/25 15:25:20 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <stdio.h>

int	main(void)
{
//	char	*name;
//	char	*lastname;
//	int		ret;
//	float	pi = 3.14159235358979323846;
//	double  pi2 = -3.14;
	unsigned int b = -7;

//	name = "Joe";
//	lastname = "Dassin";
//	ret = ft_printf("My name is %s et mon nom de famille est %s.\nMy age is %d\n", name, lastname, 36);
	ft_printf("Le retour est = %d\n", -95);
//	ft_printf("Essayons d impimer un char: %c\n", 'c');
//	ft_printf("Display %%\n");
//	ft_printf("Pi@ = %f\n", pi);
//	printf("Pi = %f\n", pi);
//	ft_printf("Pi2@ = %f\n",pi2);
//	printf("Pi2 = %f\n",pi2);
//	printf("Valeur du pointeur name %p\n", name);
//	//ft_printf("@Valeur du pointeur name %p\n", name);
//	printf("Valeur en hexadecimal = %x\n", 65748);
//	ft_printf("@Valeur en hexadecimal = %x\n", 65748);
//	printf("Valeur en hexadecimal = %X\n", 1000000);
//	ft_printf("@Valeur en hexadecimal = %X\n", 1000000);
//	printf("Valeur octal = %o\n", 78676);
//	ft_printf("@Valeur octal = %o\n", 78676);
//	printf("Sizeof char= %lu\n", sizeof("Joe"));
//	printf("Sizeof char= %lu\n", sizeof(char));
//	printf("Sizeof char= %lu\n", sizeof(name[0]));
//	printf("Sizeof int= %lu\n", sizeof(int));
//	printf("Sizeof char*= %lu\n", sizeof(char*));
//	printf("Sizeof int*= %lu\n", sizeof(int*));
//	printf("Sizeof double= %lu\n", sizeof(double));
//	printf("Sizeof float= %lu\n", sizeof(float));
//	printf("Sizeof &x= %lu\n", sizeof(&x));
//	printf("Sizeof 23= %lu\n", sizeof(23));
//	ft_printf("Valeur en BIT=\n%b\n", name);
//	ft_printf("Valeur en BIT= \n%b\n", 2);
	printf("FLag u = %u\n", b);
	ft_printf("FT lLag u = %u\n", b);


	return (EXIT_SUCCESS);
}

