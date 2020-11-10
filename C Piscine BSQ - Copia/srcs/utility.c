#include "bsq.h"

int	ft_atoi(int size)
{
	int ris;
	int i;
	int fd;
	char c;

	ris = 0;
	i = 0;
	if ((fd = open(g_path, O_RDONLY)) == -1)
			return (0);
	while (i < size)
	{
		read(fd, &c, 1);
		ris *= 10;
		ris += (c - '0');
		i++;
	}
	close(fd);
	return (ris);
}
