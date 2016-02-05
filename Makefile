# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 08:41:32 by qdegraev          #+#    #+#              #
#    Updated: 2016/02/05 12:41:40 by qdegraev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIBPATH = libft
LIB = $(LIBPATH)/libft.a

NAME = ft_prinft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I libft

LDFLAGS = -L libft -lft

SRC = ft_prinft.c 

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	libtool -static -o libftprintf.a $(LIB) $(NAME)

$(LIB):
	make -C $(LIBPATH)

clean: $(OBJ)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean flcean

