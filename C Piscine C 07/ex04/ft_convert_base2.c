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
	unsigned int	un_nbr;
	unsigned int	base_l;
	unsigned int	i;

	i = 0;
	if (nbr < 0)
	{
		*dest = '-';
		i++;
		un_nbr = (unsigned int)(-1 * nbr);
	}
	else
		un_nbr = (unsigned int)nbr;
	base_l = ft_strlen(base);
	while (un_nbr != 0)
	{
		dest[i] = base[un_nbr % base_l];
		un_nbr = un_nbr / base_l;
		i++;
	}
	ft_reverse_str(dest, i);
}
