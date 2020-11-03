/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:48:59 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/31 09:25:14 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putnbr_base(int nbr, char *base, char *dest);

int		ft_check_base(char *base)
{
	int k;
	int i;

	i = 0;
	k = 1;
	if (*base == 0 || *(base + 1) == 0)
		return (0);
	while (*(base + i))
	{
		if (*(base + i) == '+' || *(base + i) == '-' || *(base + i) == ' ')
			return (0);
		while (*(base + k))
		{
			if (*(base + i) == *(base + k))
				return (0);
			k++;
		}
		i++;
		k = i + 1;
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

char	*ft_char_is_in_base(char *str, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (*str == base[i])
			return (base + i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	unsigned int	ris;
	unsigned int	sign;

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
	while (ft_char_is_in_base(str, base))
	{
		ris *= ft_strlen(base);
		ris += (unsigned int)(ft_char_is_in_base(str, base) - base);
		str++;
	}
	return (ris * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*dest;
	int		i;

	i = 0;
	if (!(ft_check_base(base_from) && ft_check_base(base_to)))
		return (0);
	while (*(nbr + i) == ' ' || *(nbr + i) == '\f' ||
			*(nbr + i) == '\n' || *(nbr + i) == '\r' ||
			*(nbr + i) == '\t' || *(nbr + i) == '\v')
		i++;
	while (*(nbr + i) == '+' || *(nbr + i) == '-')
		i++;
	while (i < ft_strlen(nbr))
	{
		if (!ft_char_is_in_base((nbr + i), base_from))
			return (0);
		i++;
	}
	i = 0;
	nb = ft_atoi_base(nbr, base_from);
	dest = (char *)malloc(100 * sizeof(char));
	ft_putnbr_base(nb, base_to, dest);
	while (ft_char_is_in_base((dest + i), base_to))
		i++;
	*(dest + 1 + ft_strlen(dest)) = 0;
	return (dest);
}
