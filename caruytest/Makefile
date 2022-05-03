# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 11:19:44 by cchen             #+#    #+#              #
#    Updated: 2022/05/03 15:27:45 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := test_printf
PRINTF_DIR := /Users/briffard/Desktop/FT_PRINTF/
FT_PRINTF := libftprintf.a

CC := gcc
CFLAGS := -Wall -Werror -Wextra
INCLUDES := -I$(PRINTF_DIR)/libft/includes -I$(PRINTF_DIR)/include -Iincludes
LIB :=  -L$(PRINTF_DIR) -lftprintf

SRC_DIR := ./src
SRC := $(shell find $(SRC_DIR) -type f | grep -E "\.c$$")

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB) $(SRC) -o $@

clean:
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(MAKE) -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all


