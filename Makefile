# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 11:19:02 by briffard          #+#    #+#              #
#    Updated: 2022/02/28 09:40:42 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#EXECUTABLE
NAME		=		test

#HEADER FILE
SRCS		=		main.c
SRCS_DIR	=		./srcs/

OBJ_DIR		=		./objects/
OBJ			=		$(addprefix $(OBJ-DIR), $(SRCS;.c=.o))

#LIBFT Library
INCL_LIBFT	=	./libft/includes/
LIBFT		=	./libft/ -lft

#FT_PRINTF Library
INCL_FT_PRINTF	=	./ft_printf/includes/
LFT_PRINTF		=	./ft_printf/ -lftprintf

#COMPILATION
CC			=	gcc
CCFLAGS		=	-Werror -Wextra -Wall

#DELETE
RM			=	rm -f
RM_D		=	rm -rf

all: $(NAME)

$(NAME):
	make -C ft_printf/ fclean && make -C ft_printf/
	$(CC) $(CCFLAGS) -I$(INCL_FT_PRINTF) -o $@  ./srcs/main.c  -L $(LFT_PRINTF)

clean:
	$(RM_d) $(OBJ_DIR)
	make -C ft_printf/ clean

fclean:
	$(RM) $(NAME)
	make -C ft_printf/ fclean

re: fclean all

.PHONY: all clean fclean re
