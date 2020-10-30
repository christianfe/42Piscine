/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:53:58 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/30 10:22:04 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int ris;

	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	ris = 1;
	while (power > 0)
	{
		ris *= nb;
		power--;
	}
	return (ris);
}
