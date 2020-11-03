NAME		= ft_display_file.c

OBJS		= ${SRCS:.c=.o}

SRCS		= ft_display_file.c

OUT			= ft_display_file

all:
			${OBJS}
			gcc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJS}

fclean:
			clean
			rm -f ${NAME}
