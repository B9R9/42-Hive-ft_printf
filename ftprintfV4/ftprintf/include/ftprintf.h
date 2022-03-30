/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:33:41 by briffard          #+#    #+#             */
/*   Updated: 2022/03/30 15:12:42 by briffard         ###   ########.fr       */
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
# define flags "scdxXop%ifu"
# define option " .0#+-"
# define maxint 2147483647
# define minint -2147489647
# define maxuint 4294967295
# define maxuchar 128
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
	size_t addspace;
	t_bool	negatif;
	char *sizePrefix;
	t_bool signeneg;
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
// t_bool		optionflag_x(t_parameter li);
// t_bool		optionflag_p(t_parameter li);


typedef t_bool		(*dispachterror)(t_parameter li);

static const dispachterror	funcErrorArray[5] = {
	optionflag_s,
	optionflag_c,
	optionflag_d,
	// optionflag_x,
	// optionflag_p,
};

/*FUNCTION IN DISPACHT FLAG ARRAY*/
char *argtostr(t_parameter li, va_list ap);
char *argtochar(t_parameter li, va_list ap);
char *argtoint(t_parameter li, va_list ap);
char *argtohexoroct(t_parameter li, va_list ap);
char *argtoptraddress(t_parameter li, va_list ap);
char *argtofloat(t_parameter li, va_list ap);
char *argto_u_int(t_parameter li, va_list ap);

typedef char *(*dispachtFlags)(t_parameter li, va_list ap);
// static const dispachtFlags	funcFlagsArray[11] = {
// 	argtostr,
// 	argtochar,
// 	argtoint,
// 	argtohexoroct,
// 	argtohexoroct,
// 	argtohexoroct,
// 	argtoptraddress,
// 	argtochar,
// 	argtoint,
// 	argtofloat,
// 	argto_u_int,
// };

static const dispachtFlags	funcFlagsArray[26] = {
	NULL, //A
	NULL,//B
	argtochar,//C
	argtoint,//D
	NULL,//E
	argtofloat,//F
	NULL,//G
	NULL,//H
	argtoint,//I
	NULL,//J
	NULL,//K
	NULL,//L
	NULL,//M
	NULL,//N
	NULL,//O
	argtoptraddress,//P
	NULL,//Q
	NULL,//R
	argtostr,//S
	NULL,//T
	argto_u_int,//U
	NULL,//V
	NULL,//W
	argtohexoroct,//X
	NULL,//Y
	NULL,//Z
};
/*PROTOTYPE*/
int		ft_printf(const char *format, ...);

/*HANDLE FLAG CHARACTER*/
t_parameter handle_flag(char *str, t_parameter li);
t_parameter handle_width(char *str, t_parameter li, va_list ap);
t_parameter handle_precision(char *str, t_parameter li, va_list ap);
t_parameter handle_size_prefix(char *str, t_parameter li);

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

/*SIZE PREFIX HANDLER*/
/*FLAg D&i*/
char *ll_int_to_arr(t_parameter li, long long number);// peut etre regroupe avec long
char *l_int_to_arr(t_parameter li, long number);
char *short_int_to_arr(t_parameter li, short int number);
char *char_to_arr(t_parameter li, char number);
/*FLAG U*/
char *u_chartoa(t_parameter li, unsigned char number);
char *u_short_intoa(t_parameter li, unsigned short number);
char *u_ll_intoa(t_parameter li, unsigned long long number);
/*FLAG D*/
char *l_doubleToa(t_parameter li, long double number);



/*INIT OPTION STRUCTURE*/
t_parameter		init(const char *format, size_t index, t_parameter li, va_list ap);

/*CHECK OPTIONSYNTAXE ERROR*/
t_bool 	checkoptionerror(t_parameter li);

/*PARSE STRING*/
char *parse_str(char *str, t_parameter li, char *source);
char *addspaces(char *str,t_parameter li, size_t space);
char *ft_reverse_str(char *dest);

# endif