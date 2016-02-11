# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 08:41:32 by qdegraev          #+#    #+#              #
#    Updated: 2016/02/11 21:35:03 by qdegraev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

LIBPRINT = libftprintf.a

LIBPATH = libft
LIB = $(LIBPATH)/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L libft -lft

SRC = ft_printf.c \
	types.c \
	arg_length.c \
	flags.c \
	ft_putnbru.c \

OBJ = $(SRC:.c=.o)

all: $(LIB) $(LIBPRINT) $(NAME)

$(NAME): $(LIBPRINT)
	$(CC) $(CFLAGS) $(LDFLAGS) -L. -lftprintf -o $@ main.c

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBPRINT): $(OBJ)
	ar rc temp.a $(OBJ)
	ranlib temp.a
	libtool -static -o $(LIBPRINT) $(LIB) temp.a

$(LIB):
	make -C $(LIBPATH)

clean:
	make clean -C $(LIBPATH)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBPATH)
	rm -f $(NAME) $(LIBPRINT) temp.a

re: fclean all

.PHONY: all re clean flcean

