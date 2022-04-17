/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:40:47 by briffard          #+#    #+#             */
/*   Updated: 2022/04/04 09:32:17 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    ft_errormem(char *file, int line)
{
    ft_putstr_fd("In ", 2);
    
    ft_putstr_fd(file, 2);
    ft_putstr_fd(": line ", 2);
    ft_putnbr_fd(line, 2);
    ft_color("red");
    ft_putstr_fd("\nError",2);
    ft_color("normal");
    ft_putstr_fd(": Allocation memory\n", 2);
    return (1);
}

int    ft_errormes(char *message)
{
    ft_color("red");
    ft_putstr_fd(message, 2);
    ft_putchar('\n');
    ft_color("normal");
    return (1);
}