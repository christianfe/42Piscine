/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:21:22 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/31 11:21:29 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putstr(char *str);

int	check_four(char *arr, int start, char to_find)
{
	int i;
	int find;

	i = 0;
	find = 0;
	while (i < 4)
	{
		if (*(arr + i + start) == to_find)
			find++;
		i++;
	}
	return (find);
}

int	check_opposite(char *arr, int n, char to_find) 
{
	printf("opp:%c\t", arr[n]);
	if ((n >= 0 && n <= 3) || (n >= 8 && n <= 11))
		n += 4;
	else
		n -= 4;
	printf("opp:%c\t", arr[n]);
	if (arr[n] == to_find)
		return (1);
	else
		return (0);
}

int	check_data(char *data)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i != 0 &&( (i % 4 == 0) || i == 0))
		{
			if (check_four(data, i, '1') != 1)
				return (0);
			if (check_four(data, i, '4') > 1)
				return (0);
		}
		i++;
	}
	return (1);
}
