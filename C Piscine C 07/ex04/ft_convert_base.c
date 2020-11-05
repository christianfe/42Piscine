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

int		ft_strlen(char *str);

void	ft_putnbr_base(int nbr, char *base, char *nb_dest);

int		ft_check_base(char *base)
{
	char	*checkbase;
	int		i;

	checkbase = base;
	if (*base == 0 || *(base + 1) == 0)
		return (0);
	while (*checkbase)
	{
		if (*checkbase == '+' || *checkbase == '-'
			|| *checkbase == ' ' || *checkbase <= 31)
			return (0);
		i = 1;
		while (*(checkbase + i))
		{
			if (*(checkbase + i) == *checkbase)
				return (0);
			i++;
		}
		checkbase++;
	}
	return (1);
}

char	*ft_char_is_in_base(char *base, char *to_find)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (*to_find == base[i])
			return (base + i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	unsigned int	ris;
	int				sign;
	char			*charptr;

	ris = 0;
	sign = 1;
	charptr = str;
	while (*charptr == ' ' || (*charptr >= 9 && *charptr <= 13))
		charptr++;
	while (*charptr == '-' || *charptr == '+')
	{
		if (*charptr == '-')
			sign *= -1;
		charptr++;
	}
	while (ft_char_is_in_base(base, charptr))
	{
		ris *= ft_strlen(base);
		ris += (unsigned int)(ft_char_is_in_base(base, charptr) - base);
		charptr++;
	}
	return (int)(ris * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb_int;
	char	*nb;

	if (!(ft_check_base(base_from) && ft_check_base(base_to)))
		return (0);
	nb = malloc(34);
	nb_int = ft_atoi_base(nbr, base_from);
	ft_putnbr_base(nb_int, base_to, nb);
	return (nb);
}
