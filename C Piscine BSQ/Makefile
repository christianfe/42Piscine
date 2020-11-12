NAME		= bsq

OBJS		= ${SRCS:.c=.o}

SRCS		= srcs/main.c srcs/ft_split.c srcs/create_map.c srcs/calculate_area.c srcs/ft_calculate_area.c srcs/utility.c

FLAGS		= -Wall -Wextra -Werror -g

CC		= gcc

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}
			rm ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re ${NAME} norm .c.o
