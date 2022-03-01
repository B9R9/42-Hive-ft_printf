/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:02:19 by briffard          #+#    #+#             */
/*   Updated: 2022/03/01 16:24:59 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

/*INCLUDES*/
# include <stdio.h>		// A RETIRER
# include <stdarg.h>	// PERMET LES FUNCTION VARIADIQUES
# include <unistd.h>
# include <stdlib.h>

/*DEFINE*/
# define flags		"sdicfxXoup%"
# define hexa		"0123456789abcdef"
# define MAX_INT	2147483647
# define MIN_INT	-2147489647
# define MAX_U_INT	4294967295

/*ENUM*/
typedef enum
{
	false,
	true
}		t_bool;

/*STRUCT*/
typedef struct	s_parameter
{
	int size;
	int contentsize;

}				t_parameter;

/*PROTOTYPE*/
int	ft_printf(const char *format, ...);

/*INITIALISATION DE LA STRUCTURE*/
t_parameter	init(const char *format, int index, t_parameter li);

/*UTILS FUNCTION*/
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_memdel(void ** ap);
#endif