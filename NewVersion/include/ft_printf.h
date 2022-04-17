/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:05:56 by briffard          #+#    #+#             */
/*   Updated: 2022/04/15 14:19:12 by briffard         ###   ########.fr       */
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

# define ARRFLAGS "scdxXop%ifut"

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
	t_bool		negatif; // check if number is negatif
	int			precision; // taille dela precision
	int 		char_to_skip; //  nombre de cahr to skip
	char 		sizePrefix[5]; // Sizeprefix conv
	int			size; // taille total de str
}               t_parameter;

/*DISPACHT TABLE*/
/*FUNCTION IN DISPACHT FLAG ARRAY*/
int	argtostr(t_parameter *li, va_list ap);
int	argtochar(t_parameter *li, va_list ap);
int	argtoint(t_parameter *li, va_list ap);
int	argtohexoroct(t_parameter *li, va_list ap); //Voir si la meme que uint
int	argto_u_int(t_parameter *li, va_list ap);
int	argtoptr(t_parameter *li, va_list ap);
int	argtofloat(t_parameter *li, va_list ap);
int	argtovoid(t_parameter *li, va_list ap);

typedef int (*dispachtFlags)(t_parameter *li, va_list ap);

static const dispachtFlags	funcFlagsArray[26] = {
	NULL,			//A
	argtovoid,	//B BONUS PRINT EN BINAIRE
	argtochar,		//C
	argtoint,		//D
	NULL,			//E
	argtofloat,		//F
	NULL,			//G
	NULL,			//H
	argtoint,		//I
	NULL,			//J
	NULL,			//K
	NULL,			//L
	NULL,			//M
	NULL,			//N
	argtohexoroct,	//O
	argtoptr,		//P
	NULL,			//Q
	NULL,			//R
	argtostr,		//S
	argtoint,		//T BONUS BOOLEAN PRINT TRUE OR FALSE
	argto_u_int,	//U
	NULL,			//V
	NULL,			//W
	argtohexoroct,	//X
	NULL,			//Y
	NULL,			//Z
};

/*PROTOTYPE*/
int ft_printf(const char *format, ...);

/*FUNCTIONS*/
/*STRUCT_INIT.C*/
t_parameter	*init(const char *format,t_parameter *li, va_list ap);
/*HANDLE_FLAG*/
t_parameter *handle_flag(char *str, t_parameter *li);
t_parameter *handle_width(char *str, t_parameter *li, va_list ap);
t_parameter *handle_precision(char *str, t_parameter *li, va_list ap);
t_parameter	*handle_size_prefix(char *str, t_parameter *li);
/*ERROR.C*/
t_parameter *checkoptionerror(t_parameter *li);
/*CONV_STR.C*/
// char	*setstr(char *dest, t_parameter li, char *source);
/*PARSE_INT.C*/
int format_intoa(t_parameter *option, char *dest);
int print_intwidth(t_parameter *option, int lenght);
int print_intprecsion(int start, t_parameter *option, int lenght);
int ajust_lenght(t_parameter *option, int lenght);
int print_0x(t_parameter *option);
/*CONV_HEX*/
int format_uint(t_parameter *option, unsigned int number);
int	define_base(t_parameter *option);

/*handle_sizePrefix_for_flag_d.c*/
int	ll_int_to_arr(t_parameter *option, long long number);
int	u_ll_itoa(t_parameter *option, unsigned long long int number);
// char    *l_int_to_arr(t_parameter li, long number);
int	short_int_to_arr(t_parameter *option, short int number);
int	char_to_arr(t_parameter *option, char number);

/*UTILS_FUNCT.C*/
int		align_right(int start, int lenght);
int		skip(char *str);
int		print_char(char c);
int		print_width(t_parameter *option, int lenght);
int		print_str(const char *str, int lenght);

/*UTILS_LIST.C*/
// t_containeur	*newlist(void);
// t_bool			is_empty(t_containeur *li);
// t_containeur	*push_back(t_containeur *li, char *str);
// t_containeur	*pop_front(t_containeur *li);
// t_containeur	*clearlist(t_containeur *li);

/*TO REMOVE*/
void check_parameter(t_parameter *li);

#endif
