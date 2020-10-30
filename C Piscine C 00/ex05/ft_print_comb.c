/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:40:00 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/23 14:59:51 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	f_print(char a, char b, char c, char d)
{
	write(1, &a, 1);
	if (b != 0)
		write(1, &b, 1);
	if (c != 0)
		write(1, &c, 1);
	if (d != 0)
		write(1, &d, 1);
}

void	ft_print_comb(void)
{
	char	i[3];

	f_print('0', '1', '2', 0);
	i[0] = '0';
	i[1] = '1';
	i[2] = '3';
	while (i[0] <= '7')
	{
		while (i[1] <= '8')
		{
			while (i[2] <= '9')
			{
				if (i[0] != i[1] && i[1] != i[2] && i[0] != i[2])
				{
					f_print(',', ' ', 0, 0);
					f_print(i[0], i[1], i[2], 0);
				}
				i[2]++;
			}
			i[1]++;
			i[2] = i[1];
		}
		i[0]++;
		i[1] = i[0];
	}
}
