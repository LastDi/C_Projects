
SRCS	=	ft_printf.c		ft_libnbr.c

OBJS	= 	${SRCS:.c=.o}

NAME	= 	libftprintf.a

CC		= 	gcc

CFLAGS	= 	-Wall -Wextra -Werror

RM		= 	rm -f

HEAD	= 	-I /

.c.o:	
			${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			@ranlib ${NAME}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
