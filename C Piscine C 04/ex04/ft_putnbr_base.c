/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:12:57 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/28 12:28:46 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_base(char *base)
{
	char	*baseptr;
	int		i;

	baseptr = base;
	if (*baseptr == 0 || *(baseptr + 1) == 0)
		return (0);
	while (*baseptr)
	{
		if (*baseptr == '+' || *baseptr == '-' || *baseptr <= 31)
			return (0);
		i = 1;
		while (*(baseptr + i))
		{
			if (*baseptr == *(baseptr + i))
				return (0);
			i++;
		}
		baseptr++;
	}
	return (1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	un_nbr;
	unsigned int	base_l;

	if (check_base(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			un_nbr = (unsigned int)(-1 * nbr);
		}
		else
			un_nbr = (unsigned int)nbr;
		base_l = ft_strlen(base);
		if (un_nbr >= base_l)
		{
			ft_putnbr_base(un_nbr / base_l, base);
			ft_putnbr_base(un_nbr % base_l, base);
		}
		else
			write(1, (base + un_nbr), 1);
	}
}
