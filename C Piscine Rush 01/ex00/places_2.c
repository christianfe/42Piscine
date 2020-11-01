/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   places_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:34:16 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/01 13:34:19 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_adrr(int space, int i);

void	ft_find_left_2(char *ris, char replace, int *y)
{
	while (y[3] < 4)
	{
		while (y[4] < 4)
		{
			if (ris[ft_adrr(y[4], y[3])] == replace)
				y[2] = 1;
			y[4]++;
		}
		if (y[2] == 0)
			y[0] = y[3];
		else
			y[2] = 0;
		y[4] = 0;
		y[3]++;
	}
}

void	ft_find_left(char *ris, char replace)
{
	int y[5];

	y[2] = 0;
	y[3] = 0;
	y[4] = 0;
	y[0] = 0;
	ft_find_left_2(ris, replace, &y[0]);
	y[3] = 8;
	while (y[3] < 12)
	{
		while (y[4] < 4)
		{
			if (ris[ft_adrr(y[4], y[3])] == replace)
				y[2] = 1;
			y[4]++;
		}
		if (y[2] == 0)
			y[1] = y[3] - 8;
		else
			y[2] = 0;
		y[4] = 0;
		y[3]++;
	}
	if (ris[ft_adrr(y[1], y[0])] == 0)
		ris[ft_adrr(y[1], y[0])] = replace;
}

int		check(char *ris, int row, char to_find)
{
	int x[3];

	x[2] = 0;
	x[1] = 4;
	x[0] = 0;
	while ((row < 4 && row >= 0) || (row > 7 && row < 12))
	{
		while (x[2] < 4)
		{
			if (ris[ft_adrr(x[2], row)] == to_find)
				x[1]--;
			x[2]++;
		}
		if (row == 4 - x[1] && x[0] == 0)
			x[0] = row;
		row++;
	}
	if (x[1] == 1 && row <= 4)
	{
		if (check(ris, 8, to_find) == 1)
			ft_find_left(ris, to_find);
	}
	else if (x[1] == 1 && row > 4)
		return (1);
	return (10);
}

int		ft_check_char_left(char *ris)
{
	if (!check(ris, 0, '1'))
		return (0);
	if (!check(ris, 0, '2'))
		return (0);
	if (!check(ris, 0, '3'))
		return (0);
	if (!check(ris, 0, '4'))
		return (0);
	return (1);
}
