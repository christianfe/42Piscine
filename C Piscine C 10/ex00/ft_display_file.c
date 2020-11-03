#include <unistd.h>
#include <fcntl.h>

void	ft_display_file(char *path)
{
	int		file_des;
	char	curchar;

	file_des = open(path, O_RDONLY);
	if (file_des == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	while (read(file_des, &curchar, 1))
		write(1, &curchar, 1);
	close (file_des);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc == 2)
		ft_display_file(argv[1]);
	else
		write(2, "Too many arguments.\n", 20);
	return (0);
}