# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 19:01:07 by joivanau          #+#    #+#              #
#    Updated: 2022/02/09 15:40:07 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_args.c ft_ischeck.c ft_conv.c ftoa.c assign_values.c
SRC += print_float.c print_char.c print_string.c print_signedinteger.c print_hex.c print_pointer.c print_octal.c print_unsignedint.c
OBJ = $(SRC:.c=.o)
CFLAGS = -c -Wall -Werror -Wextra
NAME = libftprintf.a
LIBFTPATH = libft/
all: $(NAME)

$(NAME):
	@make -C $(LIBFTPATH)
	@cc $(CFLAGS) $(SRC) -I $(LIBFTPATH)
	@ar rc $(NAME) $(OBJ) $(LIBFTPATH)*.o
clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
re: fclean all
