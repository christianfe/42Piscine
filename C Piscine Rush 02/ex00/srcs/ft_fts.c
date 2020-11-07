/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:52:41 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/07 12:46:17 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rush02.h"

int		ft_strlen(char *str);

void	ft_setzero(char *dest, char *nbr, int n, int type)
{
	int i;

	i = 0;
	while (nbr[i])
	{
		if (i < n)
		{
			if (type == 1)
				dest[i] = '1';
			else
				dest[i] = nbr[i];
		}
		else
			dest[i] = '0';
		i++;
	}
	dest[i] = '\0';
}

void	ft_isolate_nbr(char *dest, char *nbr, int n)
{
	int i;

	i = 0;
	while(nbr[i] && i < n)
	{
		dest[i] = nbr[i];
		i++;
	}
	dest[i] = '\0';
}

int		ft_is_in_file(int fd, char *to_find, int size)
{
	int mach;
	char c;
	int i;
	int row;

	mach = size;
	row = 1;
	i = 0;
	while (read(fd, &c, 1))
	{
		if (mach == 0 && (c == ' ' || c == ':'))
			return (row);
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
		if (c == '\n')
		{
			mach = size;
			row++;
		}
	}
	return (0);
}

char	*ft_cut(char *nbr, int t)
{
	char *ris;
	int i;

	i = 0;
	ris = malloc(sizeof(char) * 100);
	while (i < t)
	{
		ris[i] = nbr[i];
		i++;
	}
	ris[i] = 0;
	return (ris);
}

char	*ft_rev_cut(char *nbr, int t)
{
	char *ris;
	int i;
	int k;

	k = 0;
	i = ft_strlen(nbr);
	ris = malloc(sizeof(char) * 100);
	while (t < i)
	{
		ris[k] = nbr[t];
		t++;
		k++;
	}
	ris[k] = 0;
	return (ris);
}

char	*ft_adv_cut(char *nbr, int min, int max)
{
	char *ris;
	int i;

	i = 0;
	ris = malloc(sizeof(char) * 100);
	while (min < max)
	{
		ris[i] = nbr[min];
		i++;
		min++;
	}
	ris[i] = 0;
	return (ris);
}