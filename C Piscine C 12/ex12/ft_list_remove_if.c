/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 09:03:44 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/06 09:04:12 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
							void (*free_fct)(void *))
{
	t_list	*list_ptr;
	t_list	*prev;

	list_ptr = *begin_list;
	while (list_ptr)
	{
		if (cmp(list_ptr->next, data_ref) == 0)
		{
			prev->next = list_ptr->next;
			free_fct(list_ptr->data);
			free(list_ptr);
		}
		else
		{
			prev = list_ptr;
			list_ptr = list_ptr->next;
		}
	}
}
