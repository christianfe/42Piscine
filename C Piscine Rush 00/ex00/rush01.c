/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluican <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:12:57 by aluican           #+#    #+#             */
/*   Updated: 2020/10/24 16:04:05 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	top_line(int x)
{
	int i;
	
	i = 0;
	ft_putchar('/');
	if (x >= 3)
		while (i < (x - 2))
		{
			ft_putchar('*');
			i++;
		}
	if (x >= 2)
		ft_putchar('\\');
}

void	middles_lines(int x, int y)
{
	int i;
	int k;
	
	i = 0;
	k = 0;
	while (k < (y - 2))
	{
		while (i < x)
		{
			if (i == 0 || i == (x - 1))
				ft_putchar('*');
			else
				ft_putchar(' ');
			i++;
		}
		i = 0;
		ft_putchar('\n');
		k++;
	}
}

void	bottom_line(int x)
{
	int i;

	i = 0;
	ft_putchar('\\');
	if (x >= 3)
		while (i < (x - 2))
		{
			ft_putchar('*');
			i++;
		}
	if (x >= 2)
		ft_putchar('/');
}

void	rush(int x, int y)
{
	if (y > 0 && x > 0)
	{
		top_line(x);
		ft_putchar('\n');
		if (y > 2)
			middles_lines(x, y);
		if (y > 1)
		{
			bottom_line(x);
			ft_putchar('\n');
		}
	}
}
