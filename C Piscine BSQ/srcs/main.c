#include "bsq.h"

char *g_path;
t_map g_map;

int		ft_bsq()
{
	if (!ft_create_map())
		return(0);
	return (1);
}

int		main(int argc, char **argv)
{
	int i;
	
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

		}
		printf("%s", g_path);
	}
	return (0);
}