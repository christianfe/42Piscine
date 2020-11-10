#include "bsq.h"
int	g_size_file;

void	ft_read_stdin()
{
	char *line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	g_path = line;
	free(line);
}

int ft_first_row(int fd)
{
	char c;

	read(fd, &c, 1);
	while  (c <= '9' && c >= '0')
		read(fd, &c, 1);
	if (c == '\n')
		return (0);
	g_map.empty = c;
	read(fd, &c, 1);
	if (c == '\n')
		return (0);
	g_map.obstacle = c;
	read(fd, &c, 1);
	g_map.full = c;
	return (1);
}

int ft_all_row(int fd)
{
	char	c;
	int		len;

	len = 0;
	g_map.x_size = 0;
	read(fd, &c, 1);
	while  (read(fd, &c, 1))
	{
		len++;
		g_size_file++;
		if (c == '\n')
		{
			if (g_map.x_size == 0)
				g_map.x_size = len - 1;
			else if (g_map.x_size == len -1)
				;
			else
				return (0);
			len = 0;
		}
		if (c != g_map.empty && c != g_map.obstacle && c != '\n')
			return (0);
	}
	if (c == '\n')
		return (1);
	else
		return (0);
}

int ft_checkmap()
{
	int fd;
	char c;
	int i;

	i = 0;	
	if ((fd = open(g_path, O_RDONLY)) == -1)
		return (0);
	read(fd, &c, 1);
	while  (c <= '9' && c >= '0')
	{
		read(fd, &c, 1);
		i++;
	}
	close(fd);
	g_map.y_size = ft_atoi(i);
	fd = open(g_path, O_RDONLY);
	if (!ft_first_row(fd))
		return (0);
	if (!ft_all_row(fd))
		return (0);
	if (g_map.empty == g_map.full || g_map.obstacle == g_map.full || g_map.empty == g_map.obstacle)
		return (0);
	close(fd);
	return (1);
}

int		ft_create_map()
{
	int		fd;
	char	c;
	int		i;

	i = 0;
	g_size_file = 0;
	if (!g_path)
		ft_read_stdin();
	if (!ft_checkmap())
		return(0);
	printf("@@%i\n", g_size_file);
	if ((g_table = malloc(sizeof(int) * (1 + g_size_file))) == NULL)
		return (0);
	if ((fd = open(g_path, O_RDONLY)) == -1)
		return (0);
	read(fd, &c, 1);
	while (c != '\n')
		read(fd, &c, 1);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			continue;
		if (c == g_map.empty)
			g_table[i] = 0;
		else
			g_table[i] = 1;
		i++;
	}
	close(fd);
	return(1);
}
