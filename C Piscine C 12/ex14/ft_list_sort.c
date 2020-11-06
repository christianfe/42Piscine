/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:27:25 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/06 10:27:26 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *l1;
	t_list *l2;
	t_list *temp;

	l1 = *begin_list;
	l2 = l1->next;
	while (l1->next)
	{
		while (l2->next)
		{
			if (cmp(l1->data, l2->data))
			{
				temp = l1,
				l1 = l2;
				l2 = temp;
			}
			l2 = l2->next;
		}
		l1 = l1->next;
		l2 = l1->next;
	}
}
