/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:03:00 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/07 09:03:01 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	g_i;
int	g_check;

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		ft_strlen(char *str)
{
	char	*charptr;
	int		i;

	i = 0;
	charptr = str;
	while (*charptr != 0)
	{
		i++;
		charptr++;
	}
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (*(src + i) != 0)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = 0;
	return (dest);
}

int		ft_dict_max(char *path)
{
	char	c;
	int		max;
	int		fd;

	g_i = 1;
	g_check = 0;
	max = 1;
	fd = open(path, O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			g_check = 0;
		else if (c >= '1' && c <= '9' && g_check == 0)
			g_check = 1;
		else if (g_check == 1 && c == '0')
			g_i++;
		else
			g_check = 2;
		if (g_check == 1 && g_i > max)
			max = g_i;
		if (g_check == 2)
			g_i = 1;
	}
	close(fd);
	return (max);
}
