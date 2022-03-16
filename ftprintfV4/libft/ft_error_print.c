/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:40:47 by briffard          #+#    #+#             */
/*   Updated: 2022/03/16 11:28:06 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_errormem(char *file, int line)
{
    ft_color("red");
    ft_putstr_fd("In ", 2);
    ft_putstr_fd(file, 2);
    ft_putstr_fd(": line ", 2);
    ft_putnbr_fd(line, 2);
    ft_putstr_fd("\nError: Allocation memory\n", 2);
    ft_color("normal");
}

void    ft_errormes(char *message)
{
    ft_color("red");
    ft_putstr_fd(message, 2);
    ft_putchar('\n');
    ft_color("normal");
}