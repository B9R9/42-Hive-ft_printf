/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:30:51 by briffard          #+#    #+#             */
/*   Updated: 2022/05/03 15:48:32 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <limits.h>

int main(void)
{
    // char *test_atoi = "abfbd";
    // int ret = ft_atoi(test_atoi);
    // printf("%d\n", ret);
    printf("================SPECIFIC II ================\n");
    int nb = 42;
    
    printf("------\n");
    ft_printf("FT->Test %\n");
    // printf("PF->Test %\n");
    printf("------\n");
    ft_printf("FT->Test %#.f %#.0f %#.15Lf\n",0 , 0, 0.15545);
    printf("PF->Test %#.f %#.0f %#.15Lf\n",0, 0, 0.15545);
    printf("------\n");
    ft_printf("FT->Test %-5.0o\n",0);
    printf("PF->Test %-5.0o\n",0);
    printf("------\n");
    ft_printf("FT->Test %-5.o\n",0);
    printf("PF->Test %-5.o\n",0);
    printf("------\n");
    ft_printf("FT->Testing %hhd\n",-128);
    printf("PF->Testing %hhd\n",-128);
    printf("------\n");
    ft_printf("FT->Testing %hd\n",-128);
    printf("PF->Testing %hd\n",-128);
    printf("------\n");
    ft_printf("FT->Testing %hd\n",-32768);
    printf("PF->Testing %hd\n",-32768);
    printf("------\n");
    ft_printf("FT->Test %.2f\n",-1.500000);
    printf("PF->Test %.2f\n",-1.500000);
    printf("------\n");
    ft_printf("FT->Test %.2f\n",-958.125000);
    printf("PF->Test %.2f\n",-958.125000);
    printf("------\n");
    ft_printf("FT->Test %10.f:\n",0.011719);
    printf("PF->Test %10.f:\n",0.011719);
    printf("------\n");
    ft_printf("FT->Test %010f\n",3.141593);
    printf("PF->Test %010f\n", 3.141593);
    printf("------\n");
    ft_printf("FT->Test %010f\n", 0.011719);
    printf("PF->Test %010f\n", 0.011719);
    printf("------\n");
    ft_printf("FT->Test %%.0f: {%.0f}\n", 3.141593);
    printf("PF->Test %%.0f: {%.0f}\n", 3.141593);
    printf("------\n");
    ft_printf("FT->Test %%.0f: {%.0f}\n", -2.500000);
    printf("PF->Test %%.0f: {%.0f}\n", -2.500000);
    printf("------\n");
    ft_printf("FT->Test %%#-1.0u: {%#-1.0u}\n", 0);
    printf("PF->Test %%#-1.0u: {%#-1.0u}\n", 0);
    printf("------\n");
    ft_printf("FT->Test %%#-1.0o: {%#-1.0o}\n", 0);
    printf("PF->Test %%#-1.0o: {%#-1.0o}\n", 0);
    printf("------\n");
    ft_printf("FT->Test 05.*d negative {%05.*d}\n", -15, 42);
    printf("PF->Test 05.*d negative {%05.*d}\n", -15, 42);
    printf("------\n");
    ft_printf("FT->Test *3d positive {%*3d}\n", 5, 0);
    printf("PF->Test *3d positive {%*3d}\n", 5, 0);
    printf("------\n");
    ft_printf("FT->%*.*d\n", 0, 3, 0);
    printf("PF->%*.*d\n", 0, 3, 0);
    printf("------\n");
    ft_printf("FT->Test .*s negative {%.*s}\n", -5, "42");
    printf("PF->Test .*s negative {%.*s}\n", -5, "42");
    printf("------\n");
    ft_printf("FT->Test 5p: {%5p}\n", 0);
    printf("PF->Test 5p: {%5p}\n", 0);
    printf("------\n");
    ft_printf("FT->%10.0f\n", 42.42);
    printf("PF->%10.0f\n", 42.42);
    printf("------\n");
    ft_printf("FT->%.0p, %.p\n", 0, 0);
    printf("PF->%.0p, %.p\n", 0, 0);
    printf("------\n");
    ft_printf("FT->@moulitest: %.10hd\n", -42);
    printf("PF->@moulitest: %.10hd\n", -42);
    printf("------\n");
    ft_printf("FT->@moulitest #hhd #.hhd: >%#hhd %#.hhd<\n", 0, 0);
    printf("PF->@moulitest #hhd #.hhd: >%#hhd %#.hhd<\n", 0, 0);
    printf("------\n");
    ft_printf("FT->Test .hhd: %.hhd\n", 42);// NO LEAKS
    printf("PF->Test .hhd: %.hhd\n", 42);
    printf("------\n");
    ft_printf("FT->Test .s: %.s\n", "Hello");// NO LEAKS
    printf("PF->Test .s: %.s\n", "Hello");
    printf("------\n");
    ft_printf("FT->@moulitest: >%5.o %5.0o<\n", 0, 0);// NO LEAKS
    printf("PF->@moulitest: >%5.o %5.0o<\n", 0, 0);
    printf("------\n");
    printf("PF->hey '% .1f'\n", 0.00);
    ft_printf("FT->hey '% .1f'\n", 0.00);
    printf("------\n");
    printf("PF->testtt '% .5d'\n", nb);
    ft_printf("FT->testtt '% .5d'\n", nb);
    printf("------\n");
    printf("PF->test '%0 f'\n", 3.14159265);   
    ft_printf("FT->test '%0 f'\n", 3.14159265); 
    printf("------\n");
    printf("PF ->test: ->% d<-\n", -42);
    ft_printf("FT ->test: ->% d<-\n", -42);

    printf("------\n");
    ft_printf("Test #08d: %#08d\n", 42);
    printf("Test #08d: %#08d\n", 42);
    printf("------\n");
    ft_printf("Test #08.1x: %#08.1x\n", 42);
    printf("Test #08.1x: %#08.1x\n", 42);
    printf("------\n");
    ft_printf("Test #08.2x: %#08.2x\n", 42);
    printf("Test #08.2x: %#08.2x\n", 42);
    printf("------\n");
    ft_printf("Test #08.3x: %#010.3x\n", 42);
    printf("Test #08.3x: %#010.3x\n", 42);
    printf("------\n");
    ft_printf("Test #08.5x: %#010.5x\n", 42);
    printf("Test #08.5x: %#010.5x\n", 42);
    printf("------\n");
    ft_printf("Test 03i: %03i\n", 0);
    printf("Test 03i: %03i\n", 0);
    printf("------\n");
    ft_printf("Test #8d: %#8d\n", 42);
    printf("Test #8d: %#8d\n", 42);
    printf("------\n");
    ft_printf("%03.1d\n", 0);
    printf("%03.1d\n", 0);
    printf("------\n");
    printf("PF ->test: % d\n", -42);
    ft_printf("FT ->test: % d\n", -42);
    printf("------\n");
    printf("PF->f conversion: %f\n", 2.5555565f);
    ft_printf("FT->f conversion: %f\n", 2.5555565f);
    printf("------\n");
    printf("PF->f conversion: %f\n", 2.5555515f);
    ft_printf("FT->f conversion: %f\n", 2.5555515f);
    printf("------\n");
    printf("PF*>f conversion: %f\n", 2.5555505f);
    ft_printf("FT*>f conversion: %f\n", 2.5555505f);
    printf("------\n");
	printf("PF->lalala '%.1f'\n", 5.95); 
    ft_printf("FT->lalala '%.1f'\n", 5.95);

    printf("------\n");
    printf("PF-># test '%#.f'\n", 5.9);
    ft_printf("FT-># test '%#.f'\n", 5.9);
    printf("------\n");
    printf("PF->oihkugjtest '%.2f'\n", (double)0.005);
    ft_printf("FT->oihkugjtest '%.2f'\n", (double)0.005);
    printf("------\n");
    printf("PF->test with 0 '%0 10d'\n", 3);    //  -> 000000003<-
    ft_printf("FT->test with 0 '%0 10d'\n", 3); //  -> 000000003<-
    printf("------\n");
    printf("PF->test '%0 f'\n", 3.14159265);    //  ->03.141593<-
    ft_printf("FT->test '%0 f'\n", 3.14159265); //  ->03.141593<-
    printf("------\n");
    printf("PF->test '%0 10f'\n", 3.14159265);      //  -> 03.141593<-
    ft_printf("FT->test '%0 10f'\n", 3.14159265);   //  -> 03.141593<-
    printf("------\n");
    printf("PF->test '%0+25f'\n", 3.14159265);       // ->+00000000000000003.141593<-
    ft_printf("FT->test '%0+25f'\n", 3.14159265);   //  ->+00000000000000003.141593<-
    printf("------\n");
    printf("PF->test '%0 10f'\n", -3.14159265);          //  ->-03.141593<-
    ft_printf("FT->test '%0 10f'\n", -3.14159265);      //  ->-03.141593<-
    printf("------\n");
    printf("PF->test '%010.1f'\n", -3.14159265);        // ->-0000003.1<-
    ft_printf("FT->test '%010.1f'\n", -3.14159265);    //  ->-0000003.1<-
    printf("------\n");
    printf("PF->test '%010.1f'\n", 3.14159265); //      ->00000003.1<-
    ft_printf("FT->test '%010.1f'\n", 3.14159265); //   ->00000003.1<-
    printf("------\n");
    ft_printf("FT->%#015.10X<\n", 4561258);// NO LEAKS
    printf("PF->%#015.10X<\n", 4561258 );
    printf("------\n");
    ft_printf("FT->%#015.10X<\n", 4561258);// NO LEAKS
    printf("PF->%#015.10X<\n", 4561258 );
    printf("------\n");
    ft_printf("FT->%015.10X<\n", 4561258);// NO LEAKS
    printf("PF->%015.10X<\n", 4561258 );
    printf("------\n");
    ft_printf("FT->%015.10d<\n", 73);
    printf("PF->%015.10d<\n", 73);
    printf("------\n");
    ft_printf("FT->%015.10X<\n", 73);
    printf("PF->%015.10X<\n", 73);
    printf("------\n");
   printf("PF->null '%+f' and text\n", -0.0);
ft_printf("FT->null '%+f' and text\n", -0.0);
    printf("------\n");
   printf("PF->null '%f' and text\n", -0.0);
ft_printf("FT->null '%f' and text\n", -0.0);
    printf("------\n");
   printf("PF->null '%#.0f' and text\n", -99.5);
ft_printf("FT->null '%#.0f' and text\n", -99.5);
    printf("------\n");
   printf("PF->hey '% .1f'\n", 0.00);
ft_printf("FT->hey '% .1f'\n", 0.00);
    printf("------\n");
   printf("PF->testtt '% .5d'\n", nb);
   ft_printf("FT->testtt '% .5d'\n", nb);
    printf("------\n");
   printf("PF->test test '%#10.5o'\n", 9);   // ->    00011<-   
   ft_printf("FT->test test '%#10.5o'\n", 9);// ->    00011<-
    printf("------\n");
   printf("PF->hey '%#o'\n", 0);
   ft_printf("FT->hey '%#o'\n", 0);
    printf("------\n");
   printf("PF->tessssttt '%#08.4o'\n", 42);     // ->   0052<-
   ft_printf("FT->tessssttt '%#08.4o'\n", 42);  // ->   0052<-
    printf("------\n");
    ft_printf("FT->%#6o<\n", 2500);     // -> 04704<-
    printf("PF->%#6o<\n", 2500);        // -> 04704<-
    printf("------\n");
   printf("PF->tessssttt '%#08.o'\n", 42);      // ->     052<-
   ft_printf("FT->tessssttt '%#08.o'\n", 42);   // ->00000052<-
    printf("------\n");
    ft_printf("FT->@moulitest: %5.o %5.0o<\n", 0, 0);// NO LEAKS
    printf("PF->@moulitest: %5.o %5.0o<\n", 0, 0);
    printf("------\n");
    ft_printf("FT->%-+o<\n", 73);
    printf("PT->%-+o<\n", 73);
    printf("------\n");
    ft_printf("FT->%+o<\n", 2073U);
    printf("PF->%+o<\n", 2073U);

//     printf("================SPECIFIC================\n");
//     // ft_printf("FT ->%#x<-\n", 0); // NO LEAKS
//     // printf("PF ->%#x<-\n", 0);// NO LEAKS//   
      long int long_int = 9999999999;
    long long int   ll_int = 999999999999999999LL;
    unsigned int u_int = 21;
    unsigned long int ul_int = 123456789123456UL;
    unsigned long long ull_int = 12345678912345456653ULL;
    // unsigned long int ul_int = 123456789123456UL;
//     ft_printf("FT->%llo<\n", ull_int);
//     printf("PF->%llo<\n", ull_int);
//     printf("------\n");
//     ft_printf("FT->%lo<\n", ull_int);
//     printf("PF->%lo<\n", ull_int);
//     printf("------\n");
//     ft_printf("FT->%.30Lf<\n", -42.420);
//     printf("PF->%.30Lf<\n", -42.420);
//     printf("------\n");
//     ft_printf("FT->%f<\n", -42.420000);
//     printf("PF->%f<\n", -42.420000);
//     printf("------\n");
//     ft_printf("FT->%lf<\n", -42.420000);
//     printf("PF->%lf<\n", -42.420000);
//     printf("------\n");
//     ft_printf("FT->%lo<\n", ul_int);
//     printf("PF->%lo<\n", ul_int);
//     printf("------\n");
//     ft_printf("FT->%lo<\n", __INT_MAX__);
//     printf("PF->%lo<\n", __INT_MAX__);
//     printf("------\n");
//     ft_printf("FT->%llo<\n", __INT_MAX__);
//     printf("PF->%llo<\n", __INT_MAX__);
//     printf("------\n");
//     ft_printf("FT->%.f<\n", 0.005);// 0
//     printf("PF->%.f<\n", 0.005); // 0
//     printf("------\n");
//     ft_printf("FT->%.0f<\n", 0.05); //0
//     printf("PF->%.0f<\n", 0.05);//0
//     printf("------\n");
//     ft_printf("FT->%.0f<\n", 0.55); // 0
//     printf("PF->%.0f<\n", 0.55); // 1
//     printf("------\n");
//     ft_printf("FT->%.0f<\n", 0.51); // 0
//     printf("PF->%.0f<\n", 0.51); // 1
//     printf("------\n");
//     ft_printf("FT->%.0f<\n", 0.50); // 0
//     printf("PF->%.0f<\n", 0.50); // 0
//     printf("------\n");
//     ft_printf("FT->%.0f<\n", 0.49); //0
//     printf("PF->%.0f<\n", 0.49);// 0
//     printf("------\n");
//     ft_printf("FT->%.0f<\n", 0.45); // 0
//     printf("PF->%.0f<\n", 0.45); // 0
//     printf("------\n");
//     ft_printf("FT->%.0f<\n", 0.65);// 1
//     printf("PF->%.0f<\n", 0.65); // 1
//     printf("------\n");
//     ft_printf("FT->%.f<\n", 1.05252);// 1
//     printf("PF->%.f<\n",1.05252); // 1
//     printf("------\n");
//     ft_printf("FT->%.f<\n", 1.5252); // 2
//     printf("PF->%.f<\n",1.5252); // 2
//     printf("------\n");
//     ft_printf("FT->%.1f<\n", 0.05252);//0.0
//     printf("PF->%.1f<\n",0.05252); //0.1
//     printf("------\n");
//     ft_printf("FT->%.1f<\n", 0.04252);//0.0
//     printf("PF->%.1f<\n",0.04252); //0.1
//     printf("------\n");
//     ft_printf("FT->%.1f<\n", 0.06252);//0.1
//     printf("PF->%.1f<\n",0.06252); //0.1
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.30);//0.3
//     printf("PF->%.1f<-\n", 0.30);//0.3
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.95);//0.9
//     printf("PF->%.1f<-\n", 0.95);// 0.9
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.96);//0.9
//     printf("PF->%.1f<-\n", 0.96);// 0.9
//     printf("------\n");
//     ft_printf("FT->%.f<-\n", 0.95);//1
//     printf("PF->%.f<-\n", 0.95);// 1
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.25532);//1
//     printf("PF->%.1f<-\n", 0.25532);// 1

    

    
    printf("================STR================\n");
    char    *name;
    char    *test_null;

    test_null = NULL;
    name = "joe l' indien";

    ft_printf("FT ->%.2s is a string<-\n", ""); // NO LEAKS
    printf("PF ->%.2s is a string<-\n", "");// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%5.2s is a string<-\n", ""); // NO LEAKS
    printf("PF ->%5.2s is a string<-\n", ""); // NO LEAKS
    printf("------\n");
    ft_printf("FT ->%-.2s is a string<-\n", "");// NO LEAKS
    printf("PF ->%-.2s is a string<-\n", "");// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%-5.2s is a string<-\n", ""); // NO LEAKS
    printf("PF ->%-5.2s is a string<-\n", ""); // NO LEAKS
    printf("------\n");
    ft_printf("FT ->%s<-\n", name); // NO LEAKS
    printf("PF ->%s<-\n", name); // NO LEAKS
    printf("------\n");
    /*AT home 0 Turn to space*/
    ft_printf("FT ->%030s<-\n", name);// NO LEAKS
    printf("PF ->%030s<-\n", name);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->% 30s<-\n", name);// NO LEAKS
    printf("PF ->% 30s<-\n", name);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%- 30s<-\n", name);// NO LEAKS
    printf("PF ->%- 30s<-\n", name);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%+ 30s<-\n", name);// NO LEAKS
    printf("PF ->%+ 30s<-\n", name);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%# 30s<-\n", name);// NO LEAKS
    printf("PF ->%# 30s<-\n", name);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%# 30.10s<-\n", name);// NO LEAKS
    printf("PF ->%# 30.10s<-\n", name);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%.10s<-\n", name);// NO LEAKS
    printf("PF ->%.10s<-\n", name);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%30.10s<-\n", name);// NO LEAKS
    printf("PF ->%30.10s<-\n", name);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%-30.10s<-\n", name);// NO LEAKS
    printf("PF ->%-30.10s<-\n", name); // NO LEAKS
    printf("------\n");
    ft_printf("FT ->%s<-\n", test_null);// NO LEAKS
    printf("PF ->%s<-\n", test_null);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%s<-\n", "\0");// NO LEAKS
    printf("PF ->%s<-\n", "\0");// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%s<-\n", "");// NO LEAKS
    printf("PF ->%s<-\n", "");// NO LEAKS
    printf("================%%================\n");
    printf("------\n");
    ft_printf("FT ->%%<-\n");// NO LEAKS
    printf("PF ->%%<-\n");// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%5%<-\n"); // return UBUNTU ->    %<- MAC OK // NO LEAKS
    printf("PF ->%5%<-\n");// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%-5%<-\n"); // return UBUNTU ->%    <- MAC OK // NO LEAKS
    printf("PF ->%-5%<-\n");// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%.0%<-\n");// NO LEAKS
    printf("PF ->%.0%<-\n");// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%%<-\n", "test");// NO LEAKS
    printf("PF ->%%<-\n", "test");// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%%<-\n", "t");// NO LEAKS
    printf("PF ->%%<-\n", "t");// NO LEAKS


    printf("================CHAR================\n");
    char c = 'a';
    char n = NULL;
    printf("------\n");
    ft_printf("FT ->%c<-\n", n);// NO LEAKS
    printf("PF ->%c<-\n", n);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%c<-\n", c);// NO LEAKS
    printf("PF ->%c<-\n", c);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%+c<-\n", c);// NO LEAKS
    printf("PF ->%+c<-\n", c);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%#c<-\n", c);// NO LEAKS
    printf("PF ->%#c<-\n", c);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%-c<-\n", c);// NO LEAKS
    printf("PF ->%-c<-\n", c);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%.12c<-\n", c);// NO LEAKS
    printf("PF ->%.12c<-\n", c);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%05c<-\n", c); // RET UN->0000a<- MAC OK// NO LEAKS
    printf("PF ->%05c<-\n", c);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->% 5c<-\n", c);// NO LEAKS
    printf("PF ->% 5c<-\n", c);// NO LEAKS
    printf("------\n");
    ft_printf("FT ->%- 5c<-\n", c);// NO LEAKS
    printf("PF ->%- 5c<-\n", c);// NO LEAKS
    printf("------\n");



