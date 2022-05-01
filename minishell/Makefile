NAME = minishell

SRCS 	 = 	main.c minishell.c error.c access_dir.c \
			default_command_utils_1.c default_command_utils_2.c \
			default_command_utils_3.c default_commands_1.c \
			default_commands_2.c default_commands_3.c \
			default_commands_4.c default_commands_5.c \
			exec_pipe.c exec_start.c exec_utils.c \
			free_utils.c parser_main.c parser_utils.c \
			preparser.c redirect.c redirect_input.c \
			redirect_utils.c shell_split.c shell_utils_1.c \
			shell_utils_2.c sig_handlers.c split.c \
			utils_1.c utils_2.c utils_3.c utils_4.c utils_5.c

INCLUDE  = 	minishell.h

READLINE = 	-L/usr/local/lib -I/usr/local/include -lreadline

OBJS	 =	$(SRCS:.c=.o)

CC		 =	clang

CFLAGS	 =	-Wall -Wextra -Werror -I ./

all		 :	$(NAME)

 %.o 	 : %.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	 :	$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(SRCS) -I ./ -o $(NAME) $(READLINE)

clean	 :
			@rm -rf $(OBJS)

fclean	 :	clean
			@rm -rf $(NAME)

re		 :	fclean all

.PHONY	 : clean fclean re all