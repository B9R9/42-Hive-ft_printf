/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:30:51 by briffard          #+#    #+#             */
/*   Updated: 2022/04/13 12:40:59 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int main(void)
{
    char    *name;

    name = "joe l' indien";
    ft_printf("  -FT->%-25.10s<\n", name);
    printf("  -PF->%-25.10s<\n", name);
    system("leaks test > leaksreport.txt");
    return (0);
}