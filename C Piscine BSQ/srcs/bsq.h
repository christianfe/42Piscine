#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_map
{
	int		x_size;
	int		y_size;
	char	full;
	char	empty;
	char	obstacle;
}				t_map;

extern char		*g_path;
extern t_map	g_map;
extern int		*g_table;

int		ft_atoi(int size);
int		ft_create_map();

#endif