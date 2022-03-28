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

FILES	=	ft_printf.c structinit.c util_list.c  setupoption.c setuprecision.c\
			conv_str.c  error.c      conv_char.c  conv_int.c   inttohexoroct.c \
			pointertoa.c ftoa.c		ft_u_inttoa.c handle_flag_char.c          \
			parse_str.c   \

OBJ		=	$(SRC:.c=.o)
INCL	=	./include/
LIBFT_INCL = ../libft/includes/
RM		=	rm
CC		=	gcc
CCFLAGS	=	-Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling..."
	@$(CC) $(CCFLAGS) -I $(INCL) -I$(LIBFT_INCL) -c $(FILES)
	@echo "Creation of lftprintf"
	@ar rc $(NAME) *.o
	@echo "lftprintf created."
	@ranlib $(NAME)
	@clear 

clean:
	$(RM) -f *.o
fclean: clean
	$(RM) $(NAME)

re: fclean all