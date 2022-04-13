/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:05:56 by briffard          #+#    #+#             */
/*   Updated: 2022/04/13 15:41:32 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*INCLUDE*/
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h> //---> to remove

/*DEFINE*/
# define F_NEGATIF 0x100
# define F_HASHTAG 0x80
# define F_ZERO 0x40
# define F_PLUS 0x20
# define F_MINUS 0x10
# define F_SPACE 0x08

# define ARRFLAGS "scdxXop%ifu"

// /*ENUM*/
// typedef enum 
// {
// 	false,
// 	true,
// }		t_bool;

typedef unsigned char	t_uchar;

/*STRUCT*/
typedef struct  s_containeur 
{
	char					*box;
	struct s_containeur		*next;
}t_containeur;

typedef struct  s_parameter {
	t_uchar 	flags;	//Store les flags
	int			width; // taille de width
	char		conv; // letter de conv
	t_bool		upper;  // check si le flag est Upper case OK
	int			precision; // taille dela precision
	int 		char_to_skip; //  nombre de cahr to skip
	char 		*sizePrefix; // Sizeprefix conv
	int			size; // taille total de str
}               t_parameter;

/*DISPACHT TABLE*/
/*FUNCTION IN DISPACHT FLAG ARRAY*/
char *argtostr(t_parameter li, va_list ap);
char *argtochar(t_parameter li, va_list ap);
char *argtoint(t_parameter li, va_list ap);
// char *argtohexoroct(t_parameter *li, va_list ap);
// char *argtoptraddress(t_parameter *li, va_list ap);
// char *argtofloat(t_parameter *li, va_list ap);
// char *argto_u_int(t_parameter *li, va_list ap);

typedef char *(*dispachtFlags)(t_parameter li, va_list ap);

static const dispachtFlags	funcFlagsArray[26] = {
	NULL,//A
	NULL,//B
	argtochar,//C
	argtoint,//D
	NULL,//E
	NULL,//F
	NULL,//G
	NULL,//H
	argtoint,//I
	NULL,//J
	NULL,//K
	NULL,//L
	NULL,//M
	NULL,//N
	NULL,//O
	NULL,//P
	NULL,//Q
	NULL,//R
	argtostr,//S
	NULL,//T
	NULL,//U
	NULL,//V
	NULL,//W
	NULL,//X
	NULL,//Y
	NULL,//Z
};

/*PROTOTYPE*/
int ft_printf(const char *format, ...);

/*FUNCTIONS*/
/*STRUCT_INIT.C*/
t_parameter	init(const char *format,t_parameter li, va_list ap);
/*HANDLE_FLAG*/
t_parameter handle_flag(char *str, t_parameter li);
t_parameter handle_width(char *str, t_parameter li, va_list ap);
t_parameter handle_precision(char *str, t_parameter li, va_list ap);
t_parameter handle_size_prefix(char *str, t_parameter li);
/*ERROR.C*/
t_parameter checkoptionerror(t_parameter li);
/*CONV_STR.C*/
char	*setstr(char *dest, t_parameter li, char *source);
/*PARSE_INT.C*/
char    *parse_int(t_parameter li, char *source);

/*handle_sizePrefix_for_flag_d.c*/
char    *ll_int_to_arr(t_parameter li, long long number);
char    *l_int_to_arr(t_parameter li, long number);
char    *short_int_to_arr(t_parameter li, short int number);
char    *char_to_arr(t_parameter li, char number);
 
/*UTILS_FUNCT.C*/
char	*align_right(char *dest);
int		skip(char *str);
/*UTILS_LIST.C*/
t_containeur	*newlist(void);
t_bool			is_empty(t_containeur *li);
t_containeur	*push_back(t_containeur *li, char *str);
t_containeur	*pop_front(t_containeur *li);
t_containeur	*clearlist(t_containeur *li);

/*TO REMOVE*/
void check_parameter(t_parameter li);

#endif