//     printf("================INT================\n");
//     int max = __INT_MAX__;
//     int min = -2147483647;
//     int randonm = 73;
//     int pre    = 10;
//     int width       = 0;
//     printf("------\n");
//     ft_printf("FT->% d<\n", 42);// NO LEAKS
//     printf("PF->% d<\n", 42);// NO LEAKS
//     printf("------\n");
//     ft_printf("FT->%+d<\n", 42);// NO LEAKS
//     printf("PF->%+d<\n", 42);// NO LEAKS
//     printf("------\n");
//     ft_printf("FT->% d<\n", -42);// NO LEAKS
//     printf("PF->% d<\n", -42);// NO LEAKS
//     printf("------\n");
//     ft_printf("FT->%+d<\n", -42);// NO LEAKS
//     printf("PF->%+d<\n", -42);// NO LEAKS
//     printf("------\n");
//     ft_printf("FT->%+d<\n", 0);// NO LEAKS
//     printf("PF->%+d<\n", 0);// NO LEAKS
//     printf("------\n");
//      ft_printf("FT->%+ d<\n", 42);// NO LEAKS
//     printf("PF->%+ d<\n", 42);// NO LEAKS
//     printf("------\n");
// //     // ft_printf("FT->%+lld<\n", 4242424242424242424242); // ne compil pas
// //     // printf("PF->%+lld<\n",4242424242424242424242);// ne compil pas
//     printf("------\n");
//     ft_printf("FT->%d<\n", max);// NO LEAKS
//     printf("PF->%d<\n", max);// NO LEAKS
//     printf("------\n");
//     ft_printf("FT->%d<\n", min);// NO LEAKS
//     printf("PF->%d<\n", min);// NO LEAKS
//     printf("------\n");
//     ft_printf("FT->%d<\n", randonm);// NO LEAKS
//     printf("PF->%d<\n", randonm);// NO LEAKS
//     printf("------\n");
//     ft_printf("FT->%+015d<\n", randonm);// NO LEAKS
//     printf("PF->%+015d<\n", randonm);// NO LEAKS
//     printf("---FAIL---\n");
//     ft_printf("FT->%+ 15d<\n", randonm);// NO LEAKS
//     printf("PF->%+ 15d<\n", randonm);// NO LEAKS
//     printf("------\n");
//     ft_printf("FT->%- 15d<\n", randonm);// NO LEAKS
//     printf("PF->%- 15d<\n", randonm);// NO LEAKS
//     printf("------------------------\n");
//     ft_printf("FT->%-15d<\n", randonm);// NO LEAKS
//     printf("PF->%-15d<\n", randonm);// NO LEAKS
//     printf("------\n");
//     ft_printf("FT->%-015d<\n", randonm);
//     printf("PF->%-015d<\n", randonm);
//     printf("------\n");
//     ft_printf("FT->%015.10d<\n", randonm);
//     printf("PF->%015.10d<\n", randonm);
//     printf("------\n");
//     ft_printf("FT->%015.10X<\n", randonm);
//     printf("PF->%015.10X<\n", randonm);
//     printf("------\n");
//     ft_printf("FT->%-+015.10d<\n", randonm);
//     printf("PF->%-+015.10d<\n", randonm);

