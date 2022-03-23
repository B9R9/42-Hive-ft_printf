/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:13:18 by briffard          #+#    #+#             */
/*   Updated: 2022/03/23 17:09:02 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include<limits.h>

int		main(void)
{

	//  char *str;
	// int number;
	// char *str;
    // char *new;
    // int  *test;
   //  double test = 3.14542;

    // str = "HeLo";

    // number = 730;
    // ft_printf("->%p<-\n", &str);
    // new = NULL;
    // ft_printf("->%p<-\n", str);
    // ft_printf("->%p<-\n", new);
    // ft_printf("->%p<-\n", &test);

	// number = 730;
	// str = "Mais putain !!!!!";
	//ft_printf("MAX_INT = %d || MIN_INT = %d\n",INT_MAX, INT_MIN);

	// ft_printf("%.10s\n", str);
	// ft_printf("%+012.9d\n", number);
	// ft_printf("%+.9d\n", number);
	// ft_printf("%12.9d\n", number);
	// ft_printf("%+ 5d\n", number);
//    ft_printf("%#x\n", 2147483647);
//    ft_printf("%#X\n", 2147483647);
//    ft_printf("%o\n", number);
   ft_printf("%+14.8f\n", 23.12345678);
   printf ("%+14.8f\n", 23.12345678);
   
   // ft_printf("%.1f\n", 23.123456789);
   // ft_printf("%.2f\n", 23.123456789);
   // ft_printf("%.3f\n", 23.123456789);
   // ft_printf("%.4f\n", 23.123456789);
   // ft_printf("%.5f\n", 23.123456789);
   // ft_printf("%.6f\n", 23.123456789);
   // ft_printf("%.7f\n", 23.123456789);
   // ft_printf("%.8f\n", 23.123456789);
   // ft_printf("%.9f\n", 23.123456789);
   // ft_printf("%.10f\n", 23.123456789);
   // ft_printf("%.11f\n", 23.123456789);
   // ft_printf("%.12f\n", 23.123456789);
   // ft_printf("%.13f\n", 23.123456789);
/*
   printf("===========================\n");

   ft_printf("%4.0f\n", 23.123456789);
   ft_printf("%4.1f\n", 23.123456789);
   ft_printf("%4.2f\n", 23.123456789);
   ft_printf("%4.3f\n", 23.123456789);
   ft_printf("%4.4f\n", 23.123456789);
   ft_printf("%4.5f\n", 23.123456789);
   ft_printf("%4.6f\n", 23.123456789);
   ft_printf("%4.7f\n", 23.123456789);
   ft_printf("%4.8f\n", 23.123456789);
   ft_printf("%4.9f\n", 23.123456789);

   printf("===========================\n");

   ft_printf("%.f\n",0.5);
   ft_printf("%.f\n",0.7);
   ft_printf("%.f\n",1.0);
   ft_printf("%.f\n",1.5);
   ft_printf("%.f\n",1.7);
   ft_printf("%.f\n",2.0);
   ft_printf("%.f\n",2.5);
   ft_printf("%.f\n",2.7);
   ft_printf("%.f\n",3.0);
   ft_printf("%.f\n",3.5);
   ft_printf("%.f\n",3.7);

   printf("===========================\n");

   ft_printf("%.f\n",4.5);
   ft_printf("%.f\n",5.5);
   ft_printf("%.f\n",6.5);
   ft_printf("%.f\n",7.5);
   ft_printf("%.f\n",8.5);
   ft_printf("%.f\n",9.5);
*/
	return 0;
}

