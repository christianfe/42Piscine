OBJS		= ${SRCS:.c=.o}

SRCS		= ft_tail.c ft_tail_2.c

NAME		= ft_tail

all:		${NAME}

${NAME}:	${OBJS}
			gcc -Wall -Werror -Wextra ${SRCS} -o ${NAME}
			rm ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re ${NAME}
