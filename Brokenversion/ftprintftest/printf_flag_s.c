/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:25:47 by briffard          #+#    #+#             */
/*   Updated: 2022/03/17 09:36:12 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
    char    *empty;
    char    *space;
    char    *nonprint;
    char    *signe;
    char    *percent;
    char    *regularstr;
    char    *mixstr;
    char    *multiple1;
    char    *multiple2;
    
    multiple1 = "Tant va la cruche a l' eau,";
    multiple2 = "qu' a la fin, elle se casse";
    mixstr = "   \tHello %%! 6542,\\5 ~";
    regularstr = "This is a regular string.";
    percent = "%%%%";
    signe = "!@#$%%^&*()_+}{||:<";
    nonprint = "\n\t\r\v";
    empty = "";
    space = "     ";
    
    printf("%s\n", empty);
    printf("%s\n", space);
    printf("%s\n", nonprint);
    printf("%s\n", signe);
    printf("%s\n", percent);
    printf("%s\n", regularstr);
    printf("%s\n", mixstr);
    printf("%s\n%s\n", multiple1, multiple2);
    return (0);
}