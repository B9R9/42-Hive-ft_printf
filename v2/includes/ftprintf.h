/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:02:19 by briffard          #+#    #+#             */
/*   Updated: 2022/03/02 13:40:17 by briffard         ###   ########.fr       */
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
# define option		" .*0#<"
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
	t_bool 	space;
	char	flag;
	int		lenght;
	int		optionlenght;
	int 	size;
	int 	contentsize;
}				t_parameter;


/*ARRAY TO POINTER SUR FUNCTION*/
/*FUNCTION IN DISPACHTOPTION ARRAY*/
t_parameter				setupspace(t_parameter li, char *str);

typedef t_parameter		(*dispachtoption)(t_parameter li, char *str);

static const dispachtoption	funcOption[1] = {
	setupspace,
	//setupdot,
	//setupstart,
//	setupzero,
//	setuphastag,
//	setupnum,
};


/*PROTOTYPE*/
int	ft_printf(const char *format, ...);

/*INITIALISATION DE LA STRUCTURE*/
t_parameter	init(const char *format, int index, t_parameter li);

/*FUNCTION IN DISPACHTOPTION ARRAY*/
//t_parameter	setupspace(t_parameter li, char *str);

/*UTILS FUNCTION*/
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_memdel(void ** ap);
#endif