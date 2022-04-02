/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:13:18 by briffard          #+#    #+#             */
/*   Updated: 2022/04/02 16:09:28 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include<limits.h>

int		main(void)
{

   
   // int i = 0;
   // int precision = 2;
   // int width = 10;
   // double arr1[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
   // double arr2[] = { 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09};
   // double arr3[] = { 0.25, 0.30, 0.35, 0.40, 0.45, 0.50, 4.5, 5.5, 6.5};
   // double arr4[] = { 9.99, 99.999, 999.9999, 99999.99999, 999999.9999999, 0.999999, 19.99, 29.99, 39.99};
   // double arr5[] = { 1.55555, 2.55555, 3.55555, 4.555555, 5.55555, 6.55555, 7.55555, 8.55555, 9.55555};
   // double arr6[] = { 564.2,798.564, 13.654684, 5684.321849, 897987456.654987, 321398.3216469, 3215698.3515984, 3218.516984, 654.654654};
   // double arr7[] = {0.00, -0.00, -0.25, -0.50, -0.5, -99.99, -10.0000, -684.56, -687.563};
   // unsigned int u_int_arr[] = { 4294967295, 254, 684, 987546, 664, 684123, 784655135, 321654};
   // unsigned int neg_u_int_arr[] = {-654, -321, -0, -56448, -56431, -8, -9, -010001000};

//    char  *arrSTR[] = {"", "     ", " Hello World", "\tTEst \r \n et le reste", "@!Test string"};

   // unsigned int x = -1;
   // unsigned int a = 0;
   // unsigned int b = 4294967295;
   // unsigned int c = 4294967296;
   // ft_printf("FT: ld ->%u<-\n", x);
   // printf("PR: ld ->%u<-\n", x);

   // unsigned char max = 255;
   // unsigned char min = 0;
   // unsigned char out = -1528;
   // unsigned char neg = -129;
   // unsigned char negOut= -528;//KO

   // unsigned short max = 65536;
   // unsigned short min = 0;
   // unsigned short out = -1528;
   // unsigned short neg = -129;
   // unsigned short negOut= -70528;//KO
/*18446744073709551615.00000;*/
//111111116854775808 5000000000000000             100000000000000000   3999999999999999
   // long double max = 9223372031.02000;
   // long double min = 6546546454565429646316464967295.3164643168464165546131988464134843164;
   
   float   test = 8764.1325;
   //int test = 736549;
   // unsigned int c = 4294967296;
   ft_printf("FT->%+020.10f<-\n", test);
   printf("PR->%+020.10f<-\n",test);
   // ft_printf("0   FT->%Lf<-\n",min);
   // printf("0   PR->%Lf<-\n",min);
   // ft_printf("neg -129 FT->%hhu<-\n",neg);
   // printf("neg -129 PR->%hhu<-\n",neg);
   // // ft_printf("4294967296->%u<-\n",c);
   // ft_printf("-528   FT->%hhu<-\n",negOut);
   // printf("--528  PR->%hhu<-\n",negOut);
   // ft_printf("528 FT->%hhu<-\n",out);
   // printf("528 PR->%hhu<-\n",out);

   // int i = 498;
   // while (i < 500)
   // {
   //    ft_printf("FT->%+*.*d<-\n",width,precision, i);
   //    printf("PR->%+*.*d<-\n",width,precision, i);
   //    i++;
   // }
   // int i = 0;
   // while (i < 127)
   //    {
   //       ft_printf("FT->%-12c<-\n",i);
   //       printf("PR->%-12c<-\n", i);
   //       i++;
   //    }
// printf ("==================================== ARR STRn");
// i = 0;
//    while(i < 5)
//    {
//       printf("\n============%s===============\n",arrSTR[i]);
//       ft_printf("FT_PRINTF -->%*.*s<--\n",width, precision, arrSTR[i]);
//       printf("PRINTF    -->%*.*s<--\n", width, precision, arrSTR[i]);
//       i++;
//    }

/*U_INT PRINTF*/
// printf ("==================================== U_int_arr\n");
//    while(i < 9)
//    {
//       printf("\n============%u===============\n",u_int_arr[i]);
//       ft_printf("FT_PRINTF -->%u<--\n",/*width, precision, */u_int_arr[i]);
//       printf("PRINTF    -->%u<--\n", /*width, precision,*/ u_int_arr[i]);
//       i++;
//    }

// printf ("==================================== neg_U int\n");
// i = 0;
//    while(i < 9)
//    {
//       printf("\n============%u===============\n",neg_u_int_arr[i]);
//       ft_printf("FT_PRINTF -->%u<--\n",/*width, precision, */neg_u_int_arr[i]);
//       printf("PRINTF    -->%u<--\n", /*width, precision,*/ neg_u_int_arr[i]);
//       i++;
//    }
   

   /*DOUBLE PRINT*/
// printf ("==================================== ARR1 Value de 0.1 a 0.9\n");
//    while(i < 9)
//    {
//       printf("\n============%f===============\n",arr1[i]);
//       ft_printf("FT_PRINTF -->%+*.*f<--\n",width, precision, arr1[i]);
//       printf("PRINTF    -->%+*.*f<--\n", width, precision, arr1[i]);
//       i++;
//    }
   
