OBJS		= ${SRCS:.c=.o}

SRCS		= ft_tail.c ft_tail_2.c

OUT			= ft_tail

all:		${OBJS}
			gcc -Wall -Werror -Wextra ${SRCS} -o ${OUT}
			rm ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${OUT}

.PHONY:		all clean fclean