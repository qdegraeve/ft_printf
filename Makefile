# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 08:41:32 by qdegraev          #+#    #+#              #
#    Updated: 2016/02/08 12:35:54 by qdegraev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_prinft

LIBPATH = libft
LIB = $(LIBPATH)/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L libft -lft

SRC = ft_printf.c 

OBJ = $(SRC:.c=.o)

all: $(NAME) $(LIB)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

$(LIB):
	make -C $(LIBPATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean flcean

