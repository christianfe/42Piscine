OBJS		= ${SRCS:.c=.o}

SRCS		= srcs/do_op.c srcs/ft_op.c srcs/ft_program_adds.c

NAME		= do-op

FLAGS		= -Wall -Wextra -Werror -g

CC			= gcc

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all:		${OBJS}
			${CC} -o ${NAME} ${OBJS}
			rm ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re ${NAME}