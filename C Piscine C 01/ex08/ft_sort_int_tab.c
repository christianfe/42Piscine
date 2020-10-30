/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:06:56 by cfelicio          #+#    #+#             */
/*   Updated: 2020/10/23 10:07:33 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int k;
	int temp;

	i = 0;
	k = 0;
	while (i < size)
	{
		k = i + 1;
		while (k < size)
		{
			if (*(tab + k) < *(tab + i))
			{
				temp = *(tab + k);
				*(tab + k) = *(tab + i);
				*(tab + i) = temp;
			}
			k++;
		}
		i++;
	}
}
