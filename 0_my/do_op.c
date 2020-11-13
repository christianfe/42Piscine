/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:10:29 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/05 14:10:30 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*g_v1;
char	*g_op;
char	*g_v2;
int		g_n1;
int		g_n2;

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

int		ft_calculate(void)
{
	int ris;

	ris = 0;
	if (*g_op == '+')
		ris = (g_n1 + g_n2);
	else if (*g_op == '-')
		ris = (g_n1 - g_n2);
	else if (*g_op == '*')
		ris = (g_n1 * g_n2);
	else if (*g_op == '/')
	{
		if (g_n2 != 0)
			ris = (g_n1 / g_n2);
		else
			return (1);
	}
	else if (*g_op == '%')
	{
		if (g_n2 != 0)
			ris = (g_n1 % g_n2);
		else
			return (2);
	}
	ft_putnbr(ris);
	return (0);
}

int		main(int argc, char **argv)
{
	int err;

	if (argc == 4)
	{
		g_n1 = ft_atoi(argv[1]);
		g_op = argv[2];
		g_n2 = ft_atoi(argv[3]);
		err = ft_calculate();
		if (err)
		{
			if (err == 1)
				write(1, "Stop : division by zero", 24);
			if (err == 2)
				write(1, "Stop : modulo by zero", 22);
		}
		write(1, "\n", 1);
	}
	return (0);
}
