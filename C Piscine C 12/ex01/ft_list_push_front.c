/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:21:51 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/05 15:21:52 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	list->data = data;
	list->next = 0;
	return (list);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *fist_el;

	fist_el = ft_create_elem(data);
	fist_el->next = *begin_list;
	*begin_list = fist_el;
}
