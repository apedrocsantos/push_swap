SRCS = push_swap.c
LIB = -L. -lft
NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME) -g

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re 
