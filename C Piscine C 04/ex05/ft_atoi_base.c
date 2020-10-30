/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:06:20 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/28 12:11:19 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		check_base(char *base)
{
	int k;
	int i;

	i = 0;
	k = 1;
	if (*base == 0 || *(base + 1) == 0)
		return (0);
	while (*(base + i))
	{
		if (*(base + i) == '+' || *(base + i) == '-')
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
	if (check_base(base))
	{
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
	}
	return (ris * sign);
}
