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

SRC =	main.c \
		commands.c \
		push_swap.c \
		utils.c

SRC_BONUS =	commands.c \
			utils.c

LIBFT = ./libft/libft.a

OBJ_REG = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra 

ifdef (WITH_BONUS)
	OBJ = $(OBJ_BONUS)
	HEADER = push_swap_bonus.h
	NAME = push_swap_bonus
else
	OBJ = $(OBJ_REG)
	HEADER = push_swap.h
	NAME = push_swap
endif

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ_REG) $(OBJ_BONUS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

bonus:
	$(MAKE) WITH_BONUS=1 all

re: fclean all

.PHONY: all re fclean clean

