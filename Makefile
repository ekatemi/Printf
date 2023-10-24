# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 18:44:04 by emikhayl          #+#    #+#              #
#    Updated: 2023/10/24 19:39:06 by emikhayl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES = ft_printf.h

SOURCES = ft_printf.c ft_putnbrhex.c ft_putstr.c ft_putnbr.c ft_putnbru.c

OBJECTS = $(SOURCES:.c=.o)

COMPILER = gcc

CFLAGS = -Wall -Wextra -Werror

# Metodo implicito
%.o: %.c	$(INCLUDES) Makefile
	$(COMPILER) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

# Mis metodos
all: 	$(NAME)

$(NAME): $(OBJECTS) 
	ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
