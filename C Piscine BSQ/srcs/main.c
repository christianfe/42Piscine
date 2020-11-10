#include "bsq.h"

char	*g_path;
t_map	g_map;
int		*g_table;
int		g_start_area;
int		g_area_col;
int		g_area_len;
int		g_area;

void	ft_print_map(void)
{
	int i;

	i = 0;
	while (i < (g_map.x_size * g_map.y_size))
	{
		if (g_table[i] == 2)
			write(1, &g_map.full, 1);
		else if (g_table[i] == 0)
			write(1, &g_map.empty, 1);
		else if (g_table[i] == 1)
			write(1, &g_map.obstacle, 1);
		if ((i + 1) % g_map.x_size == 0)
			write(1, "\n", 1);
		i++;
	}
	write (1, "\n", 1);
}

int		ft_bsq()
{
	if (!ft_create_map())
		return(0);
	printf("Start:%i\tlen:%i\n", g_start_area, g_area_len);
	ft_fullize_map();
	ft_place_x(g_start_area, g_area_len);
	ft_print_map();
	return (1);
}

int		main(int argc, char **argv)
{
	int i;
	
	g_area = 0;
	g_start_area = 0;
	g_area_len = 0;
	if (argc == 1)
	{
		g_path = 0;
		if (!ft_bsq())
		{
			write(2,"map error\n", 10);
			return (0);
		}
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			g_path = argv[i];
			if (!ft_bsq())
			{
				write(2,"map error\n", 10);
				return (0);
			}
			i++;
			free(g_table);
		}
	}
	return (0);
}