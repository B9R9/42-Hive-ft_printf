/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:46:23 by briffard          #+#    #+#             */
/*   Updated: 2022/02/22 16:32:55 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

/*INCLUDES*/

# include <stdio.h> //A retirer
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/*DEFINE*/
#define hexa "0123456789abcdef"

/*ENUM*/
typedef enum
{
	false,
	true
}t_bool;

/*PROTOTYPE*/

int	ft_printf(const char *str, ...);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
char 	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
void	ft_memdel(void **ap);
int		ft_toupper(int c);

#endif
