/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:30:51 by briffard          #+#    #+#             */
/*   Updated: 2022/04/12 17:21:47 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int main(void)
{
    char    *name;

    name = "joe l' indien";
    ft_printf("-FT->%s\n", name);
    system("leaks test > leaksreport.txt");
    return (0);
}