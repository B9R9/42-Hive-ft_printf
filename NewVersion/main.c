/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:30:51 by briffard          #+#    #+#             */
/*   Updated: 2022/04/14 12:26:15 by briffard         ###   ########.fr       */
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

    printf("================INT================\n");
    int max = __INT_MAX__;
    int min = -2147483648;
    int randonm = 73;
    int precision    = 10;
    int width       = 0;
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
    printf("------\n");
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

    /*PRECSION ++*/
    while (width <= 20)
    {
        printf("------\n");
        printf("Width = %d || Precision = %d\n", width, precision);
        ft_printf("FT->%*.*d<\n",width, precision, randonm);
        printf("PF->%*.*d<\n",width, precision, randonm); 
        width++;
        precision--;
    }
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