//     /*PRECSION ++*/// NO LEAKS
//     while (width <= 20)
//     {
//         printf("------\n");
//         printf("Width = %d || pre = %d\n", width, pre);
//         ft_printf("FT->%*.*d<\n",width, pre, randonm);
//         printf("PF->%*.*d<\n",width, pre, randonm);
//         width++;
//         pre--;
//     }
    
    printf("================HEX&OCT&UINT================\n");
    printf("------\n");
    ft_printf("FT->%#6o<\n", 2500);
    printf("PF->%#6o<\n", 2500);
    printf("------\n");
    ft_printf("FT->%-5.10o<\n", 2500);
    printf("PF->%-5.10o<\n", 2500);
    printf("------\n");
    ft_printf("FT->%llo<\n", ull_int);
    printf("PF->%llo<\n", ull_int);
    printf("------\n");
    ft_printf("FT->%lo<\n", ull_int);
    printf("PF->%lo<\n", ull_int);
    printf("------\n");
    ft_printf("FT->%lo<\n", ul_int);
    printf("PF->%lo<\n", ul_int);
    printf("------\n");
    ft_printf("FT->%ho<\n", 2500);
    printf("PF->%ho<\n", 2500);
    printf("------\n");
    ft_printf("FT->%hho<\n", 2500);
    printf("PF->%hho<\n", 2500);
    printf("------\n");
    ft_printf("FT->@moulitest: %.o %.0o<\n", 0, 0);// NO LEAKS
    printf("PF->@moulitest: %.o %.0o<\n", 0, 0);
    printf("------\n");
    ft_printf("FT->@moulitest: %5.o %5.0o<\n", 0, 0);// NO LEAKS
    printf("PF->@moulitest: %5.o %5.0o<\n", 0, 0);
    printf("------\n");
    ft_printf("FT->%#x<\n", 0); // LEAKS
    printf("PF->%#x<\n", 0); // LEAKS
    printf("------\n");
    ft_printf("FT->@moulitest: %#.x %#.0x<\n", 0, 0);// // NO LEAKS
    printf("PF->@moulitest: %#.x %#.0x<\n", 0, 0);//// NO LEAKS
    printf("------\n");
    ft_printf("FT->@moulitest: %5.x %5.0x<\n", 0, 0);// NO LEAKS
    printf("PF->@moulitest: %5.x %5.0x<\n", 0, 0);// NO LEAKS
    printf("------\n");
    ft_printf("FT->%u<\n", u_int);// NO LEAKS
    printf("PF->%u<\n", u_int);// NO LEAKS
    printf("------\n");
    ft_printf("FT->%u<\n", u_int);// NO LEAKS
    printf("PF->%u<\n", u_int);// NO LEAKS
    printf("------\n");
    ft_printf("FT->%#u<\n", u_int);// NO LEAKS
    printf("PF->%#u<\n", u_int);// NO LEAKS
    printf("------\n");
    ft_printf("FT->%#d<\n", u_int);// NO LEAKS
    printf("PF->%#d<\n", u_int);
    printf("------\n");
    ft_printf("FT->%#015u<\n", u_int);// NO LEAKS
    printf("PF->%#015u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%# 15u<\n", u_int);// NO LEAKS
    printf("PF->%# 15u<\n", u_int);
    printf("---FAIL---\n");
    ft_printf("FT->%+ 15u<\n", u_int); // ret home -->             +21<-// NO LEAKS
    printf("PF->%+ 15u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%- 15u<\n", u_int);// NO LEAKS
    printf("PF->%- 15u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%-# 15u<\n", u_int);// NO LEAKS
    printf("PF->%-# 15u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%.1u<\n", u_int);// NO LEAKS
    printf("PF->%.1u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%# 15x<\n", u_int);// NO LEAKS
    printf("PF->%# 15x<\n", u_int);
    printf("------\n");
    ft_printf("FT->%015.10X<\n", 4561258);// NO LEAKS
    printf("PF->%015.10X<\n", 4561258 );
    printf("------\n");
    ft_printf("FT->%-#015.10X<\n", 4561258);// NO LEAKS
    printf("PF->%-#015.10X<\n", 4561258 );
    printf("------\n");
    ft_printf("FT->%#015.10X<\n", 4561258);// NO LEAKS
    printf("PF->%#015.10X<\n", 4561258 );
    printf("------\n");
    ft_printf("FT->%#015.10X<\n", 4561258);// NO LEAKS
    printf("PF->%#015.10X<\n", 4561258 );
    // printf("================POINTEUR================\n");
    // char *str;
    // printf("------\n");
    // ft_printf("FT->%p<\n", &str);// NO LEAKS
    // printf("PF->%p<\n", &str);
    // printf("------\n");
    // ft_printf("FT->%p<\n", &str); // NO LEAKS
    // printf("PF->%p<\n", &str);
    // printf("------\n");
    // ft_printf("FT->%#p<\n", &str); // NO LEAKS
    // printf("PF->%#p<\n", &str);
    // printf("------\n");
    // ft_printf("FT->%020p<\n", &str);// NO LEAKS
    // printf("PF->%020p<\n", &str);
    // printf("------\n");
    // ft_printf("FT->%+20p<\n", &str);// NO LEAKS
    // printf("PF->%+20p<\n", &str);
    // printf("------\n");
    // ft_printf("FT->%-20p<\n", &str); // NO LEAKS
    // printf("PF->%-20p<\n", &str);
    // printf("------\n");
    // ft_printf("FT->%-#20p<\n", &str);  // NO LEAKS
    // printf("PF->%-#20p<\n", &str);
    // printf("------\n");
    // ft_printf("FT->%-#.5p<\n", &str);  // NO LEAKS
    // printf("PF->%-#.5p<\n", &str);
    // printf("------\n");
    // ft_printf("FT->%# 25.5p<\n", &str); // NO LEAKS
    // printf("PF->%# 25.5p<\n", &str);
