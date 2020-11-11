/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:08:13 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/11 12:08:14 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char 	*ft_read_stdin()
{
	char *line;
	int i;
	char c;

	line = malloc(sizeof(char) * 1000);
	i = 0;
	read(1, &c, 1);
	while (c != '\n')
	{
		line[i] = c;
		read(1, &c, 1);
		i++;
	}
	line[i] = 0;
	return (line);
}

void	ft_print_map(t_data *t_map)
{
	int i;

	i = 0;
	while (i < t_map->size)
	{
		if (t_map->table[i] == 2)
			write(1, &t_map->full, 1);
		else if (t_map->table[i] == 0)
			write(1, &t_map->empty, 1);
		else if (t_map->table[i] == 1)
			write(1, &t_map->obstacle, 1);
		if ((i + 1) % t_map->x_size == 0)
			write(1, "\n", 1);
		i++;
	}
	t_map->area = 0;
}

int		ft_bsq(t_data *t_map)
{
	if (!ft_create_map(t_map))
		return(0);
	ft_fullize_map(t_map);
	ft_place_x(t_map, t_map->start_area, t_map->area_len, t_map->area_col);
	ft_print_map(t_map);
	return (1);
}

int		main(int argc, char **argv)
{
	int i;
	t_data	t_map;
	
	i = 0;
	t_map.area = 0;
	t_map.start_area = 0;
	t_map.area_len = 0;
	if (argc == 1)
	{
		argv = ft_split(ft_read_stdin(), " ");
		while (argv[i] != 0)
			i++;
		argc = i;
	}
	i = 1;
	while (i < argc)
	{
		t_map.path = argv[i];
		if (!ft_bsq(&t_map))
			write(2,"map error\n", 10);
		i++;
		if (i != argc)
			write (1, "\n", 1);
	}
	return (0);
}
