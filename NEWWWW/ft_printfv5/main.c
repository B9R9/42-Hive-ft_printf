/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:30:51 by briffard          #+#    #+#             */
/*   Updated: 2022/04/13 17:03:53 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <limits.h>

int main(void)
{
    /*
    ** STR
    ** char    *name;
    ** name = "joe l' indien";
    **
    */
    
    /* 
    ** CHAR
    ** char c = 'a';
    ** ft_printf("  -FT->%025c<\n", c);
    ** printf("  -PF->%025c<\n", c);
    ** ft_printf("  -FT->%c<\n", c);
    ** printf("  -PF->%c<\n", c);
    ** ft_printf("  -FT->% 25c<\n", c);
    **    printf("  -PF->% 25c<\n", c);
    **  ft_printf("  -FT->%-25c<\n", c);
    **  printf("  -PF->%-25c<\n", c);
    **  ft_printf("  -FT->%+25c<\n", c);
    **  printf("  -PF->%+25c<\n", c);
    */
    
    int max = __INT_MAX__;
    int min = -2147483648;
    int randonm = 73;

    int precision    = 5;
    int width       = 0;

    ft_printf("  -FT->%d<\n", max);
    printf("  -PF->%d<\n", max);
    ft_printf("  -FT->%d<\n", min);
    printf("  -PF->%d<\n", min);
    ft_printf("  -FT->%d<\n", randonm);
    printf("  -PF->%d<\n", randonm);

    /*PRECSION ++*/
    while (width <= 20)
    {
        ft_printf("  -FT->%*.*d<\n",width, precision, randonm);
        printf("  -PF->%*.*d<\n",width, precision, randonm); 
        width++;
        precision++;
    }
    system("leaks test > leaksreport.txt");
    return (0);
}