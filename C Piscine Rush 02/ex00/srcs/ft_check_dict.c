/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sav.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:16:55 by bvalaria          #+#    #+#             */
/*   Updated: 2020/11/08 15:17:05 by bvalaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"
#include <stdio.h>
#include <stdlib.h>

int		g_fd;
char	g_char_read;
int		g_check;
int		g_pos;

void	ft_check(void)
{
	if (g_char_read == ':')
	{
		if (g_pos == 0 || g_pos == 11)
			g_pos = 1;
		else
			g_check = 0;
	}
	else if (g_pos == -1 && !(g_char_read >= '0' && g_char_read <= '9'))
		g_check = 0;
	else if (g_pos == -1 && g_char_read == ' ')
		g_check = 0;
	else if (g_char_read >= 32 && g_char_read < 127
			&& g_char_read != ' ' && g_pos == 1)
		g_pos = 2;
	else if (g_char_read == ' ' && g_pos == 2)
		g_pos = 1;
	else if (g_char_read == ' ' && g_pos == 0)
		g_pos = 11;
	else if (g_char_read == ' ' && g_pos == 11)
		return ;
	else if (g_char_read != ' ' && g_pos == 11)
		g_check = 0;
	else if (g_pos == 0 && !(g_char_read >= '0' && g_char_read <= '9'))
		g_check = 0;
}

int		ft_check_row(char *path)
{
	g_pos = -1;
	g_check = 1;
	g_fd = open(path, O_RDONLY);
	while (read(g_fd, &g_char_read, 1))
	{
		if (g_check == 1)
		{
			if (g_char_read == '\n')
			{
				if (g_pos == 2 || g_pos == -1)
					g_pos = -1;
				else
					g_check = 0;
			}
			else if (g_pos == -1 && (g_char_read >= '0' && g_char_read <= '9'))
				g_pos = 0;
			else
				ft_check();
		}
	}
	if (g_pos != 2 && g_pos != -1)
		g_check = 0;
	close(g_fd);
	return (g_check);
}

int		ft_check_all(char *path)
{
	if (ft_check_row(path))
		return (1);
	else
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	return (0);
}
