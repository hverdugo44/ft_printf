# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 13:04:03 by hverdugo          #+#    #+#              #
#    Updated: 2024/10/27 15:06:50 by hverdugo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

FILES = ft_printf.c ft_printf_utils.c hexadecimalxm.c hexadecimal.c puntero.c

INCLUDE = ft_printf.h

AR = ar rsc

flags = -Wall -Wextra -Werror

LIBFT = libft

OFILES = $(FILES:.c=.o)

all: makelibft $(NAME)

makelibft:
	make -C $(LIBFT)


$(NAME): $(OFILES) $(INCLUDE) Makefile
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OFILES)

%.o: %.c
	cc $(flags) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -rf $(OFILES)

fclean:
	make fclean -C $(LIBFT)
	rm -rf $(NAME) $(OFILES)

re:	
	make fclean
	make all

.PHONY: all, clean, fclean, re
