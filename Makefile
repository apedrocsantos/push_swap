SRCS =	rules.c\
		check_duplicates.c\
		print_stacks.c\
		utils.c\
		ft_free.c\
		check_sorted_list.c\
		check_sorted_nbr.c\
		check_digit.c\
		create_list.c\
		sort_small.c\
		put_back.c\
		order_stack.c\
		minmax.c\
		check_maxmin.c\
		main.c

LIB = -L . -lft
INCLUDES= -I ./includes
NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
VPATH=src

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(INCLUDES)  $^ $(LIB) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re 


