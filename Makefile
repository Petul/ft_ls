# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 13:02:00 by pleander          #+#    #+#              #
#    Updated: 2025/04/01 18:44:19 by pleander         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_ls
CC := gcc
CFLAGS := -Wall -Wextra -g #-Werror
CFILES := main.c config.c ft_ls.c error.c sort.c print.c parse_args.c mode.c link.c
INCLUDES := libft/include

LIBFT := libft/libft.a

OBJECTS := $(CFILES:.c=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS)
	make clean -C libft

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	make fclean -C libft

.PHONY: re
re: fclean all
