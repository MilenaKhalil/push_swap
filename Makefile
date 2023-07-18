# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mikhalil <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/12 17:15:07 by mikhalil      #+#    #+#                  #
#    Updated: 2023/07/18 20:37:25 by mikhalil      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC =	main.c \
		commands.c \
		push_swap.c \
		utils.c \
		utils_mand.c \
		exit.c

SRC_BONUS =	commands.c \
			utils.c \
			main_bonus.c \
			exit.c

LIBFT = ./libft/libft.a

OBJ_REG = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ = $(OBJ_BONUS)

CFLAGS = -Wall -Werror -Wextra

HEADER = push_swap_bonus.h

ifdef WITH_BONUS
	OBJ = $(OBJ_BONUS)
	HEADER = push_swap_bonus.h
	NAME = checker
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

$(NAME): $(LIBFT) $(OBJ)
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

.PHONY: all re fclean clean bonus
