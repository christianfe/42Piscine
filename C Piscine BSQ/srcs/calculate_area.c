#include "bsq.h"

int ft_try_full_row(int pos)
{
	int i;

	i = pos;
	while(i < (pos - (pos % g_map.x_size) +g_map.x_size))
	{
		if (g_table[i] ==  0)
			g_table[i] = 2;
		else
			break;
		i++;
	}
	printf("%i\n",(i - pos));
	return (i - pos);
}

void	ft_fullize_map()
{
	int pos;
	int len;
	int col;

	pos = 0;

	len = 1;
	while (pos < g_map.x_size * g_map.y_size)
	{
		col = 1;
		if (g_table[pos] == 1)
		{
			pos++;
			col = 1;
			len = 1;
			continue;
		}
		if ((len = ft_try_full_row(pos)) == 1)
		{
			pos++;
			continue;
		}
		while (1)
		{
			col = ft_place_x(pos, len, col);
			if(ft_calculate_area() > g_area)
			{
				g_area = ft_calculate_area(pos, len);
				g_start_area = pos;
				g_area_len = len;
			}
			ft_print_map();
			ft_free_array();
			len--;
		}
		if (pos == 2)
			break;
		pos++;
	}
}
