/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:41:54 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/26 09:16:11 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		f_pow(int p)
{
	int ris;

	ris = 1;
	while (p > 0)
	{
		ris *= 10;
		p--;
	}
	return (ris);
}

void	ft_putnbr(int nb)
{
	long			var[3];
	char			c;

	var[1] = 0;
	var[2] = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		var[2] *= -1;
	}
	else if (nb == 0)
		write(1, "0", 1);
	var[0] = var[2];
	while (var[0] > 0)
	{
		var[0] /= 10;
		var[1]++;
	}
	while (var[1] > 0)
	{
		c = 48 + (var[2] / f_pow(var[1] - 1));
		var[2] = var[2] - ((var[2] / f_pow(var[1] - 1)) * f_pow(var[1] - 1));
		write(1, &c, 1);
		var[1]--;
	}
}
