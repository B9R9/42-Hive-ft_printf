/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:13:18 by briffard          #+#    #+#             */
/*   Updated: 2022/03/24 16:54:33 by briffard         ###   ########.fr       */
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
   // ft_printf("%#x\n", 2147483647);
   // ft_printf("%#X\n", 2147483647);
//    ft_printf("%o\n", number);
   // ft_printf("FT      ->%+14.8f<-\n", 23.123456789);

   //-0.02 // probleme itoa
  // fixe le rouding negatif
//    ft_printf("null '%.30f' and text\n",  0.65000000000000002220446049);
   printf("===========================\n");
   ft_printf("COMPARE ->%.5f<-\n", 10.35654);
   printf("PRINTF ->%.5f<-\n", 10.35654);
    printf("===========================\n");
  printf("%.30f' and text\n",  6.05);
   ft_printf("COMPARE ->%.30f<-\n", 6.05);
   printf("===========================\n");
   ft_printf("COMPARE ->%.1f<-\n", 0.35);
   printf("PRINTF ->%.1f<-\n", 0.35);
    printf("===========================\n");
    printf("PRINTF '%.1f'\n", 0.05);
 ft_printf("COMPARE '%.1f'\n", 0.05);
 printf("===========================\n");
//                 printf("\n\n"); // 0.1
    printf("PRINTF'%.1f'\n", 0.15);
 ft_printf("COMPARE '%.1f'\n", 0.15);
 printf("===========================\n");
//                 printf("\n\n"); // 0.2
    printf("PRINTF '%.1f'\n", 0.25);
 ft_printf("COMPARE '%.1f'\n", 0.25);
 printf("===========================\n");
//                 printf("\n\n"); // 0.3
    printf("PRINTF '%.1f'\n", 0.35);
 ft_printf("COMPARE '%.1f'\n", 0.35);

//              printf("\n\n"); // 0.5
//     printf("null '%.1f' and text\n", 0.45);
//  ft_printf("null '%.1f' and text\n", 0.45);

//              printf("\n\n"); // 0.6
//     printf("null '%.1f' and text\n", 0.55);
//  ft_printf("null '%.1f' and text\n", 0.55);

//              printf("\n\n"); // 0.7
//     printf("null '%.1f' and text\n", 0.65);
//  ft_printf("null '%.1f' and text\n", 0.65);
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

