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

#include<stdio.h>

int		ft_adrr(int space, int i);

void	ft_find_left(char *ris, char replace)
{
	int found;
	int y[2];
	int i;
	int k;
	
	found = 0;
	k = 0;
	i = 0;
	y[0] = 0;
	while(k < 4)
	{
		while (i < 4)
		{
			if (ris[ft_adrr(i, k)] == replace)
				found = 1;
			i++;
		}
		if (found == 0)
			y[0] = k;
		else
			found = 0; 
		i = 0;
		k++;
	}

	k = 8;
	while(k < 12)
	{
		while (i < 4)
		{
			if (ris[ft_adrr(i, k)] == replace)
				found = 1;
			i++;
		}
		if (found == 0)
			y[1] = k - 8;
		else
			found = 0; 
		i = 0;
		k++;
	}

	if (ris[ft_adrr(y[1], y[0])] == 0)
		ris[ft_adrr(y[1], y[0])] = replace;
}

int		check(char *ris, int row, char to_find)
{
	int left;
	int i;
	int x;

	i = 0;
	left = 4;
	x = 0;
	while ((row < 4 && row >= 0) || (row > 7 && row < 12))
	{
		while (i < 4)
		{
			if (ris[ft_adrr(i, row)] == to_find)
			{
				left--;
			}
			i++;
		}
		if (row == 4 - left && x == 0)
			x = row;
		i = 0;
		row++;
	}
	if (left == 1 && row <= 4)
	{
		if(check(ris, 8, to_find) == 1)
			ft_find_left(ris, to_find);
	}
	else if (left == 1 && row > 4)
		return (1);
	return (10);
}

int ft_check_char_left(char *ris)
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