/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_area.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:08:00 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/11 12:08:01 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int 	ft_calculate_area(t_data *t_map)
{
	int i;
	int area;
	
	i = 0;
	area = 0;
	while (i < t_map->size)
	{
		if (t_map->table[i] == 2)
			area++;
		i++;
	}
	return (area);
}

void	ft_free_array(t_data *t_map)
{
	int i;

	i = 0;
	while (i < (t_map->size))
	{
		if (t_map->table[i] == 2)
			t_map->table[i] = 0;
		i++;
	}
}

int		ft_is_free(t_data *t_map, int pos, int offset)
{
	return (t_map->table[pos + offset] == 0);
}

int		ft_is_border(t_data *t_map, int pos, char c)
{
	if (c == 'o')
	{
		if (pos >= 0 && pos <= t_map->x_size)
			return (1);
	}
	if (c == 'e')
	{
		if (pos <= (t_map->size) && pos >= ((t_map->size) - t_map->x_size))
			return (1);
	}
	if (c == 'v')
	{
		if (pos % (t_map->x_size) == 0)
			return (1);
	}
	if (c == 'f')
	{
		if (pos % (t_map->x_size - 1) == 0)
			return (1);
	}	
	return (0);
}

void	ft_place_x(t_data *t_map, int pos, int len, int rows)
{
	int i;
	int row_off;
	int count;

	count = 0;
	row_off = 0;
	while (row_off <= rows)
	{
		i = pos + (row_off * t_map->x_size);
		while (count < len)
		{
			t_map->table[i] = 2;
			i++;
			count++;
		}
		row_off++;
		count = 0;
	} 
}
