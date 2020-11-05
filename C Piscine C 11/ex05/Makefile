NAME		= do-op.c

OBJS		= ${SRCS:.c=.o}

SRCS		= fd-op.c

OUT			= do-op

all:		
			gcc -Wall -Werror -Wextra ${NAME} -o ${OUT}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${OUT}

re:			fclean all

.PHONY:		all clean fclean re