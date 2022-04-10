NAME		=	so_long

SRCS		=	so_long.c utils.c put_fd.c ft_split.c \
				move_funcs.c map_funcs.c \

LIBA		=	libmlx_linux.a

INCLUDE		=	so_long.h

CC			=	clang

FLAGS		=	-g -Wall -Wextra -Werror -I$(INCLUDE) -I$(MLX_H)

MLX_DIR		=	/usr/local/lib/

MLX_H		=	/usr/local/include/mlx.h

LIBS		= 	-L$(MLX_DIR) -L/usr/lib -lmlx -lXext -lX11 -lm -lz


OBJS		=	$(SRCS:c=o)

 %.o : %.c
				$(CC) $(FLAGS) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean		:
				@rm -f $(OBJS)

fclean: 		clean
				@rm -f $(NAME)

re			:	fclean all

.PHONY 		= 	all clean fclean re


