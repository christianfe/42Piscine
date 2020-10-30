/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:55:14 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/28 09:55:44 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int *k, int n)
{
	int	i;
	int	display;

	display = 1;
	i = 0;
	while (++i < n)
		if (k[i - 1] >= k[i])
			display = 0;
	if (!display)
		return ;
	i = -1;
	while (++i < n)
		ft_putchar(k[i] + 48);
	if (k[0] < (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	k[10];

	if (n > 10 || n < 0)
		return ;
	i = -1;
	while (++i < n)
		k[i] = i;
	while (k[0] <= (10 - n))
	{
		print(k, n);
		k[n - 1]++;
		i = n;
		while (i != 0 && n > 1)
		{
			i--;
			if (k[i] > 9)
			{
				k[i] = k[i - 1];
				k[i - 1]++;
			}
		}
	}
}
