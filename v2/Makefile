# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 11:02:57 by briffard          #+#    #+#              #
#    Updated: 2022/03/03 14:57:12 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

FILES	=	ft_printf.c		structinit.c		ft_memdel.c		ft_strsub.c	\
			setupoption.c	setuprecision.c	ft_strlen.c		ft_atoi.c	\

INCL	=	./includes/

OBJ		=	$(FILE:.c=.o)

RM		=	rm -f

CC		=	gcc
CCFLAGS	=	-Wall -Wextra -Werror


all: $(NAME)

$(NAME):
	@$(CC) $(CCFLAGS) -I $(INCL) -c $(FILES) 
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

test:
	@$(CC) $(CCFLAGS) -I $(INCL) -o test main.c -L . -lftprintf
	@./test


clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)
	$(RM) test

re: fclean all

.PHONY: all clean fclean re
