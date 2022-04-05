#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 08:08:13 by briffard          #+#    #+#              #
#    Updated: 2022/03/15 13:45:58 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

FILES	=	ft_printf.c \
			structinit.c \
			util_list.c utils_funct.c \
			conv_str.c conv_char.c conv_u_int.c conv_int.c conv_hex_or_oct.c \
			conv_p.c conv_f.c \
			error.c \
			set_str.c\
			handle_flag_char.c \
			handle_sizePrefix_for_flag_d.c \
			handle_sizePrefix_for_flag_u.c \
			handle_sizePrefix_for_flag_x_o.c \


OBJ		=	$(SRC:.c=.o)
INCL	=	./include/
LIBFT_INCL = ../libft/includes/
RM		=	rm
CC		=	gcc
CCFLAGS	=	#-Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling..."
	@$(CC)   -I $(INCL) -I$(LIBFT_INCL) -c $(FILES) 
	@echo "Creation of lftprintf"
	@ar rc $(NAME) *.o
	@echo "lftprintf created."
	@ranlib $(NAME)

clean:
	$(RM) -f *.o
fclean: clean
	$(RM) $(NAME)

re: fclean all