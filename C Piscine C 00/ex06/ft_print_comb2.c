/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:40:51 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/25 11:05:18 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	f_print_couples(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	if (c != 0)
	{
		write(1, " ", 1);
		write(1, &c, 1);
		write(1, &d, 1);
	}
}

void	assign_c(char *str)
{
	*str = '0';
	*(str + 1) = '0';
	*(str + 2) = '0';
	*(str + 3) = '2';
	f_print_couples('0', '0', '0', '1');
}

void	increment(char *i, int type)
{
	if (type == 0)
	{
		*i = *i + 1;
		*(i + 1) = '0';
	}
	else if (type == 1)
	{
		*(i + 2) = *i;
		*(i + 3) = *(i + 1) + 1;
		*(i + 1) = *(i + 1) + 1;
	}
	else if (type == 2)
	{
		*(i + 2) = *(i + 2) + 1;
		*(i + 3) = '0';
	}
}

void	ft_print_comb2(void)
{
	char	i[4];

	assign_c(i);
	while (i[0] <= '9')
	{
		while (i[1] <= '9')
		{
			while (i[2] <= '9')
			{
				while (i[3] <= '9')
				{
					if (!(i[0] == i[2] && i[1] == i[3]))
					{
						f_print_couples(',', ' ', 0, 0);
						f_print_couples(i[0], i[1], i[2], i[3]);
					}
					i[3]++;
				}
				increment(i, 2);
			}
			increment(i, 1);
		}
		increment(i, 0);
	}
}
