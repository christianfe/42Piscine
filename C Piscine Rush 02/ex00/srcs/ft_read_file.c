/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 08:10:10 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/07 08:10:11 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	g_row_find;
int	g_i;

char	*ft_find_world_file(int len, int fd)
{
	char	char_read;
	char	*world;

	g_i = 1;
	while (g_i != len)
	{
		read(fd, &char_read, 1);
		if (char_read == '\n')
			g_i++;
	}
	read(fd, &char_read, 1);
	while (char_read == ' ' || char_read == ':' ||
		(char_read >= '0' && char_read <= '9'))
		read(fd, &char_read, 1);
	g_i = 0;
	if (!(world = malloc(sizeof(char) * 100)))
		return (0);
	ft_list_push_back(g_to_free, world);
	while (char_read != '\n')
	{
		world[g_i] = char_read;
		read(fd, &char_read, 1);
		g_i++;
	}
	return (world);
}

int		ft_read_file(char *path, char *to_find, int size)
{
	int fd;
	int ris;

	fd = open(path, O_RDONLY);
	ris = ft_is_in_file(fd, to_find, size);
	close(fd);
	if (!ris)
		return (ris);
	fd = open(path, O_RDONLY);
	ft_list_push_back(g_result, ft_find_world_file(ris, fd));
	close(fd);
	return (ris);
}
