NAME		= ft_cat.c

OBJS		= ${SRCS:.c=.o}

SRCS		= ft_cat.c

OUT			= ft_cat

all:		${OBJS}
			gcc -Wall -Werror -Wextra -o ${OUT} ${OBJS}
			rm ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${OUT}

.PHONY:		clean fclean all