//     printf("================FLOAT================\n"); // NO LEAKS
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.05); // 0.1
//     printf("PF->%.1f<-\n", 0.05);// 0.1
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.03); // 0.0
//     printf("PF->%.1f<-\n", 0.03);// 0.0
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.10); // 0.1
//     printf("PF->%.1f<-\n", 0.10); //0.1
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.15); //0.1
//     printf("PF->%.1f<-\n", 0.15);// 0.1
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.20); //0.2
//     printf("PF->%.1f<-\n", 0.20);//0.2
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.25); //0.2
//     printf("PF->%.1f<-\n", 0.25); //0.2
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.30);//0.3
//     printf("PF->%.1f<-\n", 0.30);//0.3
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.35); //0.3
//     printf("PF->%.1f<-\n", 0.35); //0.3
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.40); // 0.4
//     printf("PF->%.1f<-\n", 0.40);//0.4
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.45);//0.5
//     printf("PF->%.1f<-\n", 0.45);//0.5
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.50);//0.5
//     printf("PF->%.1f<-\n", 0.50);//0.5
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.55);//0.6
//     printf("PF->%.1f<-\n", 0.55);//0.6
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.60);// 0.6
//     printf("PF->%.1f<-\n", 0.60);// 0.6
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.65);// 0.7
//     printf("PF->%.1f<-\n", 0.65);// 0.7
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.70);//0.7
//     printf("PF->%.1f<-\n", 0.70);//0.7
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.75);//0.8
//     printf("PF->%.1f<-\n", 0.75);//0.8
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.80);//0.8
//     printf("PF->%.1f<-\n", 0.80);//0.8
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.85);//0.9
//     printf("PF->%.1f<-\n", 0.85);//0.9
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.90);//0.99
//     printf("PF->%.1f<-\n", 0.90);//0.9
//     printf("------\n");
//     ft_printf("FT->%.1f<-\n", 0.95);//??
//     printf("PF->%.1f<-\n", 0.95);// ??
//     printf("------\n");
//     ft_printf("FT->%.20f<\n", 0.152321654);
//     printf("PF->%.20f<\n", 0.152321654);
//     printf("------\n");
//     ft_printf("FT->%.20f<\n", 12356789123456.152321654);
//     printf("PF->%.20f<\n", 12356789123456.152321654);
//     printf("------\n");
//     ft_printf("FT->%.2f<\n", 99.999);
//     printf("PF->%.2f<\n", 99.9999);
//     printf("------\n");
//     ft_printf("FT->%-015.2f<\n", 99.999);
//     printf("PF->%-015.2f<\n", 99.9999);
//     printf("------\n");
//     ft_printf("FT->%- 15.2f<\n", 99.999);
//     printf("PF->%- 15.2f<\n", 99.9999);
//     printf("------\n");
//     ft_printf("FT->%.30f<\n", 123456.123456);
//     printf("PF->%.30f<\n", 123456.123456);
//     printf("------\n");
//     ft_printf("FT->%.60f<\n", 17999999999999999780.123456);
//     printf("PF->%.60f<\n", 17999999999999999780.123456);
//     printf("------\n");
//     ft_printf("FT->%.21Lf<\n", 12345654988778946465.123456L);
//     printf("PF->%.21Lf<\n", 12345654988778946465.123456L);
//     printf("------\n");
//     ft_printf("FT->%Lf<\n", 0.123456L);
//     printf("PF->%Lf<\n", 0.123456L);
//     printf("------\n");
//     ft_printf("FT->%.50f<\n", 0.123456);
//     printf("PF->%.50f<\n", 0.123456);
//     printf("----test--\n");
//     ft_printf("FT->%.50f<\n", 0.123456);
//     printf("PF->%.50f<\n", 0.123456);
//     printf("------\n");
//     ft_printf("FT->%.50lf<\n", 0.123456);
//     printf("PF->%.50lf<\n", 0.123456);
//     printf("------\n");
//     ft_printf("FT->%f<\n", -42.420000);
//     printf("PF->%f<\n", -42.420000);
//     printf("================BONUS================\n"); //NO LEAKS

