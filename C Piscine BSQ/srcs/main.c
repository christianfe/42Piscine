#include "bsq.h"

char *g_path;
t_map g_map;

void	ft_bsq(char *g_path)
{
	if(g_path)
		ft_create_map(g_path);
	else
		ft_create_map(0);
}

int		main(int argc, char **argv)
{
	int i;
	
	if (argc == 1)
	{
		ft_bsq(0);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			ft_bsq(argv[i]);
			i++;
			printf("%s", g_path);
		}
	}
	printf("%s", g_path);
	return (0);
}