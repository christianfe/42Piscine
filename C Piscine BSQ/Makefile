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

do:			
			./gen/generator.pl 10 10 20 > ./gen/mapf
			./gen/generator.pl 10 10 3 > ./gen/map
			./gen/generator.pl 5 12 4 > ./gen/map1
			./gen/generator.pl 7 5 3 > ./gen/map2
			./gen/generator.pl 50 20 5 > ./gen/map3
			./${NAME} "./gen/map" "./gen/map1" "./gen/map2" "./gen/map3" ./gen/mapf

run:
			./${NAME} "./gen/map"

norm:
			norminette -R CheckForbiddenSourceHeader */*.c
			norminette -R CheckDefine */*.h

.PHONY:		all clean fclean re ${NAME} norm .c.o