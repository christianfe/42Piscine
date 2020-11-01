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

void	ft_find_left(char *ris, char replace, int x)
{
	int found;
	int y;
	int i;
	int k;
	
	found = 0;
	k = 0;
	i = 0;
	y = 0;
	while(k < 4)
	{
		while (i < 4)
		{
			if (ris[ft_adrr(i, k)] == replace)
				found = 1;
			i++;
		}
		if (found == 0)
			y = k;
		else
			found = 0; 
		i = 0;
		k++;
	}
	ris[ft_adrr(x - 1, y)] = replace;
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
				left--;
			else
				x = row; 
			i++;
		}
		i = 0;
		row++;
	}
	//printf ("%i,\t%i,  %c\n", left, row, to_find);
	if (left == 1 && row <= 4)
	{
		if(check(ris, 8, to_find) == 1)
			ft_find_left(ris, to_find, x);
		//printf("::%i", check(ris, 8, to_find));
	}
	else if (left == 1 && row > 4)
		return (left);
	return (1);
}

int ft_check_char_left(char *ris)
{
	int i;
	char c;

	i = 0;
	c = '1';
	while (i < 4)
	{
		if (!check(ris, 0, c))
			return (0);
		c++;
		i++;
	}
	return (1);
}