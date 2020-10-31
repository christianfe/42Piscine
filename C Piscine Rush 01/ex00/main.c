/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:02:19 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/31 11:14:34 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		ft_create_data(char *data, char *value)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (i < 32)
	{
		if (*(value + i) >= '0' && *(value + i) <= '4')
			data[a] = *(value + i);
		else
			return (0);
		i++;
		a++;
		if (*(value + i) != ' ' && i < 31)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putarr(char *arr)
{
	int a;

	a = 0;
	while (a < 16)
	{
		write(1, (arr + a), 1);
		a++;
		if (a % 4 == 0)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
	}
}

int		main(int argc, char **argv)
{
	char data[4][4];

	if (argc == 2)
	{
		if (!ft_create_data(&data[0][0], argv[1]))
		{
			ft_putstr("Error2\n");
			return (0);
		}
		ft_putarr(&data[0][0]);
	}
	else
		ft_putstr("Error");
	return (0);
}