// printf ("==================================== ARR2 Value de 0.01 a 0.09\n");
// i = 0;
//       while(i < 9)
//    {
//       printf("\n=============%f==============\n", arr2[i]);
//       ft_printf("FT_PRINTF -->%.*f<--\n",width, precision, arr2[i]);
//       printf("PRINTF    -->%.*f<--\n", width, precision, arr2[i]);
//       printf("\n===========================\n");
//       i++;
//    }

// printf ("==================================== ARR3 Value de 0.25 en 0.25\n");
// i = 0;
//       while(i < 9)
//    {
//       printf("\n===========%f================\n", arr3[i]);
//       ft_printf("FT_PRINTF -->%.*f<--\n",width, precision, arr3[i]);
//       printf("PRINTF    -->%.*f<--\n", width, precision, arr3[i]);
//       printf("\n===========================\n");
//       i++;
//    }

//    printf ("==================================== ARR4 Value de 9.99 \n");
// i = 0;
//       while(i < 9)
//    {
//       printf("\n=============%f==============\n", arr4[i]);
//       ft_printf("FT_PRINTF -->%.*f<--\n",width, precision, arr4[i]);
//       printf("PRINTF    -->%.*f<--\n", width, precision, arr4[i]);
//       printf("\n===========================\n");
//       i++;
//    }

//       printf ("==================================== ARR5 Value de 1.5555 ++ \n"); // reprendre test ici
//    i = 0;
//       while(i < 9)
//    {
//       printf("\n=============%f==============\n",arr5[i]);
//       ft_printf("FT_PRINTF -->%.*f<--\n",width, precision, arr5[i]);
//       printf("PRINTF    -->%.*f<--\n", width, precision, arr5[i]);
//       printf("\n===========================\n");
//       i++;
//    }

   //       printf ("========================================= ARR6 Value random \n");
   // i = 0;
   //    while(i < 9)
   // {
   //    printf("\n=============%f==============\n",arr6[i]);
   //    ft_printf("FT_PRINTF -->%*.*f<--\n",width, precision, arr6[i]);
   //    printf("PRINTF    -->%*.*f<--\n", width, precision, arr6[i]);
   //    printf("\n===========================\n");
   //    i++;
   // }
   //          printf ("ARR6 Value negatif\n");
   // i = 0;
   //    while(i < 9)
   // {
   //    printf("\n=============%f==============\n",arr7[i]);
   //    ft_printf("FT_PRINTF -->%*.*f<--\n",width, precision, arr7[i]);
   //    printf("PRINTF    -->%*.*f<--\n", width, precision, arr7[i]);
   //    printf("\n===========================\n");
   //    i++;
   // }
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
//    printf("\n============0.55===============\n");
//    printf("COMPARE ->%.f<-\n", 0.55);
//    ft_printf("ft_PRINTF ->%.f<-\n", 0.55);
//     printf("\n===========0.57================\n");
//      printf("COMPARE ->%.f<-\n", 0.57);
//    ft_printf("ft_PRINTF ->%.f<-\n", 0.57);
//     printf("\n============0.60===============\n");
//      printf("COMPARE ->%.f<-\n", 0.60);
//    ft_printf("ft_PRINTF ->%.f<-\n", 0.60);
//     printf("\n============6.05===============\n");
//   printf("%.30f' and text\n",  6.05);
//    ft_printf("COMPARE ->%.30f<-\n", 6.05);
//    printf("\n=============0.35==============\n");
//    ft_printf("COMPARE ->%.1f<-\n", 0.35);
//    printf("PRINTF ->%.1f<-\n", 0.35);
//     printf("\n===========0.05 ================\n");
//     printf("PRINTF '%.1f'\n", 0.05);
//  ft_printf("COMPARE '%.1f'\n", 0.05);
//  printf("\n=============1.5==============\n");
//     printf("PRINTF'%.f'\n", 1.5);
//  ft_printf("COMPARE '%.f'\n", 1.5);
//  printf("\n============0.25===============\n");
//     printf("PRINTF '%.1f'\n", 0.25);
//  ft_printf("COMPARE '%.1f'\n", 0.25);
//  printf("\n============0.35===============\n");
//     printf("PRINTF '%.1f'\n", 0.35);
//  ft_printf("COMPARE '%.1f'\n", 0.35);

//              printf("\n -->0.45\n"); // 0.5
//     printf("PRINTF '%.1f' and text\n", 0.45);
//  ft_printf("COMPARE'%.1f' and text\n", 0.45);

//              printf("\n\n"); // 0.6
//     printf("PRINTF  '%.1f' and text\n", 0.55);
//  ft_printf("COMPARE '%.1f' and text\n", 0.55);

