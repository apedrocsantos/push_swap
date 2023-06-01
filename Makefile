SRCS =	rotate.c\
		swap.c\
		push.c\
		check_duplicates.c\
		main.c

LIB = -L. -lft
INCLUDES= -I ./includes
LIBFT = ./libft/libft.a
PRINTF = ./libft/libftprintf.a
NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
VPATH=src

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(INCLUDES)  $^ $(LIB) -o $(NAME) -g

libft:	
	make -C ./libft
	ar x $(LIBFT)
	ar x $(PRINTF)
	ar crs $(LIBFT) *.o
	rm *.o
	rm -f ./libft/*.o 

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all libft fclean re 


