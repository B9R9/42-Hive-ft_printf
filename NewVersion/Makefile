# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 12:13:08 by briffard          #+#    #+#              #
#    Updated: 2022/04/15 13:22:42 by briffard         ###   ########.fr        #
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
			conv_str.c  conv_int.c conv_uint.c conv_p.c conv_f.c \
			conv_void.c \
			parse_int.c							\
			handle_sizePrefix_for_flag_d.c		\
			handle_sizePrefix_flag_u.c			\
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
	@echo "FT_PRINTF: Object Files directory has been deleted"
	@make -sC ./libft/ clean

fclean: clean
	@$(RM) $(NAME)
	@echo "libftprintf.a file has been deleted"
	@make -sC ./libft/ fclean

re:fclean all clean
