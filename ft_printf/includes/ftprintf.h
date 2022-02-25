/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:46:23 by briffard          #+#    #+#             */
/*   Updated: 2022/02/25 15:25:18 by briffard         ###   ########.fr       */
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
#define maxint 2147483647
#define minint -2147489647
#define maxuint 4294967295


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
char	*ft_itoa(long long n);
void	ft_memdel(void **ap);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