//     printf("------\n");
//     ft_printf("FT->%s%s%s<\n", "\x1B[31m", "Hello", "\x1B[0m");
//     printf("PT->%s%s%s<\n", "\x1B[31m", "Hello", "\x1B[0m");
//     printf("------\n");
//     ft_printf("FT->%s%s%s<\n", "\033[4m", "Underline","\033[0m");
//     printf("PF->%s%s%s<\n", "\033[4m", "Underline","\033[0m");
//     printf("------\n");
//     ft_printf("FT->%s%s%s<\n", "\033[1m", "BOLD","\033[0m");
//     printf("PF->%s%s%s<\n", "\033[1m", "BOLD","\033[0m");
//     printf("------\n");
//     ft_printf("FT->%s%s%s<\n", "\033[5m", "Blink","\033[25m");
//     printf("PF->%s%s%s<\n", "\033[5m", "Blink","\033[25m");
//     printf("------\n");
//     ft_printf("FT->%s%s%s%s%s%s<\n","\x1B[31m","\033[4m", "\033[1m", "\033[5m", "Whaaaaatttt","\033[0m");
//     printf("PF->%s%s%s%s%s%s<\n","\x1B[31m","\033[4m", "\033[1m", "\033[5m", "Whaaaaatttt","\033[0m");
//     printf("================BOOL================\n"); // NOLEAKS
//     t_bool test1 = true;
//     t_bool test2 = false;
//     printf("------\n");
//     ft_printf("FT->%t<\n", test1);
//     ft_printf("FT->%t<\n", test2);
//     printf("================L&LL INT================\n"); // NO LEAKS
//     long long int test_ll = 123456789132456789LL;
//     long int test_l = 123456789132456789L;
//     printf("------\n");
//     ft_printf("FT->%lld<\n", test_ll);
//     printf("PT->%lld<\n", test_ll);
//     printf("------\n");
//     ft_printf("FT->%ld<\n", test_l);
//     printf("PT->%ld<\n", test_l);
//     printf("------\n");
//     ft_printf("FT->%llu<\n", test_ll);
//     printf("PT->%llu<\n", test_ll);
//     printf("------\n");
//     ft_printf("FT->%lu<\n", test_l);
//     printf("PT->%lu<\n", test_l);
//     printf("------\n");
//     ft_printf("FT->%lli<\n", test_ll);
//     printf("PT->%lli<\n", test_ll);
//     printf("------\n");
//     ft_printf("FT->%li<\n", test_l);
//     printf("PT->%li<\n", test_l);
//     printf("------\n");
//     ft_printf("FT->%llo<\n", test_ll);
//     printf("PT->%llo<\n", test_ll);
//     printf("------\n");
//     ft_printf("FT->%lo<\n", test_l);
//     printf("PT->%lo<\n", test_l);
//     printf("================SHORT INT================\n"); // NO LEAKS
//     short int test_sh_1 = 128;
//     printf("------\n");
//     ft_printf("FT->%hd<\n", test_sh_1);
//     printf("PT->%hd<\n", test_sh_1);
//     printf("------\n");
//     ft_printf("FT->%015hd<\n", test_sh_1);
//     printf("PT->%015hd<\n", test_sh_1);
//     printf("------\n");
//     ft_printf("FT->%hu<\n", test_sh_1);
//     printf("PT->%hu<\n", test_sh_1);
//     printf("------\n");
//     ft_printf("FT->%015hu<\n", test_sh_1);
//     printf("PT->%015hu<\n", test_sh_1);
//     printf("================CHAR INT================\n"); //NO LEAKS
//     char  test_sh = -275;
//     printf("------\n");
//     ft_printf("FT->%hhd<\n", test_sh);
//     printf("PT->%hhd<\n", test_sh);
//     printf("------\n");
//     ft_printf("FT->%015hhd<\n", test_sh);
//     printf("PT->%015hhd<\n", test_sh);
//     printf("------\n");
//     ft_printf("FT->%hhd<\n", 148);
//     printf("PT->%hhd<\n", 148);
//     printf("------\n");
//     ft_printf("FT->%015hhd<\n", 2500);
//     printf("PT->%015hhd<\n", 2500);
//     printf("------\n");
//     ft_printf("FT->% 15hhd<\n", 7);
//     printf("PT->% 15hhd<\n", 7);
//     printf("------\n");
//     ft_printf("FT->%.15hhd<\n", 1);
//     printf("PT->%.15hhd<\n", 1);
//     printf("------\n");
//     ft_printf("FT->%hhu<\n", test_sh);
//     printf("PT->%hhu<\n", test_sh);
//     printf("------\n");
//     ft_printf("FT->%015hhu<\n", test_sh);
//     printf("PT->%015hhu<\n", test_sh);
//     printf("------\n");
//     ft_printf("FT->%hhu<\n", 148);
//     printf("PT->%hhu<\n", 148);
//     printf("------\n");
//     ft_printf("FT->%015hhu<\n", 2500);
//     printf("PT->%015hhu<\n", 2500);
//     printf("------\n");
//     ft_printf("FT->% 15hhu<\n", 7);
//     printf("PT->% 15hhu<\n", 7);
//     printf("------\n");
//     ft_printf("FT->%.15hhu<\n", 1);
//     printf("PT->%.15hhu<\n", 1);
//     printf("------\n");
//     ft_printf("FT->% 15hhx<\n", 7);
//     printf("PT->% 15hhx<\n", 7);
//     printf("------\n");
//     ft_printf("FT->%.15hhx<\n", 1);
//     printf("PT->%.15hhx<\n", 1);
//     printf("------\n");
//     ft_printf("FT->%hhx<\n", test_sh);
//     printf("PT->%hhx<\n", test_sh);
//     printf("------\n");
//     ft_printf("FT->%015hhx<\n", test_sh);
//     printf("PT->%015hhx<\n", test_sh);
//     printf("------\n");
//     ft_printf("FT->%hhx<\n", 148);
//     printf("PT->%hhx<\n", 148);
//     printf("------\n");
//     ft_printf("FT->%015hhx<\n", 2500);
//     printf("PT->%015hhx<\n", 2500);
//     printf("------\n");
//     ft_printf("FT->% 15hhx<\n", 7);
//     printf("PT->% 15hhx<\n", 7);
//     printf("------\n");
//     ft_printf("FT->%.15hhx<\n", 1);
//     printf("PT->%.15hhx<\n", 1);
//     printf("================BINAIRE================\n"); // NO LEAKS

