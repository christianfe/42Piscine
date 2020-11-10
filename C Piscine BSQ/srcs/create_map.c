#include "bsq.h"

void	ft_read_stdin()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t lineSize = 0;
	lineSize = getline(&line, &len, stdin);
	g_path = line;
	free(line);
}

int ft_first_row(int fd)
{
	char c;

	read(fd, &c, 1);
	while  (c <= '9' && c >= '0')
		read(fd, &c, 1);
	read(fd, &c, 1);
	if (c != '\n')
	{
		g_map.empty = c;
		read(fd, &c, 1);
	}
	if (c == '\n')
		return (0);
	if (c != '\n')
	{
		g_map.obstacle = c;
		read(fd, &c, 1);
	}
	if (c == '\n')
		return (0);
	if (c != '\n')
	{
		g_map.full = c;
		read(fd, &c, 1);
	}
	return (1);
}

int ft_all_row(int fd)
{
	char	c;
	int		len;

	while  (read(fd, &c, 1))
	{
		if (c != '\n')
		{
			if (g_map.x_size == 0)
				g_map.x_size = len;
			else if (g_map.x_size == len)
				continue;
			else
				return (0);
		}
		if (c != g_map.empty && c != g_map.obstacle && c != '\n')
			return (0);
		len++;
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
	if ((fd = open(g_path, O_RDONLY)) == -1)
		return (0);
	if (!ft_first_row(fd))
		return (0);
	if (!ft_all_row(fd))
		return (0);
	return (1);
}

int		ft_create_map(char *g_path)
{
	if (ft_checkmap())
		return(0);
	if (!g_path)
		ft_read_stdin();
	return(1);
}
