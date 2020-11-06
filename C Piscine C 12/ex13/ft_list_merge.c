/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 09:59:59 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/06 10:00:00 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *list_ptr;

	list_ptr = *begin_list1;
	if (!list_ptr)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (list_ptr->next)
		list_ptr = list_ptr->next;
	list_ptr->next = begin_list2;
}
