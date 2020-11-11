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

int		ft_is_free(int pos, int offset)
{
	return (g_table[pos + offset] == 0);
}

int		ft_is_border(int pos, char c)
{
	if (c == 'o')
	{
		if (pos >= 0 && pos <= g_map.x_size)
			return (1);
	}
	if (c == 'e')
	{
		if (pos <= (g_map.size) && pos >= ((g_map.size) - g_map.x_size))
			return (1);
	}
	if (c == 'v')
	{
		if (pos % (g_map.x_size) == 0)
			return (1);
	}
	if (c == 'f')
	{
		if (pos % (g_map.x_size - 1) == 0)
			return (1);
	}	
	return (0);
}

void	ft_place_x(int pos, int len, int rows)
{
	int i;
	int row_off;
	int count;

	count = 0;
	row_off = 0;
	while (row_off <= rows)
	{
		i = pos + (row_off * g_map.x_size);
		while (count < len)
		{
			g_table[i] = 2;
			i++;
			count++;
		}
		row_off++;
		count = 0;
	} 
}
