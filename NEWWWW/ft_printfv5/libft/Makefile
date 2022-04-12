#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 08:08:13 by briffard          #+#    #+#              #
#    Updated: 2022/02/07 14:29:45 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

FILES=	ft_putchar.c		ft_putchar_fd.c		ft_putendl.c		ft_tolower.c\
		ft_putendl_fd.c		ft_putnbr.c			ft_putnbr_fd.c		ft_toupper.c\
		ft_putstr.c			ft_putstr_fd.c		ft_strlen.c			ft_atoi.c	\
		ft_isalpha.c		ft_itoa.c			ft_strjoin.c		ft_bzero.c	\
		ft_isalnum.c		ft_isascii.c		ft_isdigit.c		ft_isprint.c\
		ft_memccpy.c		ft_strnew.c			ft_memcpy.c			ft_memset.c	\
		ft_strcat.c			ft_strchr.c			ft_strcmp.c			ft_strcpy.c	\
		ft_strdup.c			ft_strlcat.c		ft_strncat.c		ft_strncmp.c\
		ft_strncpy.c		ft_strnstr.c		ft_strrchr.c		ft_strstr.c	\
		ft_strequ.c			ft_strnequ.c		ft_strtrim.c		ft_isspace.c\
		ft_strclr.c			ft_strdel.c			ft_strsub.c			ft_striter.c\
		ft_striteri.c		ft_memalloc.c		ft_memchr.c			ft_memcmp.c	\
		ft_memdel.c			ft_memmove.c		ft_strmapi.c		ft_strmap.c	\
		ft_strsplit.c		ft_cleanstr.c		ft_lstnew.c			ft_lstadd.c	\
		ft_lstdelone.c		ft_lstdel.c			ft_color.c			ft_debug.c	\
		ft_putstrcolor.c	ft_putcharcolor.c	ft_error_print.c	ft_itona.c	\
		ft_numlenght.c		ft_randomnbr.c 		ft_display_file.c	ft_fillit.c	\
		get_next_line.c		ft_swap.c			ft_abs_float.c		ft_isupper.c\
		ft_u_itoa.c 		ft_ll_itoa.c		ft_l_itoa.c      ft_u_short_itoa.c\
		ft_abs_int.c 		ft_uitoa_base.c 	ft_reversestr.c \
		ft_charjoin.c 		ft_strtoupper.c		ft_strtoupper.c  ft_str_rounding.c\
		ft_isdoubleneg.c \
		newdlist.c			is_empty_dlist.c	dlist_length.c					\
		dlist_first_end.c	push_back_dlist.c	push_front_dlist.c				\
		pop_back_dlist.c	pop_front_dlist.c 	print_dlist.c					\
		ft_newlst.c\
		#ft_strjoin_replace.c\

INCL=./includes/

OBJ=$(SRC:.c=.o)
RM=rm -f
CC=gcc
CCFLAGS=-Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@$(CC)  -I $(INCL) -c $(FILES) -g
	@echo "Creation of libft"
	@ar rc $(NAME) *.o
	@echo "Libft created."
	@ranlib $(NAME)   

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all clean
