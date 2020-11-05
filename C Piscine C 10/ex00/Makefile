NAME		= ft_display_file.c

OBJS		= ${SRCS:.c=.o}

SRCS		= ft_display_file.c

OUT			= ft_display_file

all:		${OBJS}
			gcc -Wall -Werror -Wextra -o ${OUT} ${OBJS}
			rm ${OBJS}

${NAME}:	all

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${OUT}

re:			fclean all

.PHONY:		${NAME} all clean fclean re