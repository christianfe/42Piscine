OBJS		= ${SRCS:.c=.o}

SRCS		= do_op.c

OUT			= do-op

all:		
			gcc -Wall -Werror -Wextra ${SRCS} -o ${OUT}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${OUT}

re:			fclean all

.PHONY:		all clean fclean re