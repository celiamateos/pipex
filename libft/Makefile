# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 13:03:04 by cmateos-          #+#    #+#              #
#    Updated: 2023/07/17 19:21:41 by cmateos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEXT = "It 's up to you to figure it out for yourselves!"
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rc
SRC = ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strlen.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strncmp.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strnstr.c \
	  ft_atoi.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew_bonus.c \
	  ft_lstadd_front_bonus.c \
	  ft_lstsize_bonus.c \
	  ft_lstlast_bonus.c \
	  ft_lstdelone_bonus.c \
	  ft_lstclear_bonus.c \
	  ft_lstadd_back_bonus.c \
	  ft_lstiter_bonus.c \
	  ./ft_printf/ft_printf.c \
	  ./ft_printf/ft_putchr_pf.c \
	  ./ft_printf/ft_putstr_pf.c \
	  ./ft_printf/ft_putnbr_pf.c \
	  ./ft_printf/ft_putptr_pf.c \
	  ./ft_printf/ft_puthex.c \
	  ./ft_printf/ft_putun.c
SRC_BONUS = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstiter_bonus.c 
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	ar rc $(NAME) $(OBJ_BONUS) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

Coment:
	echo $(TEXT)
clean:
	rm -rdf $(OBJ)
	rm -rdf $(OBJ_BONUS)

fclean: clean
	rm -rdf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus
