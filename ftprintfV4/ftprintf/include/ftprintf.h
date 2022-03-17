/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:33:41 by briffard          #+#    #+#             */
/*   Updated: 2022/03/17 08:15:30 by briffard         ###   ########.fr       */
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
# define flags "scdifxXoup%"
# define option " .*0#<+-"

/*TYPEDEF*/
// typedef enum{
// 	false,
// 	true
// }		t_bool;

typedef struct	s_parameter {
	t_bool	space;
	size_t	spacelenght;
	t_bool	dot;
	size_t	dotlenght;
	t_bool	star;
	t_bool	zero;
	size_t	zerolenght;
	t_bool	hastag;
	t_bool	signe;
	char	flag;
	size_t	size;
	int		contentsize;
}			t_parameter;


typedef struct s_containeur {
	
	char					*box;
	// struct t_parameter		parameter;
	struct s_containeur		*next;
}	t_containeur;


/*FUNCTION IN DISPACHTERROR ARRAY*/
t_parameter		optionflag_s(t_parameter li);
t_parameter		optionflag_c(t_parameter li);


typedef t_parameter		(*dispachterror)(t_parameter li);

static const dispachterror	funcErrorArray[2] = {
	optionflag_s,
	optionflag_c,
};


/*FUNCTION IN DISPACHTOPTION ARRAY*/
t_parameter				setupspace(t_parameter li, char *str);
t_parameter				setupdot(t_parameter li, char *str);
t_parameter				setupstar(t_parameter li, char *str);
t_parameter				setupzero(t_parameter li, char *str);
t_parameter				setuphastag(t_parameter li, char *str);
t_parameter				setupnum(t_parameter li, char *str);
t_parameter				setupsigned(t_parameter li, char *str);
// Missing pour  le caratetre -
// missing l,ll,h et hhdi
//
typedef t_parameter		(*dispachtoption)(t_parameter li, char *str);

static const dispachtoption	funcOption[7] = {
	setupspace,
	setupdot,
	setupstar,
	setupzero,
	setuphastag,
	setupnum,
	setupsigned,
};

/*FUNCTION IN DISPACHT FLAG ARRAY*/
char *argtostr(t_parameter li, va_list ap);
char *argtochar(t_parameter li, va_list ap);

typedef char *(*dispachtFlags)(t_parameter li, va_list ap);
static const dispachtFlags	funcFlagsArray[2] = {
	argtostr,
	argtochar,
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

/*INIT OPTION STRUCTURE*/
t_parameter		init(const char *format, size_t index, t_parameter li, va_list ap);

/*CHECK OPTIONSYNTAXE ERROR*/
t_parameter 	checkoptionerror(t_parameter li);




# endif