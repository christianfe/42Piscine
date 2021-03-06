/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:07:51 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/11 12:07:53 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_first_row(t_data *t_map, int fd)
{
	char c;

	read(fd, &c, 1);
	while (c <= '9' && c >= '0')
		read(fd, &c, 1);
	if (c == '\n')
		return (0);
	t_map->empty = c;
	read(fd, &c, 1);
	if (c == '\n')
		return (0);
	t_map->obstacle = c;
	read(fd, &c, 1);
	t_map->full = c;
	return (1);
}

int		ft_all_row2(t_data *t_map, char *c, int *len, int *row)
{
	if (*c == '\n')
	{
		if (t_map->x_size == 0)
			t_map->x_size = *len - 1;
		else if (t_map->x_size == *len - 1)
			;
		else
			return (0);
		*len = 0;
		*row += 1;
	}
	return (1);
}

int		ft_all_row(t_data *t_map, int fd, int *size)
{
	char	c;
	int		len;
	int		row;

	len = 0;
	row = 0;
	t_map->x_size = 0;
	while (read(fd, &c, 1))
	{
		len++;
		*size += 1;
		if (!ft_all_row2(t_map, &c, &len, &row))
			return (0);
		if (c != t_map->empty && c != t_map->obstacle && c != '\n')
			return (0);
	}
	if (row - 1 != t_map->y_size)
		return (0);
	if (c == '\n')
		return (1);
	else
		return (0);
}

int		ft_checkmap(t_data *t_map, int *size)
{
	int		fd;
	char	c;
	int		i;

	i = 0;
	if ((fd = open(t_map->path, O_RDONLY)) == -1)
		return (0);
	read(fd, &c, 1);
	while (c <= '9' && c >= '0')
	{
		read(fd, &c, 1);
		i++;
	}
	close(fd);
	t_map->y_size = ft_atoi(t_map, i);
	fd = open(t_map->path, O_RDONLY);
	if (!ft_first_row(t_map, fd))
		return (0);
	if (!ft_all_row(t_map, fd, size))
		return (0);
	if (t_map->empty == t_map->full || t_map->obstacle == t_map->full ||
		t_map->empty == t_map->obstacle)
		return (0);
	close(fd);
	return (1);
}

void	ft_assign_map(t_data *t_map, int fd, int i)
{
	char c;

	while (read(fd, &c, 1))
	{
		if (c == t_map->empty)
			t_map->table[i] = 0;
		else if (c == t_map->obstacle)
			t_map->table[i] = 1;
		if (c != '\n')
			i++;
	}
}
