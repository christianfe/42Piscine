/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_area.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:07:42 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/11 17:38:18 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_calculate_len(t_data *t_map, int pos, int len)
{
	int temp;
	int pos2;

	pos2 = pos;
	temp = 0;
	while (ft_is_free(t_map, pos, 0) && temp <= len &&
		len <= t_map->x_size - (1 + (pos2 % t_map->x_size)))
	{
		temp++;
		pos++;
	}
	if (temp - 1 != len)
		return (0);
	return (1);
}

int		ft_calculate_down(t_data *t_map, int pos, int down, int len)
{
	int temp;

	temp = 1;
	while (ft_is_free(t_map, (pos + (t_map->x_size * temp)), 0) &&
		(pos + (t_map->x_size * temp)) < t_map->size && temp <= down &&
		ft_calculate_len(t_map, (pos + (t_map->x_size * temp)), len - 1))
		temp++;
	if (temp - 1 != down)
		return (0);
	return (1);
}

int		ft_calculate_up(t_data *t_map, int pos, int up, int len)
{
	int temp;

	temp = 1;
	while (ft_is_free(t_map, (pos - (t_map->x_size * temp)), 0) &&
		(pos - (t_map->x_size * temp)) >= 0 && temp <= up &&
		ft_calculate_len(t_map, (pos - (t_map->x_size * temp)), len - 1))
		temp++;
	if (temp - 1 != up)
		return (0);
	return (1);
}

void	ft_fullize_map2(t_data *t_map, int pos, int *len)
{
	while (ft_calculate_len(t_map, pos, len[0]) == 1)
		len[0]++;
	if (pos == 0 && !ft_is_free(t_map, 0, 0))
		len[0]++;
	else if (ft_is_border(t_map, pos + len[0], 'v'))
		;
	else if (ft_is_free(t_map, pos + len[0], 0))
		len[0]--;
	while (ft_calculate_up(t_map, pos, len[1], len[0]) == 1)
		len[1]++;
	len[1]--;
	while (ft_calculate_down(t_map, pos, len[2], len[0]) == 1)
		len[2]++;
	len[2]--;
	ft_place_x(t_map, (pos - (t_map->x_size * len[1])),
				len[0], len[1] + len[2]);
}

void	ft_fullize_map(t_data *t_map)
{
	int pos;
	int len[3];

	pos = 0;
	while (pos < t_map->size)
	{
		len[1] = 0;
		len[2] = 0;
		len[0] = 1;
		if ((!ft_is_free(t_map, pos, -1) || ft_is_border(t_map, pos, 'v')) &&
			ft_is_free(t_map, pos, 0))
		{
			ft_fullize_map2(t_map, pos, &len[0]);
			if (t_map->area < ft_calculate_area(t_map))
			{
				t_map->area = ft_calculate_area(t_map);
				t_map->area_len = len[0];
				t_map->start_area = (pos - (t_map->x_size * len[1]));
				t_map->area_col = len[1] + len[2];
			}
			ft_free_array(t_map);
		}
		pos++;
	}
}
