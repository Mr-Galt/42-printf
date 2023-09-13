# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mheinke <mheinke@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 14:06:28 by mheinke           #+#    #+#              #
#    Updated: 2023/09/12 11:05:31 by mheinke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                DIRECTORIES                                   #
# **************************************************************************** #

HEADER 		= ft_printf.h
SRC 		= ft_printf.c printf_char.c printf_string.c printf_ptr.c \
				printf_nbr.c printf_hex.c printf_uint.c
OBJS 		= $(SRC:.c=.o)

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME 		= libftprintf.a
CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra
LIB_PATH 	= ./libft 
LIBFT 		= $(LIB_PATH)/libft.a

# **************************************************************************** #
#                                   TARGETS                                    #
# **************************************************************************** #

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIB_PATH) all 

%.o: %.c  $(HEADER)
	$(CC) -c $(CFLAGS) -I ./ $< -o $@  


fclean: clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME)	

clean:
	rm -f $(OBJS)
	make -C $(LIB_PATH) clean

re: fclean all

.PHONY: all clean fclean re