//     int test = 1;
//     char *a = "Hello World";
//     printf("------\n");
//     ft_printf("FT->%b<\n", a);
//     ft_printf("FT->%b<\n", test);
//     printf("================ALIGN================\n"); // NOLEAKS
//     int number = 123456;
//     double decimal = 123.123456;
//     char *ptr = NULL;

//     printf("------\n");
//     ft_printf("FT->%-d<\n", number);
//     printf("PT->%-d<\n", number);
//     printf("------\n");
//     ft_printf("FT->%- d<\n", number);
//     printf("PT->%- d<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-15d<\n", number);
//     printf("PT->%-15d<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-15.10d<\n", number);
//     printf("PT->%-15.10d<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-+15.10d<\n", number);
//     printf("PT->%-+15.10d<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-015d<\n", number);
//     printf("PT->%-015d<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-#x<\n", number);
//     printf("PT->%-#x<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-#15x<\n", number);
//     printf("PT->%-#15x<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-#015x<\n", number);
//     printf("PT->%-#015x<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-# 15x<\n", number);
//     printf("PT->%-# 15x<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-#o<\n", number);
//     printf("PT->%-#o<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-o<\n", number);
//     printf("PT->%-o<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-# 15o<\n", number);
//     printf("PT->%-# 15o<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-o<\n", number);
//     printf("PT->%-o<\n", number);
//     printf("------\n");
//     ft_printf("FT->%- o<\n", number);
//     printf("PT->%- o<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-15o<\n", number);
//     printf("PT->%-15o<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-15.10o<\n", number);
//     printf("PT->%-15.10o<\n", number);
//     printf("--FAIl----\n");
//     ft_printf("FT->%-+15.10o<\n", number);  // verifier sur mac si flag + ave conv o
//     printf("PT->%-+15.10o<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-015o<\n", number);
//     printf("PT->%-015o<\n", number);
//     printf("---FAIL---\n");
//     ft_printf("FT->%-+o<\n", number); // verifier sur mac si flag + ave conv o
//     printf("PT->%-+o<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-o<\n", number);
//     printf("PT->%-o<\n", number);
//     printf("================MOULITEST================\n"); // NO LEAKS
//     printf("------\n");
//     ft_printf("FT->%#6o<\n", 73);
//     printf("PT->%#6o<\n", 73);
//     printf("------\n");
//     ft_printf("FT->%-#6o<\n", 73);
//     printf("PT->%-#6o<\n", 73);
//     printf("------\n");
//     ft_printf("FT->%d<\n", 2147483648);
//     printf("PT->%d<\n", 2147483648);
//     printf("------\n");
//     ft_printf("FT->%d<\n", -2147483648);
//     printf("PT->%d<\n", -2147483648);
//     printf("------\n");
//     ft_printf("FT->%5d<\n", -42);
//     printf("PT->%5d<\n", -42);
//     printf("------\n");
//     ft_printf("FT->%-5d<\n", -42);
//     printf("PT->%-5d<\n", -42);
//     printf("------\n");
//     ft_printf("FT->%-05d<\n", -42);
//     printf("PT->%-05d<\n", -42);
//     printf("------\n");
//     ft_printf("FT->%hd<\n", 32768);
//     printf("PT->%hd<\n", 32768);
//     printf("------\n");
//     ft_printf("FT->%hhd<\n",-128);
//     printf("PT->%hhd<\n", -128);
//     printf("------\n");
//     ft_printf("FT->%hhd<\n",128);
//     printf("PT->%hhd<\n", 128);
//         printf("------\n");
//     ft_printf("%lld\n", -9223372036854775808);
//     printf("%lld\n", -9223372036854775808);
//         printf("------\n");
//     ft_printf("%lld\n", 9223372036854775808);
//     printf("%lld\n", 9223372036854775808);
//         printf("------\n");
//     ft_printf("%10.5d\n", 4242);
//     printf("%10.5d\n", 4242);
//         printf("------\n");
//     ft_printf("% 10.5d\n", 4242);
//     printf("% 10.5d\n", 4242);
//         printf("------\n");
//     ft_printf("%+10.5d\n", 4242);
//     printf("%+10.5d\n", 4242);
//         printf("------\n");
//     ft_printf("%03.1d\n", 0);
//     printf("%03.1d\n", 0);
//             printf("------\n");
//     ft_printf("%010.3d\n", 01);
//     printf("%010.3d\n", 01);
//         printf("------\n");
//     ft_printf("%03.2d\n", -1);
//     printf("%03.2d\n", -1);
//         printf("------\n");
//     ft_printf("%-#6o\n", 2500);
//     printf("%-#6o\n", 2500);
//    printf("================ TEST FLAGS ================\n"); // NO LEAKS
//     printf("------\n");
//     ft_printf("%+ 12d\n", -2500);
//     printf("%+ 12d\n", -2500);
//     printf("------\n");
//     ft_printf("FT->%+ 15u<\n", u_int);
//     printf("PF->%+ 15u<\n", u_int);
//     printf("------\n");
//     ft_printf("FT->%+u<\n", u_int);
//     printf("PF->%+u<\n", u_int);
//     printf("------\n");
//     ft_printf("FT->%+p<\n", u_int);
//     printf("PF->%+p<\n", u_int);
//     printf("------\n");
//     ft_printf("FT->%+o<\n", u_int);
//     printf("PF->%+o<\n", u_int);
//     printf("------\n");
//     ft_printf("FT->%+x<\n", u_int);
//     printf("PF->%+x<\n", u_int);
//     printf("------\n");
//     ft_printf("FT->%-+o<\n", number);
//     printf("PT->%-+o<\n", number);
//     printf("------\n");
//     ft_printf("FT->%-+15.10o<\n", number);
//     printf("PT->%-+15.10o<\n", number);

