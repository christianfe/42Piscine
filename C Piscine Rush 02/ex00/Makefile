NAME		= rush-02

OBJS		= ${SRCS:.c=.o}

SRCS		= srcs/main.c srcs/ft_fts.c srcs/utility.c srcs/ft_find_nbr.c srcs/ft_list.c srcs/ft_read_file.c srcs/ft_check_dict.c

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

norm:
			norminette -R CheckForbiddenSourceHeader */*.c
			norminette -R CheckDefine */*.h

.PHONY:		all clean fclean re ${NAME} norm .c.o
