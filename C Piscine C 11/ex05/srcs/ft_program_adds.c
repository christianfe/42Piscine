/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program_adds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:20:56 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/09 10:20:58 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_putstr(char *str)
{
	char *charptr;

	charptr = str;
	while (*charptr != 0)
	{
		write(1, charptr, 1);
		charptr++;
	}
}

int		ft_atoi(char *str)
{
	int ris;
	int sign;

	ris = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' ||
			*str == '\r' || *str == '\t' || *str == '\v')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		ris *= 10;
		ris += (*str - '0');
		str++;
	}
	return (ris * sign);
}

int		ft_strlen(char *str)
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
