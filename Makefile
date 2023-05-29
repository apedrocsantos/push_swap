SRCS = push_swap.c rotate.c swap.c push.c
LIB = -L. -lft
LIBFT = libft.a
PRINTF = libftprintf.a
NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): 
	$(CC) $(SRCS) $(LIB) -o $(NAME) -g

libft: 
	ar x $(LIBFT)
	ar x $(PRINTF)
	ar crs $(LIBFT) *.o
	rm -f *.o 

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all libft fclean re 
