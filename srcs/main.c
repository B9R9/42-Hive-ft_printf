/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:42:38 by briffard          #+#    #+#             */
/*   Updated: 2022/03/01 09:53:20 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <stdio.h>

int	main(void)
{
	char	*name;
//	char	*lastname;
//	int		ret;
//	float	pi = 3.14159235358979323846;
//	double  pi2 = -3.14;
//	unsigned int b = -7;
//	char *str;
	
//	str = NULL;
	name = "Joe";
	ft_printf("My Name is %.5s\n", name);
	ft_printf("My Name is %010s\n", name);
	ft_printf("My Name is %15s\n", name);
	ft_printf("My Name is %*5s\n", name);
	ft_printf("My Name is %*5$s\n", name);
	ft_printf("My Name is % s\n", name);
	ft_printf("My Name is %+s\n", name);
	ft_printf("My Name is %-5s\n", name);
	printf("TEST = % 5d\n", 23);
	printf("TEST = % 6d\n", 23);
//	lastname = "Dassin";
//	ret = ft_printf("My name is %s et mon nom de famille est %s.\nMy age is %d\n", name, lastname, 36);
//	ft_printf("@Le retour est = %d\n", -95);
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
//	printf("flag u = %u\n", b);
//	ft_printf("@flag u = %u\n", b);
//	printf("Adresse de pointer flag p: %p\n", str);
//	ft_printf("@Adresse de pointer flag p: %p\n", str);
//	printf("Adresse de pointer flag p: %p\n", &str);
//	ft_printf("@Adresse de pointer flag p: %p\n", &str);
//
//
//
//
/*
	printf("=========================================  precision\n");
	char	*str;
	float	numDouble  =  72.20;
	float	numDouble1 =  72.21;
	float	numDouble2 =  72.22;
	float	numDouble3 =  72.23;
	float	numDouble4 =  72.24;
	float	numDouble5 =  72.25;
	float	numDouble6 =  72.26;
	float	numDouble7 =  72.27;
	float	numDouble8 =  72.28;
	float	numDouble9 =  73.49;
	float	numDouble10  =  73.20;
	float	numDouble11  =  73.21;
	float	numDouble22  =  73.22;
	float	numDouble33  =  73.23;
	float	numDouble44  =  73.24;
	float	numDouble55  =  73.25;
	float	numDouble66  =  73.26;
	float	numDouble77  =  73.27;
	float	numDouble88  =  73.28;
	float	numDouble99  =  73.59;
	int test;
	test = 123;
	str = "Hello";
	printf("%.3s\n", str);//Hel
	printf("%.5d\n", test);//00123
	printf("%.8f\n", numDouble); // 42.7
	printf("%.8f\n", numDouble1); // 42.7
	printf("%.8f\n", numDouble2); // 42.7
	printf("%.8f\n", numDouble3); // 42.7
	printf("%.8f\n", numDouble4); // 42.7
	printf("%.8f\n", numDouble5); // 42.7
	printf("%.8f\n", numDouble6); // 42.7
	printf("%.8f\n", numDouble7); // 42.7
	printf("%.8f\n", numDouble8); // 42.7
	printf("%.8f\n", numDouble9); // 42.7
	printf("%.8f\n", numDouble10); // 42.7
	printf("%.8f\n", numDouble11); // 42.7
	printf("%.8f\n", numDouble22); // 42.7
	printf("%.8f\n", numDouble33); // 42.7
	printf("%.8f\n", numDouble44); // 42.7
	printf("%.8f\n", numDouble55); // 42.7
	printf("%.8f\n", numDouble66); // 42.7
	printf("%.8f\n", numDouble77); // 42.7
	printf("%.8f\n", numDouble88); // 42.7
	printf("%.8f\n", numDouble99); // 42.7
	//printf("%*1$d", test);
//
	printf("=========================================  minimun field width\n");
	
	printf("%*d\n", 5, 123);//00123
	printf("%*d\n", 6, 123);//00123
*/
//
/*
	printf("=========================================  TEST PRECISION %%0 ot %%10\n");
	printf("Test precision 0:%11f\n",23.23);
	printf("Test precision 0:%12f\n",23.23);
	printf("Test precision 0:%11d\n",23);
	printf("Test precision 0:%12d\n",23);
	printf("Test precision 0:%11u\n",246);
	printf("Test precision 0:%12u\n",246);
	printf("Test precision 0:%11i\n",246);
	printf("Test precision 0:%12i\n",246);
	printf("Test precision 0:%11x\n",246);
	printf("Test precision 0:%12x\n",246);
	printf("Test precision 0:%11o\n",246);
	printf("Test precision 0:%12o\n",246);
	printf("Test precision 0:%11X\n",246);
	printf("Test precision 0:%12X\n",246);
	printf("Test precision 0:%011f\n",23.23);
	printf("Test precision 0:%012f\n",23.23);
	printf("Test precision 0:%011d\n",23);
	printf("Test precision 0:%012d\n",23);
	printf("Test precision 0:%011u\n",246);
	printf("Test precision 0:%012u\n",246);
	printf("Test precision 0:%011i\n",246);
	printf("Test precision 0:%012i\n",246);
	printf("Test precision 0:%011x\n",246);
	printf("Test precision 0:%012x\n",246);
	printf("Test precision 0:%011o\n",246);
	printf("Test precision 0:%012o\n",246);
	printf("Test precision 0:%011X\n",246);
	printf("Test precision 0:%012X\n",246);

	printf("=========================================  TEST PRECISION #\n");
	float c = 23;
	printf("Test precision # %%f:%#f\n",c);
//	printf("Test precision #:%#d\n",23);
//	printf("Test precision #:%#d\n",23);
//	printf("Test precision #:%#u\n",246);
//	printf("Test precision #:%#u\n",246);
//	printf("Test precision #:%#i\n",246);
//	printf("Test precision #:%#i\n",246);
	printf("Test precision # %%x:%#x\n",246);
	printf("Test precision # %%o:%#o\n",246);
	printf("Test precision # %%X:%#X\n",246);
//	printf("Test precision #:%#d\n",23);
//	printf("Test precision #:%#d\n",23);
//	printf("Test precision #:%#u\n",246);
//	printf("Test precision #:%#u\n",246);
//	printf("Test precision #:%#i\n",246);
//	printf("Test precision #:%#i\n",246);
	printf("=========================================  TEST PRECISION -\n");
	
	int d = 23;
	printf("Test precision - %%f:%-f\n",c);
	printf("Test precision - %%f:%f\n",c);
	printf("Test precision - %%d:%-d\n",d);
	printf("Test precision - %%d:%d\n",d);

	printf("=========================================  TEST PRECISION space\n");

	printf("Test precision aq %%aq:% d\n",d);
	printf("Test precision aq %%aq:%d\n",d);
	printf("Test precision aq %%aq:% f\n",c);
	printf("Test precision aq %%aq:%f\n",c);
	printf("Test precision aq %%aq:% x\n",246);
//	printf("Test precision aq %%aq:% o\n",246);
//	printf("Test precision aq %%aq:% X\n",246);
//	printf("Test precision aq %%aq:% s\n", "Hello");
//	printf("Test precision aq %%aq:% c\n", 'H');
	printf("=========================================  TEST PRECISION +\n");
	
	int q = -73;
	printf("Test precision + %%+: %+d\n", d);
	printf("Test precision + %%+: %d\n", d);
	printf("Test precision + %%+: %d\n", q);
	printf("Test precision + %%+: %+d\n", q);
	printf("Test precision + %%+: %f\n", c);
	printf("Test precision + %%+: %+f\n", c);
	printf("Test precision + %%+: %i\n", 123456);
	printf("Test precision + %%+: %+i\n", 123456);
	*/
	return (EXIT_SUCCESS);
}

