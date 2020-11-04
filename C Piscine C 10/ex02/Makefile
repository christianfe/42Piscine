NAME		= ft_tail.c

OBJS		= ${SRCS:.c=.o}

SRCS		= ft_tail.c

OUT			= ft_tail

all:		${OBJS}
			gcc -Wall -Werror -Wextra ${NAME} -o ${OUT}
			rm ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${OUT}

.PHONY:		all clean fclean