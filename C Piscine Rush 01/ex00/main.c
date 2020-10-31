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

int		ft_place_data(char *data, char *ris);

int	ft_strlen(char *str)
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
	if (ft_strlen(value) != 31)
		return (0);
	while (i < 32)
	{
		if (*(value + i) >= '1' && *(value + i) <= '4')
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
			write(1, "\t", 1);
	}
}

int		main(int argc, char **argv)
{
	char data[4][4];
	char ris[4][4];
	int i[2];
	
	i[0] = 0;
	i[1] = 0;
	if (argc == 2)
	{
		if (!ft_create_data(&data[0][0], argv[1]))
		{
			ft_putstr("Error\n");
			return (0);
		}
		/*while(i[0] <4)
		{
			while(i[1] < 4)
			{
				ris[i[0]][i[1]] = '0';
				i[1]++;
			}
			i[1] = 0;
			i[0]++;
		}*/
		/*ft_putarr(&data[0][0]);
		ft_putstr("\n");**/
		if (!ft_place_data(&data[0][0], &ris[0][0]))
		{
			ft_putstr("Error2\n");
			return (0);
		}
		ft_putarr(&ris[0][0]);
	}
	else
		ft_putstr("Error3\n");
	return (0);
}
