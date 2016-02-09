# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 08:41:32 by qdegraev          #+#    #+#              #
#    Updated: 2016/02/09 19:12:57 by qdegraev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

LIBPATH = libft
LIB = $(LIBPATH)/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L libft -lft

SRC = ft_printf.c 

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

$(LIB):
	make -C $(LIBPATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean: $(OBJ)
	make clean -C $(LIBPATH)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBPATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean flcean

