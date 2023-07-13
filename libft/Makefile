# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mikhalil <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/30 15:47:49 by mikhalil      #+#    #+#                  #
#    Updated: 2022/11/12 17:14:52 by mikhalil      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = ft_memcmp.c \
	  ft_strlcpy.c \
	  ft_memcpy.c \
	  ft_strlen.c \
	  ft_atoi.c \
	  ft_memmove.c \
	  ft_strmapi.c \
	  ft_bzero.c \
	  ft_memset.c \
	  ft_strncmp.c \
	  ft_calloc.c \
	  ft_putchar_fd.c \
	  ft_strnstr.c \
	  ft_isalnum.c \
	  ft_putendl_fd.c \
	  ft_strrchr.c \
	  ft_isalpha.c \
	  ft_putnbr_fd.c \
	  ft_strtrim.c \
	  ft_isascii.c \
	  ft_putstr_fd.c \
	  ft_substr.c \
	  ft_isdigit.c \
	  ft_split.c \
	  ft_tolower.c \
	  ft_isprint.c \
	  ft_strchr.c \
	  ft_toupper.c \
	  ft_itoa.c \
	  ft_strdup.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_memchr.c \
	  ft_strlcat.c \
	  ft_lstadd_front_bonus.c \
	  ft_lstnew_bonus.c \
	  ft_lstclear_bonus.c \
	  ft_lstlast_bonus.c \
	  ft_lstsize_bonus.c

OBJ = $(SRC:.c=.o)

#OBJECTS = obj

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
#	mkdir $(OBJECTS)
#	mv $(OBJ) $(OBJECTS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
