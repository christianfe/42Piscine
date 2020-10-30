/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 09:08:36 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/30 14:44:39 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *ris;
	int i;

	i = 0;
	if (min >= max)
		return (0);
	ris = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		*(ris + i) = min;
		min++;
		i++;
	}
	*(ris + i) = 0;
	return (ris);
}
