NAME		= ft_cat.c

OBJS		= ${SRCS:.c=.o}

SRCS		= ft_cat.c

OUT			= ft_cat

all:		${OBJS}
			gcc -Wall -Werror -Wextra ${NAME} -o ${OUT}
			rm ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${OUT}

.PHONY:		all clean fclean