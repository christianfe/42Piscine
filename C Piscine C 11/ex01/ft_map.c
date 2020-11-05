/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 08:43:21 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/05 08:43:22 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *ris;
	int i;

	i = 0;
	ris = malloc(sizeof(int) * length);
	if (!ris)
		return (0);
	while (i < length)
	{
		ris[i] = f(tab[i]);
		i++;
	}
	return (ris);
}
