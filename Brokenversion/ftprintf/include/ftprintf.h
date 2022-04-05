/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:33:41 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 15:41:10 by briffard         ###   ########.fr       */
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
# define ARRFLAGS "scdxXop%ifu"
# define option " .0#+-"
# define hexa "0123456789abcdef"

# define F_NEGATIF 0x100
# define F_HASHTAG 0x80
# define F_ZERO 0x40
# define F_PLUS 0x20
# define F_MINUS 0x10
# define F_SPACE 0x08

typedef unsigned char	t_uchar;
typedef struct	s_parameter {
	t_uchar 	flags;	//Store les flags
	int			width; // taille de width
	char		conv; // letter de conv
	t_bool		upper;  // check si le flag est Upper case OK
	int			precision; // taille dela precision
	int 		char_to_skip; //  nombre de cahr to skip
	char 		*sizePrefix; // Sizeprefix conv
	int			size; // taille total de str
	// char		char_to_print;
}			t_parameter;

typedef struct s_containeur {
	
	char					*box;
	struct s_containeur		*next;
}	t_containeur;

/*FUNCTION IN DISPACHT FLAG ARRAY*/
char *argtostr(t_parameter li, va_list ap);
char *argtochar(t_parameter li, va_list ap);
char *argtoint(t_parameter li, va_list ap);
char *argtohexoroct(t_parameter li, va_list ap);
char *argtoptraddress(t_parameter li, va_list ap);
char *argtofloat(t_parameter li, va_list ap);
char *argto_u_int(t_parameter li, va_list ap);

typedef char *(*dispachtFlags)(t_parameter li, va_list ap);

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
	argtohexoroct,//O
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

/*INIT OPTION STRUCTURE*/
t_parameter		init(const char *format, size_t index, t_parameter li, va_list ap);

/*HANDLE FLAG CHARACTER*/
t_parameter handle_flag(char *str, t_parameter li);
t_parameter handle_width(char *str, t_parameter li, va_list ap);
t_parameter handle_precision(char *str, t_parameter li, va_list ap);
t_parameter handle_size_prefix(char *str, t_parameter li);
t_parameter checkoptionerror(t_parameter li);

/*SIZE PREFIX HANDLER*/
/*Flag D&i*/
char *ll_int_to_arr(t_parameter li, long long number);// peut etre regroupe avec long
char *l_int_to_arr(t_parameter li, long number);
char *short_int_to_arr(t_parameter li, short int number);
char *char_to_arr(t_parameter li, char number);
/*FlAG U*/
char *u_chartoa(t_parameter li, unsigned char number);
char *u_short_intoa(t_parameter li, unsigned short number);
char *u_ll_intoa(t_parameter li, unsigned long long number);
/*FlAG D*/
char *l_doubleToa(t_parameter li, long double number);
/*Flag X&O*/
char    *char_to_hex_or_oct(t_parameter li, char number);
char    *short_int_to_hex_or_oct(t_parameter li, short  int number);
char    *l_int_to_hex_or_oct(t_parameter li, long int number);
char    *ll_int_to_hex_or_oct(t_parameter li, long long int number);

/*SET STR*/
char 	*parse_str(char *str, t_parameter li, char *source);
char    *parse_int(t_parameter li, char *source);
char	*parse_ptr(t_parameter li, char *source);
char    *parse_hexa_or_oct(t_parameter li, char *source);

/*UTILS*/
/*utils _list*/
t_containeur	*newlist(void);
t_containeur	*push_back(t_containeur *li, char *str);
// t_containeur	*push_front(t_containeur *li, char *str);
// t_containeur	*pop_back(t_containeur *li);
t_containeur	*pop_front(t_containeur *li);
t_containeur	*clearlist(t_containeur *li);
t_bool			is_empty(t_containeur *li);
// void			printlist(t_containeur *li);
/*utils_funct*/
int				skip(char *str);
char 			*align_right(char *dest);


# endif