/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 08:43:56 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/05 08:43:58 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_cresc(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_decresc(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	if (ft_is_cresc(tab, length, f) || ft_is_decresc(tab, length, f))
		return (1);
	else
		return (0);
}
