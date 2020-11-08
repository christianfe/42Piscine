/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 10:12:06 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/07 10:12:08 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

char	*g_temp;
int		g_first;

void	ft_check_is_in_file(char c, int *m, char *to_find, int *ii)
{
	int mach;
	int i;

	mach = *m;
	i = *ii;
	if (c == to_find[i])
	{
		mach--;
		i++;
	}
	else
	{
		mach = -1;
		i = 0;
	}
	*ii = i;
	*m = mach;
}

int		ft_is_in_file(int fd, char *to_find, int size)
{
	int		mach;
	char	c;
	int		i;
	int		row;

	mach = size;
	row = 1;
	i = 0;
	while (read(fd, &c, 1))
	{
		if (mach == 0 && (c == ' ' || c == ':'))
			return (row);
		ft_check_is_in_file(c, &mach, to_find, &i);
		if (c == '\n')
		{
			mach = size;
			row++;
		}
	}
	return (0);
}

void	ft_iter2(char *nbr, char *path, int lenght)
{
	if (lenght == 2)
	{
		if ((ft_read_file(path, g_temp, lenght)) == 0)
		{
			ft_setzero(g_temp, nbr, 1, 0);
			ft_read_file(path, g_temp, lenght);
			ft_find_nbr(ft_rev_cut(nbr, 1), path, 1);
		}
	}
	else if ((lenght % 3) == 1)
	{
		ft_find_nbr(nbr, path, 1);
		ft_setzero(g_temp, nbr, 1, 1);
		ft_read_file(path, g_temp, lenght);
		ft_find_nbr(ft_rev_cut(nbr, 1), path, lenght - 1);
	}
	else if ((lenght % 3) == 2)
	{
		ft_find_nbr(nbr, path, 2);
		ft_setzero(g_temp, ft_rev_cut(nbr, 1), 1, 1);
		ft_read_file(path, g_temp, lenght - 1);
		ft_find_nbr(ft_rev_cut(nbr, 2), path, lenght - 2);
	}
}

void	ft_iter(char *nbr, char *path, int lenght)
{
	if ((lenght % 3) == 0)
	{
		if (nbr[0] != '0')
		{
			ft_read_file(path, nbr, 1);
			ft_setzero(g_temp, nbr, 1, 1);
			ft_read_file(path, g_temp, 3);
		}
		ft_find_nbr(ft_rev_cut(nbr, 1), path, 2);
		if (lenght > 3)
		{
			if (nbr[0] != '0' || nbr[1] != '0' || nbr[2] != '0')
			{
				ft_setzero(g_temp, nbr, 1, 1);
				ft_read_file(path, g_temp, lenght - 2);
			}
			ft_find_nbr(ft_rev_cut(nbr, 3), path, lenght - 3);
		}
	}
	else
		ft_iter2(nbr, path, lenght);
}

int		ft_find_nbr(char *nbr, char *path, int lenght)
{
	int		i;

	i = 0;
	if (ft_dict_max(path) + 3 <= lenght)
		return (0);
	if (lenght > 1)
		g_first = 0;
	if (!(g_temp = malloc(sizeof(char) * 200)))
		return (0);
	ft_list_push_back(g_to_free, g_temp);
	ft_strcpy(g_temp, nbr);
	if (lenght == 1)
	{
		if (nbr[0] == '0')
			if (g_first)
				ft_read_file(path, g_temp, lenght);
		if (nbr[0] != '0')
			ft_read_file(path, g_temp, lenght);
	}
	else
		ft_iter(nbr, path, lenght);
	return (1);
}
