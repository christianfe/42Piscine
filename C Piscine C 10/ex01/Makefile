NAME		= ft_cat.c

OBJS		= ${SRCS:.c=.o}

SRCS		= ft_cat.c

OUT			= ft_cat

all:		${OBJS}
			gcc -Wall -Werror -Wextra ${NAME} -o ${OUT}
			rm ${OBJS}

${NAME}:	all

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${OUT}

re:			fclean all

.PHONY:		${NAME} all clean fclean re 