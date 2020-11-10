#include "bsq.h"

char	*g_path;
t_map	g_map;
int		*g_table;
int		g_start_area;
int		g_area;

int		ft_bsq()
{
	if (!ft_create_map())
		return(0);
	ft_calculate_area();
	return (1);
}

int		main(int argc, char **argv)
{
	int i;
	
	g_area = 0;
	g_start_area = 0;
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
		printf("%s", g_path);
	}
	return (0);
}