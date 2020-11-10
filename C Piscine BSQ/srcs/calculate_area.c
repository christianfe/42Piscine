#include "bsq.h"

int		ft_calculate_len(int pos, int len, int up, int down)
{
	int temp;
	int pos2;
	
	temp = 0;
	pos2 = pos - (up * g_map.x_size);
	while(ft_is_free(pos2, 1) && !ft_is_border(pos2 + 1) && temp < len)
	{
		temp++;
		pos2++;
	}
	if (temp != pos)
		return (0);
	if (up >= (down * -1))
		return (ft_calculate_len(pos, len, up - 1, down));
	else
		return (1);
}

void	ft_fullize_map(void)
{
	int pos;
	int len;
	int up;
	int down;

	pos = 0;
	up = 0;
	down = 0;
	len = 0;
	while (pos < g_map.x_size * g_map.y_size)
	{
		if (!ft_is_free(pos, -1) || ft_is_border(pos))
		{
			while (ft_calculate_len(pos, len, up, down) == 1
				&& (len % g_map.x_size < g_map.x_size))
				len++;
			len--;
			while (ft_calculate_len(pos, len, up, down) == 1)
				up++;
			up--;
			while (ft_calculate_len(pos, len, up, down) == 1)
				down++;
			down--;
			ft_place_x((pos - (g_map.x_size * up)), len, up + down + 1);
			if (g_area < ft_calculate_area())
			{
				g_area = ft_calculate_area();
				g_area_len = len;
				g_start_area = (pos - (g_map.x_size * up));
				g_area_col = up + down + 1;
			}
			ft_print_map();
			ft_free_array();
		}
		up = 0;
		down = 0;
		len = 0;
	}
}
