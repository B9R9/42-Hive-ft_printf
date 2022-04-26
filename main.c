/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:30:51 by briffard          #+#    #+#             */
/*   Updated: 2022/04/26 09:47:26 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <limits.h>

int main(void)
{
//     int result;
//     char *stra;
//     stra = "000213564kjjsfhu";
//     result = ft_atoi(stra);
//     printf("ret = %d\n", result);


    printf("================SPECIFIC================\n");
    ft_printf("FT ->%#x<-\n", 0); // NO LEAKS
    printf("PF ->%#x<-\n", );// NO LEAKS
    printf("------\n");
    
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



    printf("================INT================\n");
    int max = __INT_MAX__;
    int min = -2147483647;
    int randonm = 73;
    int pre    = 10;
    int width       = 0;
    printf("------\n");
    ft_printf("FT->% d<\n", 42);// NO LEAKS
    printf("PF->% d<\n", 42);// NO LEAKS
    printf("------\n");
    ft_printf("FT->%+d<\n", 42);// NO LEAKS
    printf("PF->%+d<\n", 42);// NO LEAKS
    printf("------\n");
    ft_printf("FT->% d<\n", -42);// NO LEAKS
    printf("PF->% d<\n", -42);// NO LEAKS
    printf("------\n");
    ft_printf("FT->%+d<\n", -42);// NO LEAKS
    printf("PF->%+d<\n", -42);// NO LEAKS
    printf("------\n");
    ft_printf("FT->%+d<\n", 0);// NO LEAKS
    printf("PF->%+d<\n", 0);// NO LEAKS
    printf("------\n");
     ft_printf("FT->%+ d<\n", 42);// NO LEAKS
    printf("PF->%+ d<\n", 42);// NO LEAKS
    printf("------\n");
//     // ft_printf("FT->%+lld<\n", 4242424242424242424242); // ne compil pas
//     // printf("PF->%+lld<\n",4242424242424242424242);// ne compil pas
    printf("------\n");
    ft_printf("FT->%d<\n", max);// NO LEAKS
    printf("PF->%d<\n", max);// NO LEAKS
    printf("------\n");
    ft_printf("FT->%d<\n", min);// NO LEAKS
    printf("PF->%d<\n", min);// NO LEAKS
    printf("------\n");
    ft_printf("FT->%d<\n", randonm);// NO LEAKS
    printf("PF->%d<\n", randonm);// NO LEAKS
    printf("------\n");
    ft_printf("FT->%+015d<\n", randonm);// NO LEAKS
    printf("PF->%+015d<\n", randonm);// NO LEAKS
    printf("---FAIL---\n");
    ft_printf("FT->%+ 15d<\n", randonm);// NO LEAKS
    printf("PF->%+ 15d<\n", randonm);// NO LEAKS
    printf("------\n");
    ft_printf("FT->%- 15d<\n", randonm);// NO LEAKS
    printf("PF->%- 15d<\n", randonm);// NO LEAKS
    printf("------------------------\n");
    ft_printf("FT->%-15d<\n", randonm);// NO LEAKS
    printf("PF->%-15d<\n", randonm);// NO LEAKS
    printf("------\n");
    ft_printf("FT->%-015d<\n", randonm);
    printf("PF->%-015d<\n", randonm);
    printf("------\n");
    ft_printf("FT->%015.10d<\n", randonm);
    printf("PF->%015.10d<\n", randonm);
    printf("------\n");
    ft_printf("FT->%015.10X<\n", randonm);
    printf("PF->%015.10X<\n", randonm);
    printf("------\n");
    ft_printf("FT->%-+015.10d<\n", randonm);
    printf("PF->%-+015.10d<\n", randonm);

    /*PRECSION ++*/// NO LEAKS
    while (width <= 20)
    {
        printf("------\n");
        printf("Width = %d || pre = %d\n", width, pre);
        ft_printf("FT->%*.*d<\n",width, pre, randonm);
        printf("PF->%*.*d<\n",width, pre, randonm);
        width++;
        pre--;
    }
    printf("================HEX&OCT&UINT================\n");
    long int long_int = 9999999999;
    long long int   ll_int = 999999999999999999LL;
    unsigned int u_int = 21;
    unsigned long int ul_int = 123456789123456UL;
    unsigned long long ull_int = 12345678912345456653ULL;
    printf("------\n");
    ft_printf("FT->%#6o<\n", 2500);
    printf("PF->%#6o<\n", 2500);
    printf("------\n");
    ft_printf("FT->%-5.10o<\n", 2500);
    printf("PF->%-5.10o<\n", 2500);
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
    printf("================POINTEUR================\n");
    char *str;
    printf("------\n");
    ft_printf("FT->%p<\n", &str);// NO LEAKS
    printf("PF->%p<\n", &str);
    printf("------\n");
    ft_printf("FT->%p<\n", &str); // NO LEAKS
    printf("PF->%p<\n", &str);
    printf("------\n");
    ft_printf("FT->%#p<\n", &str); // NO LEAKS
    printf("PF->%#p<\n", &str);
    printf("------\n");
    ft_printf("FT->%020p<\n", &str);// NO LEAKS
    printf("PF->%020p<\n", &str);
    printf("------\n");
    ft_printf("FT->%+20p<\n", &str);// NO LEAKS
    printf("PF->%+20p<\n", &str);
    printf("------\n");
    ft_printf("FT->%-20p<\n", &str); // NO LEAKS
    printf("PF->%-20p<\n", &str);
    printf("------\n");
    ft_printf("FT->%-#20p<\n", &str);  // NO LEAKS
    printf("PF->%-#20p<\n", &str);
    printf("------\n");
    ft_printf("FT->%-#.5p<\n", &str);  // NO LEAKS
    printf("PF->%-#.5p<\n", &str);
    printf("------\n");
    ft_printf("FT->%# 25.5p<\n", &str); // NO LEAKS
    printf("PF->%# 25.5p<\n", &str);
    printf("================FLOAT================\n"); // NO LEAKS
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.05); 
    printf("PF->%.1f<-\n", 0.05);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.10);
    printf("PF->%.1f<-\n", 0.10);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.15);
    printf("PF->%.1f<-\n", 0.15);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.20);
    printf("PF->%.1f<-\n", 0.20);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.25);
    printf("PF->%.1f<-\n", 0.25);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.30);
    printf("PF->%.1f<-\n", 0.30);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.35);
    printf("PF->%.1f<-\n", 0.35);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.40);
    printf("PF->%.1f<-\n", 0.40);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.45);
    printf("PF->%.1f<-\n", 0.45);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.50);
    printf("PF->%.1f<-\n", 0.50);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.55);
    printf("PF->%.1f<-\n", 0.55);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.60);
    printf("PF->%.1f<-\n", 0.60);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.65);
    printf("PF->%.1f<-\n", 0.65);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.70);
    printf("PF->%.1f<-\n", 0.70);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.75);
    printf("PF->%.1f<-\n", 0.75);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.80);
    printf("PF->%.1f<-\n", 0.80);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.85);
    printf("PF->%.1f<-\n", 0.85);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.90);
    printf("PF->%.1f<-\n", 0.90);
    printf("------\n");
    ft_printf("FT->%.1f<-\n", 0.95);
    printf("PF->%.1f<-\n", 0.95);
    printf("------\n");
    ft_printf("FT->%.20f<\n", 0.152321654);
    printf("PF->%.20f<\n", 0.152321654);
    printf("------\n");
    ft_printf("FT->%.20f<\n", 12356789123456.152321654);
    printf("PF->%.20f<\n", 12356789123456.152321654);
    printf("------\n");
    ft_printf("FT->%.2f<\n", 99.999);
    printf("PF->%.2f<\n", 99.9999);
    printf("------\n");
    ft_printf("FT->%-015.2f<\n", 99.999);
    printf("PF->%-015.2f<\n", 99.9999);
    printf("------\n");
    ft_printf("FT->%- 15.2f<\n", 99.999);
    printf("PF->%- 15.2f<\n", 99.9999);
    printf("------\n");
    ft_printf("FT->%.30f<\n", 123456.123456);
    printf("PF->%.30f<\n", 123456.123456);
    printf("------\n");
    ft_printf("FT->%.60f<\n", 17999999999999999780.123456);
    printf("PF->%.60f<\n", 17999999999999999780.123456);
    printf("------\n");
    ft_printf("FT->%.60f<\n", 0.123456);
    printf("PF->%.60f<\n", 0.123456);
    printf("------\n");
    ft_printf("FT->%.50Lf<\n", 0.123456);
    printf("PF->%.50Lf<\n", 0.123456);
    printf("================BONUS================\n"); //NO LEAKS

    printf("------\n");
    ft_printf("FT->%s%s%s<\n", "\x1B[31m", "Hello", "\x1B[0m");
    printf("PT->%s%s%s<\n", "\x1B[31m", "Hello", "\x1B[0m");
    printf("------\n");
    ft_printf("FT->%s%s%s<\n", "\033[4m", "Underline","\033[0m");
    printf("PF->%s%s%s<\n", "\033[4m", "Underline","\033[0m");
    printf("------\n");
    ft_printf("FT->%s%s%s<\n", "\033[1m", "BOLD","\033[0m");
    printf("PF->%s%s%s<\n", "\033[1m", "BOLD","\033[0m");
    printf("------\n");
    ft_printf("FT->%s%s%s<\n", "\033[5m", "Blink","\033[25m");
    printf("PF->%s%s%s<\n", "\033[5m", "Blink","\033[25m");
    printf("------\n");
    ft_printf("FT->%s%s%s%s%s%s<\n","\x1B[31m","\033[4m", "\033[1m", "\033[5m", "Whaaaaatttt","\033[0m");
    printf("PF->%s%s%s%s%s%s<\n","\x1B[31m","\033[4m", "\033[1m", "\033[5m", "Whaaaaatttt","\033[0m");
    printf("================BOOL================\n"); // NOLEAKS
    t_bool test1 = true;
    t_bool test2 = false;
    printf("------\n");
    ft_printf("FT->%t<\n", test1);
    ft_printf("FT->%t<\n", test2);
    printf("================L&LL INT================\n"); // NO LEAKS
    long long int test_ll = 123456789132456789LL;
    long int test_l = 123456789132456789L;
    printf("------\n");
    ft_printf("FT->%lld<\n", test_ll);
    printf("PT->%lld<\n", test_ll);
    printf("------\n");
    ft_printf("FT->%ld<\n", test_l);
    printf("PT->%ld<\n", test_l);
    printf("================SHORT INT================\n"); // NO LEAKS
    short int test_sh_1 = 128;
    printf("------\n");
    ft_printf("FT->%hd<\n", test_sh_1);
    printf("PT->%hd<\n", test_sh_1);
    printf("------\n");
    ft_printf("FT->%015hd<\n", test_sh_1);
    printf("PT->%015hd<\n", test_sh_1);
    printf("================CHAR INT================\n"); //NO LEAKS
    char  test_sh = -275;
    printf("------\n");
    ft_printf("FT->%hhd<\n", test_sh);
    printf("PT->%hhd<\n", test_sh);
    printf("------\n");
    ft_printf("FT->%015hhd<\n", test_sh);
    printf("PT->%015hhd<\n", test_sh);
    printf("------\n");
    ft_printf("FT->%hhd<\n", 148);
    printf("PT->%hhd<\n", 148);
    printf("------\n");
    ft_printf("FT->%015hhd<\n", 2500);
    printf("PT->%015hhd<\n", 2500);
    printf("------\n");
    ft_printf("FT->% 15hhd<\n", 7);
    printf("PT->% 15hhd<\n", 7);
    printf("------\n");
    ft_printf("FT->%.15hhd<\n", 1);
    printf("PT->%.15hhd<\n", 1);
    printf("================BINAIRE================\n"); // NO LEAKS

    int test = 1;
    char *a = "Hello World";
    printf("------\n");
    ft_printf("FT->%b<\n", a);
    ft_printf("FT->%b<\n", test);
    printf("================ALIGN================\n"); // NOLEAKS
    int number = 123456;
    double decimal = 123.123456;
    char *ptr = NULL;

    printf("------\n");
    ft_printf("FT->%-d<\n", number);
    printf("PT->%-d<\n", number);
    printf("------\n");
    ft_printf("FT->%- d<\n", number);
    printf("PT->%- d<\n", number);
    printf("------\n");
    ft_printf("FT->%-15d<\n", number);
    printf("PT->%-15d<\n", number);
    printf("------\n");
    ft_printf("FT->%-15.10d<\n", number);
    printf("PT->%-15.10d<\n", number);
    printf("------\n");
    ft_printf("FT->%-+15.10d<\n", number);
    printf("PT->%-+15.10d<\n", number);
    printf("------\n");
    ft_printf("FT->%-015d<\n", number);
    printf("PT->%-015d<\n", number);
    printf("------\n");
    ft_printf("FT->%-#x<\n", number);
    printf("PT->%-#x<\n", number);
    printf("------\n");
    ft_printf("FT->%-#15x<\n", number);
    printf("PT->%-#15x<\n", number);
    printf("------\n");
    ft_printf("FT->%-#015x<\n", number);
    printf("PT->%-#015x<\n", number);
    printf("------\n");
    ft_printf("FT->%-# 15x<\n", number);
    printf("PT->%-# 15x<\n", number);
    printf("------\n");
    ft_printf("FT->%-#o<\n", number);
    printf("PT->%-#o<\n", number);
    printf("------\n");
    ft_printf("FT->%-o<\n", number);
    printf("PT->%-o<\n", number);
    printf("------\n");
    ft_printf("FT->%-# 15o<\n", number);
    printf("PT->%-# 15o<\n", number);
    printf("------\n");
    ft_printf("FT->%-o<\n", number);
    printf("PT->%-o<\n", number);
    printf("------\n");
    ft_printf("FT->%- o<\n", number);
    printf("PT->%- o<\n", number);
    printf("------\n");
    ft_printf("FT->%-15o<\n", number);
    printf("PT->%-15o<\n", number);
    printf("------\n");
    ft_printf("FT->%-15.10o<\n", number);
    printf("PT->%-15.10o<\n", number);
    printf("--FAIl----\n");
    ft_printf("FT->%-+15.10o<\n", number);  // verifier sur mac si flag + ave conv o
    printf("PT->%-+15.10o<\n", number);
    printf("------\n");
    ft_printf("FT->%-015o<\n", number);
    printf("PT->%-015o<\n", number);
    printf("---FAIL---\n");
    ft_printf("FT->%-+o<\n", number); // verifier sur mac si flag + ave conv o
    printf("PT->%-+o<\n", number);
    printf("------\n");
    ft_printf("FT->%-o<\n", number);
    printf("PT->%-o<\n", number);
    printf("================MOULITEST================\n"); // NO LEAKS
    printf("------\n");
    ft_printf("FT->%#6o<\n", 73);
    printf("PT->%#6o<\n", 73);
    printf("------\n");
    ft_printf("FT->%-#6o<\n", 73);
    printf("PT->%-#6o<\n", 73);
    printf("------\n");
    ft_printf("FT->%d<\n", 2147483648);
    printf("PT->%d<\n", 2147483648);
    printf("------\n");
    ft_printf("FT->%d<\n", -2147483648);
    printf("PT->%d<\n", -2147483648);
    printf("------\n");
    ft_printf("FT->%5d<\n", -42);
    printf("PT->%5d<\n", -42);
    printf("------\n");
    ft_printf("FT->%-5d<\n", -42);
    printf("PT->%-5d<\n", -42);
    printf("------\n");
    ft_printf("FT->%-05d<\n", -42);
    printf("PT->%-05d<\n", -42);
    printf("------\n");
    ft_printf("FT->%hd<\n", 32768);
    printf("PT->%hd<\n", 32768);
    printf("------\n");
    ft_printf("FT->%hhd<\n",-128);
    printf("PT->%hhd<\n", -128);
    printf("------\n");
    ft_printf("FT->%hhd<\n",128);
    printf("PT->%hhd<\n", 128);
        printf("------\n");
    ft_printf("%lld\n", -9223372036854775808);
    printf("%lld\n", -9223372036854775808);
        printf("------\n");
    ft_printf("%lld\n", 9223372036854775808);
    printf("%lld\n", 9223372036854775808);
        printf("------\n");
    ft_printf("%10.5d\n", 4242);
    printf("%10.5d\n", 4242);
        printf("------\n");
    ft_printf("% 10.5d\n", 4242);
    printf("% 10.5d\n", 4242);
        printf("------\n");
    ft_printf("%+10.5d\n", 4242);
    printf("%+10.5d\n", 4242);
        printf("------\n");
    ft_printf("%03.1d\n", 0);
    printf("%03.1d\n", 0);
            printf("------\n");
    ft_printf("%010.3d\n", 01);
    printf("%010.3d\n", 01);
        printf("------\n");
    ft_printf("%03.2d\n", -1);
    printf("%03.2d\n", -1);
        printf("------\n");
    ft_printf("%-#6o\n", 2500);
    printf("%-#6o\n", 2500);
   printf("================ TEST FLAGS ================\n"); // NO LEAKS
    printf("------\n");
    ft_printf("%+ 12d\n", -2500);
    printf("%+ 12d\n", -2500);
    printf("------\n");
    ft_printf("FT->%+ 15u<\n", u_int);
    printf("PF->%+ 15u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%+u<\n", u_int);
    printf("PF->%+u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%+p<\n", u_int);
    printf("PF->%+p<\n", u_int);
    printf("------\n");
    ft_printf("FT->%+o<\n", u_int);
    printf("PF->%+o<\n", u_int);
    printf("------\n");
    ft_printf("FT->%+x<\n", u_int);
    printf("PF->%+x<\n", u_int);
    printf("------\n");
    ft_printf("FT->%-+o<\n", number);
    printf("PT->%-+o<\n", number);
    printf("------\n");
    ft_printf("FT->%-+15.10o<\n", number);
    printf("PT->%-+15.10o<\n", number);

    printf("================ unbehavior test ================\n");
    ft_printf("->%<-\n");
    printf("->%<-\n");
    printf("------\n");
    ft_printf("% ");
    printf("% ");
    printf("------\n");
    ft_printf("% ");
    printf("% h");
    printf("------\n");
    ft_printf("% hZ%\n");
    printf("% hZ%\n");
    printf("------\n");
    ft_printf("% Z%s\n", "test");
    printf("% Z%s\n", "test");
    printf("------\n");
    ft_printf("%000   %\n", "test");
    printf("%000   %\n", "test");
    printf("------\n");
    ft_printf("%jx\n", 4294967295);
    printf("%jx\n", 4294967295);
    printf("------\n");
    ft_printf("%ll#x\n", 9223372036854775807);
    printf("%ll#x\n", 9223372036854775807);
    printf("------\n");
    ft_printf("%5+d\n", 42);
    printf("%5+d\n", 42);
    printf("------\n");
    ft_printf("%5+d\n", -42);
    printf("%5+d\n", -42);
    printf("------\n");
    ft_printf("%-5+d\n", 42);
    printf("%-5+d\n", 42);
    printf("------\n");
    ft_printf("%-5+d\n", -42);
    printf("%-5+d\n", -42);
    printf("------\n");
    ft_printf("%jd\n", 9223372036854775807);
    printf("%jd\n", 9223372036854775807);
    printf("------\n");
    ft_printf("%jd\n", -9223372036854775808);
    printf("%jd\n", -9223372036854775808);
    printf("------\n");
    ft_printf("%zd\n", 4294967295);
    printf("%zd\n", 4294967295);
    printf("------\n");
    ft_printf("%zd\n", 4294967296);
    printf("%zd\n", 4294967296);
    printf("------\n");
    ft_printf("%zu\n", 4294967296);
    printf("%zu\n", 4294967296);
    printf("------\n");
    ft_printf("%ju\n", 4999999999);
    printf("%ju\n", 4999999999);
    printf("------\n");
    ft_printf("%zhd\n", 4294967296);
    printf("%zhd\n", 4294967296);
    printf("------\n");
    ft_printf("@main_ftprintf: %####0000 33..1..#00d\\n\n", 256);
    printf("@main_ftprintf: %####0000 33..1..#00d\\n\n", 256);
    printf("------\n");
    ft_printf("@main_ftprintf: %####0000 33..1..#00d\\n\n", 256);
    printf("@main_ftprintf: %####000033....21d\\n\n", 256);
    printf("------\n");
    ft_printf("@main_ftprintf: %####0000 33..1d\n", 256);
    printf("@main_ftprintf: %####0000 33..1d\n", 256);
    printf("------\n");
    ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d\n", 256);
    printf("@main_ftprintf: %###-#0000 33...12..#0+0d\n", 256);
    printf("------\n");
    ft_printf("FT->%lls\n", "test lls");
    printf("PF->%lls\n", "test lls");
    printf("------\n");
    ft_printf("FT->%*s<-\n", -12,"lls");
    printf("PF->%*s<-\n", -12,"lls");

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
    system("leaks test > leaksreport.txt");
    return (0);
}
