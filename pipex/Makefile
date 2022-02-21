NAME = pipex

SRCS = 	pipex.c find_path.c put_fd.c \
		split_func.c utils_func.c utils_func_two.c

INCLUDE	=	pipex.h

OBJS	=	$(SRCS:.c=.o)

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -I$(INCLUDE)

all		:	$(NAME)

 %.o : %.c	$(INCLUDE)
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME)	:	$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(SRCS) -I ./ -o $(NAME)

clean	:
		@rm -rf $(OBJS)

fclean	:	clean
		@rm -rf $(NAME)

re		:	fclean all

.PHONY: clean fclean re all