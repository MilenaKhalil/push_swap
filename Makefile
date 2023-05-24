# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mikhalil <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/12 17:15:07 by mikhalil      #+#    #+#                  #
#    Updated: 2023/04/25 23:04:54 by mikhalil      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# gcc -Ofast main4.c MLX42/libmlx42.a -o fractol -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit && ./fractol

SRC =	main.c 

LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra 

NAME = push_swap

INCLUDE = -I ./

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all re fclean clean

