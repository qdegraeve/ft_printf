# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 08:41:32 by qdegraev          #+#    #+#              #
#    Updated: 2016/02/10 13:33:07 by qdegraev         ###   ########.fr        #
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

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME) $(LIBPRINT)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ)

$(LIBPRINT):
	ar rc temp.a $(OBJ)
	ranlib temp.a
	libtool -static -o $(LIBPRINT) $(LIB) temp.a

$(LIB):
	make -C $(LIBPATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean: $(OBJ)
	make clean -C $(LIBPATH)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBPATH)
	rm -f $(NAME) $(LIBPRINT) temp.a

re: fclean all

.PHONY: all re clean flcean

