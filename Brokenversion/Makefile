# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 12:46:55 by briffard          #+#    #+#              #
#    Updated: 2022/04/04 14:17:53 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE		=	test

OBJ		=	$(FILE:.c=.o)

#libftprintf
FTPRINTF		= lftprintf
FTPRINTF_DIR	= ./ftprintf/
FTPRINTF_INCL	= ./ftprintf/include

#LIBFT
LIBFT		= lft
LIBFT_DIR	= ./libft/
LIBFT_INCL	= ./libft/includes

RM		=	rm -f
CC		=	gcc
CFLAGS	=	#-Werror -Wextra -Wall

all:  $(LIBFT) $(FTPRINTF) $(EXE) 
	
$(EXE):
	rm -f $(EXE)
	@$(CC)   -I$(FTPRINTF_INCL) -I$(LIBFT_INCL) -o main.o -c main.c 
	@$(CC)   -o $(EXE) main.o -L$(LIBFT_DIR) -lft -L$(FTPRINTF_DIR) -lftprintf  

$(FTPRINTF):
	$(MAKE) -C$(FTPRINTF_DIR)

$(LIBFT):
	$(MAKE) -C$(LIBFT_DIR)
clean:
	$(MAKE) -C$(LIBFT_DIR) clean
	$(MAKE) -C$(FTPRINTF_DIR) clean
	$(RM)	*.o

fclean: clean
	$(MAKE) -C$(LIBFT_DIR) fclean
	$(MAKE) -C$(FTPRINTF_DIR) fclean
	$(RM)	-f $(EXE)

re: fclean all

.PHONY: clean, fclean, re