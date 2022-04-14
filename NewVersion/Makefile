# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 12:13:08 by briffard          #+#    #+#              #
#    Updated: 2022/04/14 16:13:38 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

#COMPILATION
CC		=	gcc
CCFLAGS	=	-Werror -Wextra -Wall -I./libft/includes -Iinclude -g

#CLEAN & FCLEAN
RM_DIR	=	rm -rf
RM		=	rm	-f

#SOURCE FILE
SRC_DIR =	./srcs/
SRC		=	ft_printf.c							\
			struct_init.c						\
			handle_Flag.c error.c				\
			conv_str.c  conv_int.c conv_uint.c conv_p.c 	\
			parse_int.c							\
			utils_funct.c 						\

#OBJECT FILE
OBJ_DIR	=	./objectFiles/
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

all:$(NAME)  

$(NAME):$(OBJS)
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@make -sC ./libft
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CCFLAGS) -o $@ -c $< 

clean:
	@$(RM_DIR) $(OBJ_DIR)
	@make -sC ./libft/ clean
	@echo "Object Files from libft has been deleted"

fclean: clean
	@$(RM_DIR) $(NAME)
	@make -sC ./libft/ fclean
	@echo ".a file from libft has been deleted"

re:fclean all clean