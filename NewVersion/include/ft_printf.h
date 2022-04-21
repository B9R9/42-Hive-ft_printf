/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:05:56 by briffard          #+#    #+#             */
/*   Updated: 2022/04/20 11:48:17 by briffard         ###   ########.fr       */
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
# define F_HASHTAG 0x80
# define F_ZERO 0x40
# define F_PLUS 0x20
# define F_MINUS 0x10
# define F_SPACE 0x08
# define F_NEGATIF 0x04
# define F_MOD 0x02

# define ARRFLAGS "scdxXop%ifut"

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
	t_bool		dot;// check for the dot
	int			lenght;
	int			precision; // taille dela precision
	int 		char_to_skip; //  nombre de cahr to skip
	char 		sizePrefix[5]; // Sizeprefix conv
	int			size; // taille total de str
}               t_parameter;

/*DISPACHT TABLE*/
/*FUNCTION IN DISPACHT FLAG ARRAY*/
int	conv_to_str(t_parameter *li, va_list ap);
int	conv_to_int(t_parameter *li, va_list ap);
int	conv_to_uint(t_parameter *li, va_list ap); //Voir si la meme que uint
int	conv_to_ptr(t_parameter *li, va_list ap);
int	conv_to_dbl(t_parameter *li, va_list ap);
int	conv_to_void(t_parameter *li, va_list ap);

typedef int (*dispachtFlags)(t_parameter *li, va_list ap);

static const dispachtFlags	funcFlagsArray[26] = {
	NULL,			//A
	conv_to_void,	//B BONUS PRINT EN BINAIRE
	conv_to_int,	//C
	conv_to_int,	//D
	NULL,			//E
	conv_to_dbl,	//F
	NULL,			//G
	NULL,			//H
	conv_to_int,	//I
	NULL,			//J
	NULL,			//K
	NULL,			//L
	NULL,			//M
	NULL,			//N
	conv_to_uint,	//O
	conv_to_ptr,	//P
	NULL,			//Q
	NULL,			//R
	conv_to_str,	//S
	conv_to_int,	//T BONUS BOOLEAN PRINT TRUE OR FALSE
	conv_to_uint,	//U
	NULL,			//V
	NULL,			//W
	conv_to_uint,	//X
	NULL,			//Y
	NULL,			//Z
};

/*PROTOTYPE*/
int ft_printf(const char *format, ...);

/*FUNCTIONS*/
/*STRUCT_INIT.C*/
t_parameter	*init(const char *format,t_parameter *li, va_list ap);

/*PRINT_STR.C*/
int	print_width(t_parameter *option, int lenght);
int	print_str(const char *str, int lenght);
int	print_char(char c);
int	align_right(int start, int lenght);

/*BONUS.C*/
int	is_bonus(const char *s);

/*HANDLE_FLAG*/
t_parameter *handle_flag(char *str, t_parameter *li);
t_parameter *handle_width(char *str, t_parameter *li, va_list ap);
t_parameter *handle_precision(char *str, t_parameter *li, va_list ap);
t_parameter	*handle_size_prefix(char *str, t_parameter *li);

/*ERROR.C*/
t_parameter *checkoptionerror(t_parameter *option);
void		error_message(const char *message);

/*CONV_INT.C*/
int  format_char(t_parameter *option, char c);

/*PRINT_INT.C*/
int		print_int(t_parameter *option, char *str);
void	set_lenght(t_parameter *option, char *str);
int		print_precision(int start, t_parameter *option, int lenght);
int		print_sign(t_parameter *option);
int		print_0x(t_parameter *option);

/*CONV_UINT.C*/
int format_uint(t_parameter *option, unsigned int number);
int	u_ll_itoa(t_parameter *option, unsigned long long int number);

/*handle_sizePrefix_for_flag_d.c*/
int dispach_to_intSizePrefix(t_parameter *option, va_list ap);
int	ll_int_to_arr(t_parameter *option, long long number);
int	short_int_to_arr(t_parameter *option, short int number);
int	char_to_arr(t_parameter *option, char number);


/*UTILS_FUNCT.C*/
int		define_base(t_parameter *option);
int		skip(char *str);
int 	align(char *str, t_parameter *option);

/*UTILS_PRINT_INT.C*/
int		add_character_F_HASTAG(char conv);
int		set_space(t_parameter *option);
int		set_zero(t_parameter *option);
void	adjust_lenght(t_parameter *option, char *str, int to_remove);

/*TO REMOVE*/
void check_parameter(t_parameter *li);
void    check_flasgbit(t_parameter *option);

#endif
