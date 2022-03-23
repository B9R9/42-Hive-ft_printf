/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:33:41 by briffard          #+#    #+#             */
/*   Updated: 2022/03/23 09:18:31 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

/*INCLUDES*/
#include <stdlib.h>
#include <stdio.h> // Should be remove before return the project
#include <stdarg.h> // Allow you  to use va_arg
#include <unistd.h>
#include "libft.h"

/*DEFINE*/
# define flags "scdxXop%if"
# define option " .0#+"
# define hexa "0123456789abcdef"

/*TYPEDEF*/
// typedef enum{
// 	false,
// 	true
// }		t_bool;

typedef struct	s_parameter {
	
	t_bool	hastag; 
	t_bool	positif;
	t_bool	space; 
	t_bool	zero;
	t_bool	dot;
	t_bool	star;
	size_t	width; 
	char	flag; 
	t_bool	upper;  // check si le flag est Upper case OK
	size_t	precision;
	int 	char_to_skip;
	size_t	size;
	t_bool	negatif;
	// int		contentsize;
}			t_parameter;


typedef struct s_containeur {
	
	char					*box;
	// struct t_parameter		parameter;
	struct s_containeur		*next;
}	t_containeur;


/*FUNCTION IN DISPACHTERROR ARRAY*/
t_bool		optionflag_s(t_parameter li);
t_bool		optionflag_c(t_parameter li);
t_bool		optionflag_d(t_parameter li);
t_bool		optionflag_x(t_parameter li);
t_bool		optionflag_p(t_parameter li);


typedef t_bool		(*dispachterror)(t_parameter li);

static const dispachterror	funcErrorArray[5] = {
	optionflag_s,
	optionflag_c,
	optionflag_d,
	optionflag_x,
	optionflag_p,
};


/*FUNCTION IN DISPACHTOPTION ARRAY*/
t_parameter				setupspace(t_parameter li, char *str, va_list ap);
t_parameter				setupprecision(t_parameter li, char *str, va_list ap);
t_parameter				setupstar(t_parameter li, char *str, va_list ap);
t_parameter				setupzero(t_parameter li, char *str, va_list ap);
t_parameter				setuphastag(t_parameter li, char *str, va_list ap);
t_parameter				setupnum(t_parameter li, char *str, va_list ap);
t_parameter				setuppositif(t_parameter li, char *str, va_list ap);
// Missing pour  le caratetre -
// missing l,ll,h et hhdi
//
typedef t_parameter		(*dispachtoption)(t_parameter li, char *str, va_list ap);

static const dispachtoption	funcOption[5] = {
	setupspace,
	setupprecision,
	setupzero,
	setuphastag,
	setuppositif,
};

/*FUNCTION IN DISPACHT FLAG ARRAY*/
char *argtostr(t_parameter li, va_list ap);
char *argtochar(t_parameter li, va_list ap);
char *argtoint(t_parameter li, va_list ap);
char *argtohexoroct(t_parameter li, va_list ap);
char *argtoptraddress(t_parameter li, va_list ap);
char *argtofloat(t_parameter li, va_list ap);

typedef char *(*dispachtFlags)(t_parameter li, va_list ap);
static const dispachtFlags	funcFlagsArray[10] = {
	argtostr,
	argtochar,
	argtoint,
	argtohexoroct,
	argtohexoroct,
	argtohexoroct,
	argtoptraddress,
	argtochar,
	argtoint,
	argtofloat,
};

/*PROTOTYPE*/
int		ft_printf(const char *format, ...);

/*UTIL LIST*/
t_containeur	*newlist(void);
t_containeur	*push_back(t_containeur *li, char *str);
t_containeur	*push_front(t_containeur *li, char *str);
t_containeur	*pop_back(t_containeur *li);
t_containeur	*pop_front(t_containeur *li);
t_containeur	*clearlist(t_containeur *li);
t_bool			is_empty(t_containeur *li);
int				list_lenght(t_containeur *li);
void			printlist(t_containeur *li);
int				skip(char *str);
char			*revstr(char *str);



/*INIT OPTION STRUCTURE*/
t_parameter		init(const char *format, size_t index, t_parameter li, va_list ap);

/*CHECK OPTIONSYNTAXE ERROR*/
t_bool 	checkoptionerror(t_parameter li);




# endif