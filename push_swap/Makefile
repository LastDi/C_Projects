NAME = push_swap

NAME_B = checker

SRCS =		push_swap.c free_func.c init_stack_func.c \
			manipulation_func.c push_func.c small_sort_func.c \
			sort_func.c sort_rules_part_one.c sort_rules_part_two.c \
			utils_func.c validate_func.c

SRCS_B = 	z_free_func_bonus.c z_get_next_line_bonus.c z_get_next_line_utils_bonus.c \
			z_init_stack_func_bonus.c z_push_swap_bonus.c z_sort_rules_part_one_bonus.c \
			z_sort_rules_part_three_bonus.c z_sort_rules_part_two_bonus.c z_start_checker_bonus.c \
			z_validate_func_bonus.c

INCLUDE_B = z_push_swap_bonus.h

INCLUDE = push_swap.h

OBJS	=	$(SRCS:.c=.o)

OBJS_B	=	$(SRCS_B:.c=.o)

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -I ./

all		:	$(NAME)

 %.o : %.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(SRCS) -I ./ -o $(NAME)

clean	:
			@rm -rf $(OBJS)
			@rm -rf $(OBJS_B)

fclean	:	clean
			@rm -rf $(NAME)
			@rm -rf $(NAME_B)

re		:	fclean all

bonus	:	$(OBJS_B) $(INCLUDE_B)
			$(CC) $(CFLAGS) $(SRCS_B) -I ./ -o $(NAME_B)

.PHONY: clean fclean re all