//     printf("================ unbehavior test ================\n");
//     ft_printf("->%<-\n");
//     printf("->%<-\n");
//     printf("------\n");
//     ft_printf("% ");
//     printf("% ");
//     printf("------\n");
//     ft_printf("% ");
//     printf("% h");
//     printf("------\n");
//     ft_printf("% hZ%\n");
//     printf("% hZ%\n");
//     printf("------\n");
//     ft_printf("% Z%s\n", "test");
//     printf("% Z%s\n", "test");
//     printf("------\n");
//     ft_printf("%000   %\n", "test");
//     printf("%000   %\n", "test");
//     printf("------\n");
//     ft_printf("%jx\n", 4294967295);
//     printf("%jx\n", 4294967295);
//     printf("------\n");
//     ft_printf("%ll#x\n", 9223372036854775807);
//     printf("%ll#x\n", 9223372036854775807);
//     printf("------\n");
//     ft_printf("%5+d\n", 42);
//     printf("%5+d\n", 42);
//     printf("------\n");
//     ft_printf("%5+d\n", -42);
//     printf("%5+d\n", -42);
//     printf("------\n");
//     ft_printf("%-5+d\n", 42);
//     printf("%-5+d\n", 42);
//     printf("------\n");
//     ft_printf("%-5+d\n", -42);
//     printf("%-5+d\n", -42);
//     printf("------\n");
//     ft_printf("%jd\n", 9223372036854775807);
//     printf("%jd\n", 9223372036854775807);
//     printf("------\n");
//     ft_printf("%jd\n", -9223372036854775808);
//     printf("%jd\n", -9223372036854775808);
//     printf("------\n");
//     ft_printf("%zd\n", 4294967295);
//     printf("%zd\n", 4294967295);
//     printf("------\n");
//     ft_printf("%zd\n", 4294967296);
//     printf("%zd\n", 4294967296);
//     printf("------\n");
//     ft_printf("%zu\n", 4294967296);
//     printf("%zu\n", 4294967296);
//     printf("------\n");
//     ft_printf("%ju\n", 4999999999);
//     printf("%ju\n", 4999999999);
//     printf("------\n");
//     ft_printf("%zhd\n", 4294967296);
//     printf("%zhd\n", 4294967296);
//     printf("------\n");
//     ft_printf("@main_ftprintf: %####0000 33..1..#00d\\n\n", 256);
//     printf("@main_ftprintf: %####0000 33..1..#00d\\n\n", 256);
//     printf("------\n");
//     ft_printf("@main_ftprintf: %####0000 33..1..#00d\\n\n", 256);
//     printf("@main_ftprintf: %####000033....21d\\n\n", 256);
//     printf("------\n");
//     ft_printf("@main_ftprintf: %####0000 33..1d\n", 256);
//     printf("@main_ftprintf: %####0000 33..1d\n", 256);
//     printf("------\n");
//     ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d\n", 256);
//     printf("@main_ftprintf: %###-#0000 33...12..#0+0d\n", 256);
//     printf("------\n");
//     ft_printf("FT->%lls\n", "test lls");
//     printf("PF->%lls\n", "test lls");
//     printf("------\n");
//     ft_printf("FT->%*s<-\n", -12,"lls");
//     printf("PF->%*s<-\n", -12,"lls");
  printf("================ END OF TEST ================\n");
    // int max = __INT_MAX__;
    // int min = -2147483648;
    // int randonm = 73;

    // int pre    = 5;
    // int width       = 0;

    // ft_printf("  -FT->%d<\n", max);
    // printf("  -PF->%d<\n", max);
    // ft_printf("  -FT->%d<\n", min);
    // printf("  -PF->%d<\n", min);
    // ft_printf("  -FT->%d<\n", randonm);
    // printf("  -PF->%d<\n", randonm);

    // /*PRECSION ++*/
    // while (width <= 20)
    // {
    //     ft_printf("  -FT->%*.*d<\n",width, pre, randonm);
    //     printf("  -PF->%*.*d<\n",width, pre, randonm);
    //     width++;
    //     pre++;
    // }
    system("leaks test_ftprintf > ./test/leaks/leaksreport.txt");
    return (0);
}
