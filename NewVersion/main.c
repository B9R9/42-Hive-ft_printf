/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:30:51 by briffard          #+#    #+#             */
/*   Updated: 2022/04/19 17:22:54 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <limits.h>

int main(void)
{
    // printf("================STR================\n");
    // char    *name;
    // char    *test_null;

    // test_null = NULL;
    // name = "joe l' indien";

    // ft_printf("FT ->%.2s is a string<-\n", "");
    // printf("PF ->%.2s is a string<-\n", "");
    // printf("------\n");
    // ft_printf("FT ->%5.2s is a string<-\n", "");
    // printf("PF ->%5.2s is a string<-\n", "");
    // printf("------\n");
    // ft_printf("FT ->%-.2s is a string<-\n", "");
    // printf("PF ->%-.2s is a string<-\n", "");
    // printf("------\n");
    // ft_printf("FT ->%-5.2s is a string<-\n", "");
    // printf("PF ->%-5.2s is a string<-\n", "");
    // printf("------\n");
    // ft_printf("FT ->%s<-\n", name);
    // printf("PF ->%s<-\n", name);
    // printf("------\n");
    // ft_printf("FT ->%030s<-\n", name);
    // printf("PF ->%030s<-\n", name);
    // printf("------\n");
    // ft_printf("FT ->% 30s<-\n", name);
    // printf("PF ->% 30s<-\n", name);
    // printf("------\n");
    // ft_printf("FT ->%- 30s<-\n", name);
    // printf("PF ->%- 30s<-\n", name);
    // printf("------\n");
    // ft_printf("FT ->%+ 30s<-\n", name);
    // printf("PF ->%+ 30s<-\n", name);
    // printf("------\n");
    // ft_printf("FT ->%# 30s<-\n", name);
    // printf("PF ->%# 30s<-\n", name);
    // printf("------\n");
    // ft_printf("FT ->%# 30.10s<-\n", name);
    // printf("PF ->%# 30.10s<-\n", name);
    // printf("------\n");
    // ft_printf("FT ->%.10s<-\n", name);
    // printf("PF ->%.10s<-\n", name);
    // printf("------\n");
    // ft_printf("FT ->%30.10s<-\n", name);
    // printf("PF ->%30.10s<-\n", name);
    // printf("------\n");
    // ft_printf("FT ->%-30.10s<-\n", name);
    // printf("PF ->%-30.10s<-\n", name);
    // printf("------\n");
    // ft_printf("FT ->%s<-\n", test_null);
    // printf("PF ->%s<-\n", test_null);
    // printf("================%%================\n");
    // printf("------\n");
    // ft_printf("FT ->%%<-\n");
    // printf("PF ->%%<-\n");
    // printf("------\n");
    // ft_printf("FT ->%5%<-\n");
    // printf("PF ->%5%<-\n");
    // printf("------\n");
    // ft_printf("FT ->%-5%<-\n");
    // printf("PF ->%-5%<-\n");
    // printf("------\n");
    // ft_printf("FT ->%.0%<-\n");
    // printf("PF ->%.0%<-\n");
    // printf("------\n");
    // ft_printf("FT ->%%<-\n", "test");
    // printf("PF ->%%<-\n", "test");
    
    // printf("================CHAR================\n");
    // char c = 'a';
    // char n = NULL;
    // printf("------\n");
    // ft_printf("FT ->%c<-\n", n);
    // printf("PF ->%c<-\n", n);
    // printf("------\n");
    // ft_printf("FT ->%c<-\n", c);
    // printf("PF ->%c<-\n", c);
    // printf("------\n");
    // ft_printf("FT ->%+c<-\n", c);
    // printf("PF ->%+c<-\n", c);
    // printf("------\n");
    // ft_printf("FT ->%#c<-\n", c);
    // printf("PF ->%#c<-\n", c);
    // printf("------\n");
    // ft_printf("FT ->%-c<-\n", c);
    // printf("PF ->%-c<-\n", c);
    // printf("------\n");
    // ft_printf("FT ->%.12c<-\n", c);
    // printf("PF ->%.12c<-\n", c);
    // printf("------\n");
    // ft_printf("FT ->%05c<-\n", c);
    // printf("PF ->%05c<-\n", c);
    // printf("------\n");
    // ft_printf("FT ->% 5c<-\n", c);
    // printf("PF ->% 5c<-\n", c);
    // printf("------\n");
    // ft_printf("FT ->%- 5c<-\n", c);
    // printf("PF ->%- 5c<-\n", c);
    // printf("------\n");
    // ft_printf("FT->%c<\n", 64);
    // printf("PF->%c<\n", 64);

    printf("================INT================\n");
    int max = __INT_MAX__;
    int min = -2147483647;
    int randonm = 73;
    int precision    = 10;
    int width       = 0;
    printf("------\n");
    ft_printf("FT->% d<\n", 42);
    printf("PF->% d<\n", 42);
    printf("------\n");
    ft_printf("FT->%+d<\n", 42);
    printf("PF->%+d<\n", 42);
    printf("------\n");
    ft_printf("FT->% d<\n", -42);
    printf("PF->% d<\n", -42);
    printf("------\n");
    ft_printf("FT->%+d<\n", -42);
    printf("PF->%+d<\n", -42);
    printf("------\n");
    ft_printf("FT->%+d<\n", 0); //FAIL
    printf("PF->%+d<\n", 0); //FAIL
    printf("------\n");
     ft_printf("FT->%+ d<\n", 42);
    printf("PF->%+ d<\n", 42);
    printf("------\n");
    // ft_printf("FT->%+lld<\n", 4242424242424242424242); // ne compil pas 
    // printf("PF->%+lld<\n",4242424242424242424242);// ne compil pas 
    printf("------\n");
    ft_printf("FT->%d<\n", max);
    printf("PF->%d<\n", max);
    printf("------\n");
    ft_printf("FT->%d<\n", min);
    printf("PF->%d<\n", min);
    printf("------\n");
    ft_printf("FT->%d<\n", randonm);
    printf("PF->%d<\n", randonm);
    printf("------\n");
    ft_printf("FT->%+015d<\n", randonm);
    printf("PF->%+015d<\n", randonm);
    printf("---FAIL---\n");
    ft_printf("FT->%+ 15d<\n", randonm);
    printf("PF->%+ 15d<\n", randonm);
    printf("------\n");
    ft_printf("FT->%- 15d<\n", randonm);
    printf("PF->%- 15d<\n", randonm);
    printf("------\n");
    ft_printf("FT->%-15d<\n", randonm);
    printf("PF->%-15d<\n", randonm);
    printf("------\n");
    ft_printf("FT->%-015d<\n", randonm);
    printf("PF->%-015d<\n", randonm);
    printf("------\n");
    ft_printf("FT->%015.10d<\n", randonm);
    printf("PF->%015.10d<\n", randonm);

    /*PRECSION ++*/
    // while (width <= 20)
    // {
    //     printf("------\n");
    //     printf("Width = %d || Precision = %d\n", width, precision);
    //     ft_printf("FT->%*.*d<\n",width, precision, randonm);
    //     printf("PF->%*.*d<\n",width, precision, randonm);
    //     width++;
    //     precision--;
    // }
    printf("================HEX&OCT&UINT================\n");
    long int long_int = 9999999999;
    long long int   ll_int = 999999999999999999LL;
    unsigned int u_int = 21;
    unsigned long int ul_int = 123456789123456UL;
    unsigned long long ull_int = 12345678912345456653ULL;
    printf("------\n");
    ft_printf("FT->%#6o<\n", 2500);//   "  4704"
    printf("PF->%#6o<\n", 2500); //     " 04704"
    printf("------\n");
    ft_printf("FT->%-5.10o<\n", 2500);//  
    printf("PF->%-5.10o<\n", 2500); //     
    printf("------\n");
    ft_printf("FT->@moulitest: %.o %.0o<\n", 0, 0);//   Fail
    printf("PF->@moulitest: %.o %.0o<\n", 0, 0); //     FAIl
    printf("------\n");
    ft_printf("FT->@moulitest: %5.o %5.0o<\n", 0, 0);//  
    printf("PF->@moulitest: %5.o %5.0o<\n", 0, 0); //     
    printf("------\n");
    ft_printf("FT->%#x<\n", 0);
    printf("PF->%#x<\n", 0);
    printf("------\n");
    ft_printf("FT->@moulitest: %#.x %#.0x<\n", 0, 0);//doesn't know the problem
    printf("PF->@moulitest: %#.x %#.0x<\n", 0, 0);// doesn't know the problem
    printf("------\n");
    ft_printf("FT->@moulitest: %5.x %5.0x<\n", 0, 0);
    printf("PF->@moulitest: %5.x %5.0x<\n", 0, 0);
    printf("------\n");
    ft_printf("FT->%u<\n", u_int);
    printf("PF->%u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%u<\n", u_int);
    printf("PF->%u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%#u<\n", u_int);
    printf("PF->%#u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%#d<\n", u_int);
    printf("PF->%#d<\n", u_int);
    printf("------\n");
    ft_printf("FT->%#015u<\n", u_int);
    printf("PF->%#015u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%# 15u<\n", u_int);
    printf("PF->%# 15u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%+ 15u<\n", u_int);
    printf("PF->%+ 15u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%- 15u<\n", u_int);
    printf("PF->%- 15u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%-# 15u<\n", u_int);
    printf("PF->%-# 15u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%.1u<\n", u_int);
    printf("PF->%.1u<\n", u_int);
    printf("------\n");
    ft_printf("FT->%# 15x<\n", u_int);
    printf("PF->%# 15x<\n", u_int);
    // printf("================POINTEUR================\n");
    // char *str;
    // printf("------\n");
    // ft_printf("FT->%p<\n", &str);
    // printf("PF->%p<\n", &str);
    // printf("------\n");
    // ft_printf("FT->%p<\n", str);
    // printf("PF->%p<\n", str);
    // printf("------\n");
    // ft_printf("FT->%#p<\n", str);
    // printf("PF->%#p<\n", str);
    // printf("------\n");
    // ft_printf("FT->%020p<\n", str);
    // printf("PF->%020p<\n", str);
    // printf("------\n");
    // ft_printf("FT->%+20p<\n", str);
    // printf("PF->%+20p<\n", str);
    // printf("------\n");
    // ft_printf("FT->%-20p<\n", str);
    // printf("PF->%-20p<\n", str);
    // printf("------\n");
    // ft_printf("FT->%-#20p<\n", str);
    // printf("PF->%-#20p<\n", str);
    // printf("------\n");
    // ft_printf("FT->%-#.5p<\n", str);
    // printf("PF->%-#.5p<\n", str);
    // printf("------\n");
    // ft_printf("FT->%# 25.5p<\n", str);
    // printf("PF->%# 25.5p<\n", str);
    // printf("================FLOAT================\n");
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.05);
    // printf("PF->%.1f<-\n", 0.05);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.10);
    // printf("PF->%.1f<-\n", 0.10);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.15);
    // printf("PF->%.1f<-\n", 0.15);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.20);
    // printf("PF->%.1f<-\n", 0.20);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.25);
    // printf("PF->%.1f<-\n", 0.25);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.30);
    // printf("PF->%.1f<-\n", 0.30);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.35);
    // printf("PF->%.1f<-\n", 0.35);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.40);
    // printf("PF->%.1f<-\n", 0.40);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.45);
    // printf("PF->%.1f<-\n", 0.45);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.50);
    // printf("PF->%.1f<-\n", 0.50);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.55);
    // printf("PF->%.1f<-\n", 0.55);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.60);
    // printf("PF->%.1f<-\n", 0.60);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.65);
    // printf("PF->%.1f<-\n", 0.65);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.70);
    // printf("PF->%.1f<-\n", 0.70);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.75);
    // printf("PF->%.1f<-\n", 0.75);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.80);
    // printf("PF->%.1f<-\n", 0.80);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.85);
    // printf("PF->%.1f<-\n", 0.85);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.90);
    // printf("PF->%.1f<-\n", 0.90);
    // printf("------\n");
    // ft_printf("FT->%.1f<-\n", 0.95);
    // printf("PF->%.1f<-\n", 0.95);
    // printf("------\n");
    // ft_printf("FT->%.20f<\n", 0.152321654);
    // printf("PF->%.20f<\n", 0.152321654);
    // printf("------\n");
    // ft_printf("FT->%.20f<\n", 12356789123456.152321654);
    // printf("PF->%.20f<\n", 12356789123456.152321654);
    // printf("------\n");
    // ft_printf("FT->%.2f<\n", 99.999);
    // printf("PF->%.2f<\n", 99.9999);
    // printf("------\n");
    // ft_printf("FT->%-015.2f<\n", 99.999);
    // printf("PF->%-015.2f<\n", 99.9999);
    // printf("------\n");
    // ft_printf("FT->%- 15.2f<\n", 99.999);
    // printf("PF->%- 15.2f<\n", 99.9999);
    // printf("------\n");
    // ft_printf("FT->%.30f<\n", 123456.123456);
    // printf("PF->%.30f<\n", 123456.123456);
    // printf("------\n");
    // ft_printf("FT->%.60f<\n", 17999999999999999780.123456);
    // printf("PF->%.60f<\n", 17999999999999999780.123456);
    // printf("------\n");
    // ft_printf("FT->%.60f<\n", 0.123456);
    // printf("PF->%.60f<\n", 0.123456);
    // printf("================COLOR================\n");
    // char *str;
    // str = "Hello World";
    // printf("------\n");
    // // ft_printf("FT->%s%s%s<\n", "\x1B[31m", str, "\x1B[0m");
    // printf("PF->%s%s%s<\n", "\033[4m", str);
    // printf("================BOOL================\n");
    // t_bool test = true;
    // t_bool test2 = false;
    // printf("------\n");
    // ft_printf("FT->%t<\n", test);
    // ft_printf("FT->%t<\n", test2);
    // printf("================L&LL INT================\n");
    // long long int test_ll = 123456789132456789LL;
    // long int test_l = 123456789132456789L;
    // printf("------\n");
    // ft_printf("FT->%lld<\n", test_ll);
    // printf("PT->%lld<\n", test_ll);
    // printf("------\n");
    // ft_printf("FT->%ld<\n", test_l);
    // printf("PT->%ld<\n", test_l);
    // printf("================SHORT INT================\n");
    // short int test_sh = 128;
    // printf("------\n");
    // ft_printf("FT->%hd<\n", test_sh);
    // printf("PT->%hd<\n", test_sh);
    // printf("------\n");
    // ft_printf("FT->%015hd<\n", test_sh);
    // printf("PT->%015hd<\n", test_sh);
    // printf("================CHAR INT================\n");
    // char  test_sh = -275;
    // printf("------\n");
    // ft_printf("FT->%hhd<\n", test_sh);
    // printf("PT->%hhd<\n", test_sh);
    // printf("------\n");
    // ft_printf("FT->%015hhd<\n", test_sh);
    // printf("PT->%015hhd<\n", test_sh);
    // printf("------\n");
    // ft_printf("FT->%hhd<\n", 148);
    // printf("PT->%hhd<\n", 148);
    // printf("------\n");
    // ft_printf("FT->%015hhd<\n", 2500);
    // printf("PT->%015hhd<\n", 2500);
    // printf("------\n");
    // ft_printf("FT->% 15hhd<\n", 7);
    // printf("PT->% 15hhd<\n", 7);
    // printf("------\n");
    // ft_printf("FT->%.15hhd<\n", 1);
    // printf("PT->%.15hhd<\n", 1);
    // printf("================BINAIRE================\n");
    // int test = 1;
    // char *a = "Hello World";
    // printf("------\n");
    // ft_printf("FT->%b<\n", a);
    // ft_printf("FT->%b<\n", test);





    // int max = __INT_MAX__;
    // int min = -2147483648;
    // int randonm = 73;

    // int precision    = 5;
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
    //     ft_printf("  -FT->%*.*d<\n",width, precision, randonm);
    //     printf("  -PF->%*.*d<\n",width, precision, randonm);
    //     width++;
    //     precision++;
    // }
    system("leaks test > leaksreport.txt");
    return (0);
}
