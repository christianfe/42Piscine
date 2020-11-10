SRCS		= ft_tail.c ft_tail_2.c

OBJS		= ${SRCS:.c=.o}

NAME		= ft_tail

FLAGS		= -Wall -Wextra -Werror

CC			= gcc

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${SRCS} -o ${NAME}
			rm -f ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

all:		${NAME}

.PHONY:		all clean fclean re ${NAME} .c.o
