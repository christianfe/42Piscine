#include "bsq.h"

int 	ft_calculate_area(void)
{
	int i;
	int area;
	
	i = 0;
	area = 0;
	while (i < g_map.x_size * g_map.y_size)
	{
		if (g_table[i] == 2)
			area++;
		i++;
	}
	return (area);
}

void	ft_free_array(void)
{
	int i;

	i = 0;
	while (i < (g_map.x_size * g_map.y_size))
	{
		if (g_table[i] == 2)
			g_table[i] = 0;
		i++;
	}
}

int		ft_is_free_next(int pos)
{
	if (pos % (g_map.x_size - 1) == 0)
		return (0);
	if (g_table[pos + 1] == 0)
		return (1);
	else
		return (0);
}

int		ft_place_x(int pos, int len)
{
	int i;
	int row;

	i = pos;
	row = 0;
	while (row < g_map.y_size)
	{
		while (i < (pos - (pos % g_map.x_size) +g_map.x_size) && g_table[i] != 1)
		{
			g_table[i] = 2;
			i++;
		}
		if (g_table[i] == 1 && row == 0)
			return (-1);
		else if (g_table[i] == 1)
			break;
		row ++;
		i = pos + (g_map.x_size * row);
	} 
	return (row);
}
