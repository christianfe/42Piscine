/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:27:04 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/04 13:27:06 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>

char	*g_name_progr;

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_print_error_msg(char *file)
{
	ft_putstr(basename(g_name_progr));
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	errno = 0;
}

void	ft_display_file(int fd, char *path)
{
	char	curchar;

	while (read(fd, &curchar, 1))
	{
		if (errno)
		{
			ft_print_error_msg(path);
			return ;
		}
		write(1, &curchar, 1);
	}
}

int		main(int argc, char **argv)
{
	int	fd;
	int	i;

	g_name_progr = argv[0];
	if (argc == 1)
		ft_display_file(0, 0);
	else
	{
		i = 0;
		while (++i < argc)
		{
			if ((fd = open(argv[i], O_RDONLY)) == -1)
			{
				ft_print_error_msg(argv[i]);
				continue ;
			}
			ft_display_file(fd, argv[i]);
			close(fd);
		}
	}
	return (0);
}