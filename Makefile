# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/07 18:36:39 by vgurginy          #+#    #+#              #
#    Updated: 2026/02/07 18:36:53 by vgurginy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c \
       ft_print_digit.c \
       ft_print_hex.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I. -I$(LIBFT_DIR)

AR = ar rcs
RM = rm -f

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
