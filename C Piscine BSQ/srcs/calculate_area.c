#include "bsq.h"

int		ft_row_lim(int pos)
{
	int i;
	int start;
	int max;
	int find;

	i = 0;
	find = 0;
	start = pos - (pos % g_map.x_size);
	while (i < g_map.x_size)
	{
		if (i + start == pos)
			find = 1;
		
		if (!g_table[start + i])
			max++;
		else 
		{
			if (!find)
				max = 0;
			else 
				break;
		}
		i++;
	}
	return (max);
}

int		ft_col_lim(int pos)
{
	int i;
	int start;
	int max;
	int find;

	i = 0;
	find = 0;
	start = pos - (pos % g_map.y_size);
	while (i < g_map.y_size)
	{
		if (i + start == pos)
			find = 1;
		
		if (!g_table[start * (i + 1)])
			max++;
		else 
		{
			if (!find)
				max = 0;
			else 
				break;
		}
		i++;
	}
	return (max);
}

void	ft_calculate_area(void)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (g_table[i])
	{
		if (g_table[i] == 1)
			continue;
		x = ft_count_row();
	}
}