//              printf("\n\n"); // 0.7
//     printf("PRINTF  '%.1f' and text\n", 0.65);
//  ft_printf("COMPARE '%.1f' and text\n", 0.65);

 
   // ft_printf("Precision 2 Ft     -->%.2f\n", 23.123456789);
   // printf("Precision 2        -->%.2f\n", 23.123456789);
   // ft_printf("Precision 3 Ft     -->%.3f\n", 23.123456789);
   // printf("Precision 3        -->%.3f\n", 23.123456789);
   // ft_printf("Precison 4 Ft      -->%.4f\n", 23.123456789);
   // printf("Precison 4         -->%.4f\n", 23.123456789);
   // ft_printf("Precision 5 Ft     -->%.5f\n", 23.1234556789);
   // printf("Precision 5        -->%.5f\n", 23.1234556789);
   // ft_printf("Precision 6 Ft     -->%.6f\n", 23.123456789);
   // printf("Precision 6        -->%.6f\n", 23.123456789);
   // ft_printf("Precision 7 Ft     -->%.7f\n", 23.123456789);
   // printf("Precision 7        -->%.7f\n", 23.123456789);
   // ft_printf("Precsion 8 Ft      -->%.8f\n", 23.123456789);
   // printf("Precsion 8         -->%.8f\n", 23.123456789);
   // ft_printf("Precision 9 Ft     -->%.9f\n", 23.123456789);
   // printf("Precision 9        -->%.9f\n", 23.123456789);
   // ft_printf("Precsion 10 Ft     -->%.10f\n", 23.123456789);
   // printf("Precsion 10        -->%.10f\n", 23.123456789);
   // ft_printf("Precsion 11 Ft     -->%.11f\n", 23.123456789);
   // printf("Precsion 11        -->%.11f\n", 23.123456789);
   // ft_printf("Precsion 12 Ft     -->%.12f\n", 23.123456789);
   // printf("Precsion 12        -->%.12f\n", 23.123456789);
   // ft_printf("Precsion 13 Ft     -->%.13f\n", 23.123456789);
   // printf("Precsion 13        -->%.13f\n", 23.123456789);

   // printf("\n=======23.123456789====================\n");

   // ft_printf("FT_printf       --->%4.0f\n", 23.123456789);
   // printf("Printf          --->%4.0f\n", 23.123456789);

   //    printf("\n===========================\n");

   // ft_printf("FT_printf       --->%4.1f\n", 23.123456789);
   // printf("Printf          --->%4.1f\n", 23.123456789);

   // printf("\n===========================\n");

   // ft_printf("FT_printf       --->%4.2f\n", 23.123456789);
   // printf("Printf          --->%4.2f\n", 23.123456789);

   // printf("\n===========================\n");

   // ft_printf("FT_printf       --->%4.3f\n", 23.123456789);
   // printf("Printf          --->%4.3f\n", 23.123456789);
   // printf("\n===========================\n");
   // ft_printf("FT_printf       --->%4.4f\n", 23.123456789);
   // printf("Printf          --->%4.4f\n", 23.123456789);
   // printf("\n===========================\n");
   // ft_printf("FT_printf       --->%4.5f\n", 23.123456789);
   // printf("Printf          --->%4.5f\n", 23.123456789);
   // printf("\n===========================\n");
   // ft_printf("FT_printf       --->%4.6f\n", 23.123456789);
   // printf("Printf          --->%4.6f\n", 23.123456789);

   // printf("======0.5=====================\n");

   // ft_printf("FT        --->%.f\n",0.5);
   // printf("PRINTF    --->%.f\n",0.5);
   //   printf("======0.3=====================\n");

   // ft_printf("FT        --->%.f\n",0.3);
   // printf("PRINTF    --->%.f\n",0.3);
   // printf("\n==============0.7=============\n");
   // ft_printf("FT        --->%.f\n",0.7);
   // printf("PRINTF    --->%.f\n",0.7);
   // printf("\n=============1.0==============\n");
   // ft_printf("FT        --->%.f\n",1.0);
   // printf("PRINTF    --->%.f\n",1.0);
   // printf("\n===========================\n");
   // ft_printf("FT        --->%.f\n",1.5);
   // printf("PRINTF    --->%.f\n",1.5);
   // printf("\n===========================\n");
   // ft_printf("FT        --->%.f\n",1.7);
   // printf("PRINTF    --->%.f\n",1.7);
   // printf("\n===========================\n");
   // ft_printf("FT        --->%.f\n",2.0);
   // printf("PRINTF    --->%.f\n",2.0);
   // printf("\n===========================\n");
   // ft_printf("FT        --->%.f\n",2.5);
   // printf("PRINTF    --->%.f\n",2.5);
   // printf("\n============2.7===============\n");
   // ft_printf("FT        --->%.f\n",2.7);
   // printf("PRINTF    --->%.f\n",2.7);
   // printf("\n===========3.0================\n");
   // ft_printf("FT        --->%.f\n",3.0);
   // printf("PRINTF    --->%.f\n",3.0);
   // printf("\n===========================\n");
   // // ft_printf("FT        --->%.f\n",3.5);
   // printf("PRINTF    --->%.f\n",3.5);
   // printf("\n===========================\n");
   // ft_printf("FT        --->%.f\n",3.7);
   // printf("PRINTF    --->%.f\n",3.7);

   // printf("===========================\n");

	return 0;
}

