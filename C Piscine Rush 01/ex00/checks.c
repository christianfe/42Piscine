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

void	ft_putstr(char *str);

int		check_four(char *arr, int start, char to_find)
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

int		check_opposite(char *arr, int n, char to_find)
{
	if ((n >= 0 && n <= 3) || (n >= 8 && n <= 11))
		n += 4;
	else
		n -= 4;
	if (arr[n] == to_find)
		return (1);
	else
		return (0);
}

int		check_data(char *data)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i != 0 && ((i % 4 == 0) || i == 0))
		{
			if (check_four(data, i, '1') != 1)
				return (0);
			if (check_four(data, i, '4') > 1)
				return (0);
			if (data[i] == '4')
				if (!(check_opposite(data, i, '1')))
					return (0);
			if ((i >= 0 && i <= 3) || (i >= 8 && i <= 11))
			{
				if ((((data[i] - '0') + (data[i + 4] - '0')) < 3) ||
				(((data[i] - '0') + (data[i + 4] - '0')) > 5))
					return (0);
			}
		}
		i++;
	}
	return (1);
}

char	get_x(char *data, int i, int x, int type)
{
	int punt;

	if (i <= 3 && i >= 0)
		punt = 12 + x;
	if (i <= 7 && i >= 4)
		punt = 8 + (3 - x);
	if (i <= 11 && i >= 8)
		punt = 4 + x;
	if (i <= 15 && i >= 12)
		punt = 4 + (3 - x);
	if (type < 0)
		punt -= 4;
	return (data[punt]);
}

int		ft_arrc_comp(char *arr)
{
	int i;

	i = 0;
	while (i <= 16)
	{
		if (arr[i] == 0)
			return (0);
		i++;
	}
	return (1);
}
