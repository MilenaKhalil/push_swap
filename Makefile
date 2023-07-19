# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mikhalil <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/12 17:15:07 by mikhalil      #+#    #+#                  #
#    Updated: 2023/07/19 17:34:42 by mikhalil      ########   odam.nl          #
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

obj_dir = obj

OBJ_REG = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

HEADER = push_swap_bonus.h

NAME_REG = push_swap

NAME_BONUS = checker

ifdef WITH_BONUS
	OBJ = $(OBJ_BONUS)
	HEADER = push_swap_bonus.h
	NAME = $(NAME_BONUS)
else
	OBJ = $(OBJ_REG)
	HEADER = push_swap.h
	NAME = $(NAME_REG)
endif

OBJ := $(addprefix $(obj_dir)/, $(OBJ))

all: $(obj_dir) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(obj_dir):
	mkdir -p $(obj_dir)

$(obj_dir)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(LIBFT) $(obj_dir) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@

clean:
	rm -rf $(obj_dir)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME_REG) $(NAME_BONUS)
	$(MAKE) fclean -C libft

bonus:
	$(MAKE) WITH_BONUS=1 all

re: fclean all

.PHONY: all re fclean clean bonus
