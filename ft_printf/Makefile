# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 11:02:57 by briffard          #+#    #+#              #
#    Updated: 2022/02/25 15:04:11 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

FILES	=	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_atoi.c ft_toupper.c ft_memdel.c ft_itoa.c ft_strdup.c	ft_strlen.c	ft_strnew.c	ft_strjoin.c	ft_strsub.c	ft_printf.c

INCL	=	./includes/

OBJ		=	$(FILE:.c=.o)

RM		=	rm -f

CC		=	gcc
CCFLAGS	=	-Wall -Wextra -Werror


all: $(NAME)

$(NAME):
	$(CC) $(CCFLAGS) -I $(INCL) -c $(FILES) 
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
