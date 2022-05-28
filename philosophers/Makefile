NAME	=	philo

SRCS	=	actions.c free.c init.c \
			philo.c print.c utils.c

HEADER	=	philo.h

OBJS	 =	$(SRCS:.c=.o)

CC		 =	clang

CFLAGS	 =	-pthread -Wall -Wextra -Werror -I ./

all		 :	$(NAME)

 %.o 	 : %.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	 :	$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(SRCS) -I ./ -o $(NAME) $(READLINE)

clean	 :
			@rm -rf $(OBJS)

fclean	 :	clean
			@rm -rf $(NAME)

re		 :	fclean all

.PHONY	 : clean fclean re all


