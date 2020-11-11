/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:27:04 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/04 13:27:06 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>

void	ft_putstr(char *str);
void	ft_print_error_msg(char *file, char *program_name);

int		ft_atoi(char *str)
{
	int ris;
	int sign;

	ris = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' ||
			*str == '\r' || *str == '\t' || *str == '\v')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		ris *= 10;
		ris += (*str - '0');
		str++;
	}
	return (ris * sign);
}

void	ft_display_file(int fd, int *buffer_size, char *buf)
{
	long long	i;
	int			tmp;

	if (*buffer_size == 0)
	{
		while (read(fd, buf, 1))
			if (errno)
				return ;
	}
	else
	{
		i = 0;
		while (read(fd, &buf[(i % *buffer_size)], 1))
		{
			if (errno)
				return ;
			++i;
		}
		tmp = i % *buffer_size;
		if (i >= *buffer_size)
			write(1, buf + tmp, *buffer_size - tmp);
		write(1, buf, tmp);
	}
}

void	ft_display(int ac, char **av, int *buffer_size, char *buf)
{
	int i[2];
	int	fd;

	i[0] = 2;
	i[1] = 0;
	while (++i[0] < ac)
	{
		errno = 0;
		if ((fd = open(av[i[0]], O_RDONLY)) == -1)
		{
			ft_print_error_msg(av[i[0]], av[0]);
			continue ;
		}
		if (ac > 4)
		{
			if (i[1])
				ft_putstr("\n");
			ft_putstr("==> ");
			ft_putstr(av[i[0]]);
			ft_putstr(" <==\n");
		}
		i[1] = 1;
		ft_display_file(fd, buffer_size, buf);
		close(fd);
	}
}

int		main(int argc, char **argv)
{
	int		buffer_size;
	char	*buf;

	buf = argv[2];
	buffer_size = ft_atoi(argv[2]);
	buf = (char*)malloc(buffer_size);
	if (argc == 3)
		ft_display_file(0, &buffer_size, buf);
	else
		ft_display(argc, argv, &buffer_size, buf);
	free(buf);
	return (0);
}
