/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:49:15 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/30 09:05:49 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str);

void	ft_reverse_str(char *str, int size)
{
	int		i;
	char	temp;

	i = 0;
	size--;
	while (i < size)
	{
		temp = str[i];
		str[i] = str[size];
		str[size] = temp;
		size--;
		i++;
	}
}

void	ft_putnbr_base(int nbr, char *base, char *dest)
{
	unsigned int	ui[2];
	unsigned int	i;
	int				sign;

	i = 0;
	sign = 1;
	if (nbr < 0)
	{
		sign = -1;
		i++;
	}
	ui[0] = (unsigned int)(nbr * sign);
	ui[1] = ft_strlen(base);
	while (ui[0] != 0)
	{
		dest[i] = base[ui[0] % ui[1]];
		ui[0] = ui[0] / ui[1];
		i++;
	}
	if (sign < 0)
	{
		dest[i] = '-';
		i++;
	}
	ft_reverse_str(dest, i);
}
