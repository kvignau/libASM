# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvignau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 10:04:06 by kvignau           #+#    #+#              #
#    Updated: 2018/05/17 13:44:54 by kvignau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a

H_DIR = includes/
S_DIR = srcs/
O_DIR = obj/

NASM = nasm -f macho64
CC = gcc
FLAGS = -Wall -Werror -Wextra

S_FILES = ft_bzero.s
S_FILES += ft_strcat.s
S_FILES += ft_isalpha.s
S_FILES += ft_isdigit.s
S_FILES += ft_isalnum.s
S_FILES += ft_isascii.s
S_FILES += ft_isprint.s
S_FILES += ft_toupper.s
S_FILES += ft_tolower.s
S_FILES += ft_puts.s
S_FILES += ft_strlen.s
S_FILES += ft_memset.s
S_FILES += ft_memcpy.s
S_FILES += ft_strdup.s
S_FILES += ft_cat.s


O_FILES = $(addprefix $(O_DIR),$(S_FILES:.s=.o))

all: $(NAME)

$(NAME): $(O_FILES)
	ar rc $@ $^
	ranlib $@

$(O_FILES): $(O_DIR)%.o: $(S_DIR)%.s
	@mkdir $(O_DIR) 2> /dev/null || echo "" > /dev/null
	$(NASM) $< -o $@

test: $(NAME) main.c
	$(CC) -c main.c $(FLAG)
	$(CC) -o test main.o libfts.a $(FLAG)

clean:
	@rm -rf $(O_DIR) main.o 2> /dev/null || echo "" > /dev/null

fclean: clean
	@rm -rf $(NAME) test 2> /dev/null || echo "" > /dev/null

re: fclean all

.PHONY: all clean fclean re test
