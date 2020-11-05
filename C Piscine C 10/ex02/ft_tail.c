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

char	*g_name_progr;
char	*g_buf;
int		g_fd;
int		g_buffer_size;

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

void	ft_display_file(int fd)
{
	long long	i;
	int			tmp;

	if (g_buffer_size == 0)
	{
		while (read(fd, g_buf, 1))
			if (errno)
				return ;
	}
	else
	{
		i = 0;
		while (read(fd, &g_buf[(i % g_buffer_size)], 1))
		{
			if (errno)
				return ;
			++i;
		}
		tmp = i % g_buffer_size;
		if (i >= g_buffer_size)
			write(1, g_buf + tmp, g_buffer_size - tmp);
		write(1, g_buf, tmp);
	}
}

void	ft_display(int ac, char **av)
{
	int i;
	int k;

	i = 2;
	k = 0;
	while (++i < ac)
	{
		errno = 0;
		if ((g_fd = open(av[i], O_RDONLY)) == -1)
		{
			ft_print_error_msg(av[i], g_name_progr);
			continue ;
		}
		if (ac > 4)
		{
			if (k)
				ft_putstr("\n");
			ft_putstr("==> ");
			ft_putstr(av[i]);
			ft_putstr(" <==\n");
		}
		k = 1;
		ft_display_file(g_fd);
		close(g_fd);
	}
}

int		main(int argc, char **argv)
{
	g_name_progr = argv[0];
	g_buf = argv[2];
	g_buffer_size = ft_atoi(argv[2]);
	g_buf = (char*)malloc(g_buffer_size);
	if (argc == 3)
		ft_display_file(0);
	else
		ft_display(argc, argv);
	free(g_buf);
	return (0);
}
