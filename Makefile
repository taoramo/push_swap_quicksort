CC = cc
CFLAGS = -g -c -Wall -Wextra -Werror
NAME = push_swap
SRCS = endgame.c push_swap_utils.c instructions.c instructions2.c push_swap.c  sort.c pnum_utils.c print_arrays.c
INCLUDES = ft_printf.h libft.h push_swap.h
LIBFT = ./libft/libft.a
BONUSNAME = checker

OBJS = $(SRCS:.c=.o)
all: $(NAME)

bonus : $(BONUSNAME)

$(BONUSNAME) : $(NAME)
	cp $(NAME) $(BONUSNAME)

$(NAME) : $(LIBFT) $(OBJS)

$(OBJS) : $(LIBFT)
	cc $(CFLAGS) $(SRCS)

$(LIBFT):
	make -C ./libft/

clean:
	rm -rf $(OBJS)
	make clean -C ./libft/

fclean: clean
	rm -rf $(NAME) $(BONUSNAME)
	make fclean -C ./libft/

re: fclean all
