/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:30:51 by briffard          #+#    #+#             */
/*   Updated: 2022/04/15 09:57:30 by briffard         ###   ########.fr       */
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

    // printf("================INT================\n");
    // int max = __INT_MAX__;
    // int min = -2147483648;
    // int randonm = 73;
    // int precision    = 10;
    // int width       = 0;
    // printf("------\n");
    // ft_printf("FT->%d<\n", max);
    // printf("PF->%d<\n", max);
    // printf("------\n");
    // ft_printf("FT->%d<\n", min);
    // printf("PF->%d<\n", min);
    // printf("------\n");
    // ft_printf("FT->%d<\n", randonm);
    // printf("PF->%d<\n", randonm);
    // printf("------\n");
    // ft_printf("FT->%+015d<\n", randonm);
    // printf("PF->%+015d<\n", randonm);
    // printf("------\n");
    // ft_printf("FT->%+ 15d<\n", randonm);
    // printf("PF->%+ 15d<\n", randonm);
    // printf("------\n");
    // ft_printf("FT->%- 15d<\n", randonm);
    // printf("PF->%- 15d<\n", randonm);
    // printf("------\n");
    // ft_printf("FT->%-15d<\n", randonm);
    // printf("PF->%-15d<\n", randonm);
    // printf("------\n");
    // ft_printf("FT->%-015d<\n", randonm);
    // printf("PF->%-015d<\n", randonm);

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
    // printf("================HEX&OCT&UINT================\n");
    // int randonm = 73;
    // long int long_int = 9999999999;
    // long long int   ll_int = 999999999999999999LL;
    // unsigned int u_int = 21;
    // unsigned long int ul_int = 123456789123456UL;
    // unsigned long long ull_int = 12345678912345456653ULL;

    // printf("------\n");
    // ft_printf("FT->%u<\n", u_int);
    // printf("PF->%u<\n", u_int);
    // printf("------\n");
    // ft_printf("FT->%#u<\n", u_int);
    // printf("PF->%#u<\n", u_int);
    // printf("------\n");
    // ft_printf("FT->%#d<\n", u_int);
    // printf("PF->%#d<\n", u_int);
    // printf("------\n");
    // ft_printf("FT->%#015u<\n", u_int);
    // printf("PF->%#015u<\n", u_int);
    // printf("------\n");
    // ft_printf("FT->%# 15u<\n", u_int);
    // printf("PF->%# 15u<\n", u_int);
    // printf("------\n");
    // ft_printf("FT->%+ 15u<\n", u_int);
    // printf("PF->%+ 15u<\n", u_int);
    // printf("------\n");
    // ft_printf("FT->%- 15u<\n", u_int);
    // printf("PF->%- 15u<\n", u_int);
    // printf("------\n");
    // ft_printf("FT->%-# 15u<\n", u_int);
    // printf("PF->%-# 15u<\n", u_int);
    // printf("------\n");
    // ft_printf("FT->%.1u<\n", u_int);
    // printf("PF->%.1u<\n", u_int);
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
    printf("================FLOAT================\n");  
    printf("------\n");
    ft_printf("FT->%#.5f<\n", 0.152);
    printf("PF->%#.5f<\n", 0.152);
    printf("------\n");
    ft_printf("FT->%.20f<\n", 0.152321654);
    printf("PF->%.20f<\n", 0.152321654);
    printf("------\n");
    ft_printf("FT->%.20f<\n", 12356789123456.152321654);
    printf("PF->%.20f<\n", 12356789123456.152321654);

    
    
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