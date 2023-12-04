CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = endgame.c push_swap_utils.c push_swap_utils2.c instructions.c instructions2.c sort.c sort2.c pnum_utils.c pnum_utils2.c print_arrays.c sort_three.c insertion.c insertion2.c partition_init.c check_input.c arr_utils.c make_array.c small_n.c
NAME_SRC = push_swap.c
BONUS_SRCS = checker_bonus.c
INCLUDES = ft_printf.h libft.h push_swap.h get_next_line.h
LIBFT = ./libft/libft.a
BONUSNAME = checker

OBJS = $(SRCS:.c=.o) $(LIBFT)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
all: $(NAME) $(BONUS)

$(NAME) : $(OBJS) $(LIBFT)
	cc $(OBJS) $(NAME_SRC) $(CFLAGS) -o $@

$(OBJS) : $(SRCS)

$(BONUSNAME) : $(BONUS_OBJS) $(LIBFT) $(OBJS)
	cc $(BONUS_OBJS) $(LIBFT) $(OBJS) $(CFLAGS) -o $@

$(LIBFT):
	make -C ./libft/

bonus : $(BONUSNAME)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)
	make clean -C ./libft/

fclean: clean
	rm -rf $(NAME) $(BONUSNAME)
	make fclean -C ./libft/

re: fclean all
