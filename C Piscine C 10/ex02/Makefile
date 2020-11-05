OBJS		= ${SRCS:.c=.o}

SRCS		= ft_tail.c ft_tail_2.c

NAME		= ft_tail

all:		${OBJS}
			gcc -Wall -Werror -Wextra ${SRCS} -o ${NAME}
			rm ${OBJS}

${NAME}		all

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${OUT}

re:			fclean all

.PHONY:		${NAME} all clean fclean re