/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:45:12 by bvalaria          #+#    #+#             */
/*   Updated: 2020/11/07 09:45:14 by bvalaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rush02.h"

void	ft_print_list(t_list *list)
{
	char *c;
	int i;

	i =0;
	while (list)
	{
		c = list->data;
		while (c[i] != 0)
		{
			write(1, &c[i], 1);
			i++;
		}
		write(1, " ", 1);
		list = list->next;
	}
}
