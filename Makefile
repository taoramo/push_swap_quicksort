CC = cc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = endgame.c push_swap_utils.c instructions.c instructions2.c push_swap.c  sort.c sort2.c pnum_utils.c pnum_utils2.c print_arrays.c sort_three.c insertion.c insertion2.c partition_init.c check_input.c arr_utils.c make_array.c small_n.c
INCLUDES = ft_printf.h libft.h push_swap.h
LIBFT = ./libft/libft.a
BONUSNAME = checker

OBJS = $(SRCS:.c=.o) $(LIBFT)
all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)

$(OBJS) : $(SRCS)

$(LIBFT):
	make -C ./libft/

clean:
	rm -rf $(OBJS)
	make clean -C ./libft/

fclean: clean
	rm -rf $(NAME) $(BONUSNAME)
	make fclean -C ./libft/

re: fclean all
