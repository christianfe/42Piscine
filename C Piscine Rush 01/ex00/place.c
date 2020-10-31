/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:43:52 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/31 11:43:54 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		check_data(char *data);
int		check_opposite(char *arr, int n, char to_find);
void	ft_putstr(char *str);
char	get_x(char *data, int i, int x, int type);

int		ft_adrr(int space, int i)
{
	if (i <= 3 && i >= 0)
		return (i + (4 * space));
	else if (i <= 7 && i >= 4)
		return ((i - 4) + (4 * (3 - space)));
	else if (i <= 11 && i >= 8)
		return (((i - 8) * 4) + space);
	else if (i <= 15 && i >= 12)
		return ((i - 12) * 4 + (3 - space));
	else
		return (-1);
}

int		ft_place_data(char *data, char *ris)
{
	int i_d;
	int change;

	i_d = 0;
	change = 0;
	if (!check_data(data))
		return (0);
	while (i_d < 16)
	{
		if (data[i_d] == '1')
		{
			if (ris[ft_adrr(0, i_d)] != '4')
				change = 1;
			ris[ft_adrr(0, i_d)] = '4';
		}
		if (data[i_d] == '4')
		{
			if (ris[ft_adrr(0, i_d)] != '1' && ris[ft_adrr(1, i_d)] != '2' && ris[ft_adrr(2, i_d)] != '3' && ris[ft_adrr(3, i_d)] != '4')
				change = 1;
			ris[ft_adrr(0, i_d)] = '1';
			ris[ft_adrr(1, i_d)] = '2';
			ris[ft_adrr(2, i_d)] = '3';
			ris[ft_adrr(3, i_d)] = '4';
		}
		if (data[i_d] == '3' && check_opposite(data, i_d, '2'))
		{
			if (ris[ft_adrr(2, i_d)] != '4')
				change = 1;
			ris[ft_adrr(2, i_d)] = '4';
		}
		if (data[i_d] == '2' && check_opposite(data, i_d, '2') && ris[ft_adrr(0, i_d)] == '3' && ris[ft_adrr(2, i_d)] == '4')
		{
			if (ris[ft_adrr(1, i_d)] != '1')
				change = 1;
			ris[ft_adrr(1, i_d)] = '1';
		}
		if (data[i_d] == '3' && check_opposite(data, i_d, '1') && ris[ft_adrr(0, i_d)] == '1' && ris[ft_adrr(3, i_d)] == '4')
		{
			if (ris[ft_adrr(1, i_d)] != '3' && ris[ft_adrr(2, i_d)] != '2')
				change = 1;
			ris[ft_adrr(1, i_d)] = '3';
			ris[ft_adrr(2, i_d)] = '2';
		}
		if (data[i_d] == '3' && check_opposite(data, i_d, '2') && ris[ft_adrr(0, i_d)] == '2' && ris[ft_adrr(2, i_d)] == '4')
		{
			if (ris[ft_adrr(1, i_d)] != '3' && ris[ft_adrr(3, i_d)] != '1')
				change = 1;
			ris[ft_adrr(1, i_d)] = '3';
			ris[ft_adrr(3, i_d)] = '1';
		}
		if (data[i_d] == '2' && check_opposite(data, i_d, '2') && ris[ft_adrr(0, i_d)] == '3' && ris[ft_adrr(1, i_d)] == '4')
		{
			if (ris[ft_adrr(2, i_d)] != '1' && ris[ft_adrr(3, i_d)] != '2')
				change = 1;
			ris[ft_adrr(2, i_d)] = '1';
			ris[ft_adrr(3, i_d)] = '2';
		}
		if (data[i_d] == '3' && check_opposite(data, i_d, '2') && ris[ft_adrr(2, i_d)] == '4' && ris[ft_adrr(3, i_d)] == '2')
		{
			if (ris[ft_adrr(0, i_d)] != '1' && ris[ft_adrr(1, i_d)] != '3')
				change = 1;
			ris[ft_adrr(0, i_d)] = '1';
			ris[ft_adrr(1, i_d)] = '3';
		}
		if (data[i_d] == '2' && check_opposite(data, i_d, '3') && ris[ft_adrr(0, i_d)] == '3' && ris[ft_adrr(1, i_d)] == '4')
		{
			if (ris[ft_adrr(3, i_d)] != '1' && ris[ft_adrr(2, i_d)] != '2')
				change = 1;
			ris[ft_adrr(3, i_d)] = '1';
			ris[ft_adrr(2, i_d)] = '2';
		}
		if (data[i_d] == '3' && check_opposite(data, i_d, '2') && ris[ft_adrr(3, i_d)] == '3' && ris[ft_adrr(2, i_d)] == '4')
		{
			if (ris[ft_adrr(0, i_d)] != '1' && ris[ft_adrr(1, i_d)] != '2')
				change = 1;
			ris[ft_adrr(0, i_d)] = '1';
			ris[ft_adrr(1, i_d)] = '2';
		}
		if (data[i_d] == '3' && check_opposite(data, i_d, '1') && ris[ft_adrr(3, i_d)] == '4' && ris[ft_adrr(2, i_d)] == '1')
		{
			if (ris[ft_adrr(0, i_d)] != '2' && ris[ft_adrr(1, i_d)] != '3')
				change = 1;
			ris[ft_adrr(0, i_d)] = '2';
			ris[ft_adrr(1, i_d)] = '3';
		}
		if (data[i_d] == '1' && check_opposite(data, i_d, '2') && ris[ft_adrr(0, i_d)] == '4')
		{
			if (ris[ft_adrr(3, i_d)] != '3')
				change = 1;
			ris[ft_adrr(3, i_d)] = '3';
		}
		if (data[i_d] == '2' && check_opposite(data, i_d, '3') && ris[ft_adrr(1, i_d)] == '4' && ris[ft_adrr(3, i_d)] == '1' && get_x(data, i_d, 2, 1) == '3')
		{
			if (ris[ft_adrr(2, i_d)] != '2')
				change = 1;
			ris[ft_adrr(2, i_d)] = '2';
		}
		if (change == 1)
			i_d = 0;
		else 
			i_d++;
		change = 0;
	}
	return (1);
}
