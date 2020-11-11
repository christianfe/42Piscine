#include "bsq.h"

int		ft_calculate_len(int pos, int len)
{
	int temp;
	
	temp = 1;
	while(ft_is_free(pos, 0) && !ft_is_border(pos + 1, 'v') && temp <= len)
	{
		temp++;
		pos++;
	}
	if (temp - 1 != len)
		return (0);
	return (1);
}

int		ft_calculate_down(int pos, int down, int len)
{
	int temp;
	
	temp = 1;
	while(ft_is_free((pos + (g_map.x_size * temp)), 0) && (pos + (g_map.x_size * temp)) < g_map.size && temp <= down && ft_calculate_len((pos + (g_map.x_size * temp)), len - 1))
		temp++;
	if (temp - 1 != down)
		return (0);
	return (1);
}

int		ft_calculate_up(int pos, int up, int len)
{
	int temp;
	
	temp = 1;
	while(ft_is_free((pos - (g_map.x_size * temp)), 0) && (pos - (g_map.x_size * temp)) >= 0 && temp <= up && ft_calculate_len((pos - (g_map.x_size * temp)), len - 1))
		temp++;
	if (temp - 1 != up)
		return (0);
	return (1);
}

void	ft_fullize_map(void)
{
	int pos;
	int len;
	int up;
	int down;

	pos = 0;
	while (pos < g_map.size)
	{
		up = 0;
		down = 0;
		len = 1;
		if (!ft_is_free(pos, -1) || ft_is_border(pos, 'v'))
		{
			while (ft_calculate_len(pos, len) == 1)
				len++;
			if (pos == 0 && !ft_is_free(0, 0))
				len++;
			else if (ft_is_border(pos + len, 'v'))
				;
			else if (ft_is_free(pos + len, 0))
				len--;
			/*while (ft_calculate_up(pos, up, len) == 1)
				up++;
			up--;
			printf("%i\t%i\t*%i*\t%i\n", pos ,len, up, down);
			while (ft_calculate_down(pos, down, len) == 1)
				down++;
			down--;*/
			ft_place_x((pos - (g_map.x_size * up)), len, up + down);
			if (g_area < ft_calculate_area())
			{
				g_area = ft_calculate_area();
				g_area_len = len;
				g_start_area = (pos - (g_map.x_size * up));
				g_area_col = up + down;
			}
			ft_print_map();
			ft_free_array();
		}
		//break;
		pos++;
	}
}
