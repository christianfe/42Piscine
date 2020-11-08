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

#include "ft_rush02.h"

int		ft_print_list(t_list *list, int i)
{
	if (list)
	{
		if (i == 0 && !list->next)
			return (0);
		i++;
		ft_putstr(list->data);
		if (list->next)
		{
			if (i != 1)
				ft_putstr(" ");
		}
		list = list->next;
		ft_print_list(list, i);
	}
	if (i == 1)
		ft_putstr("\n");
	return (1);
}

void	ft_list_clear(t_list *begin_list)
{
	t_list *val;

	while (begin_list->next)
	{
		val = begin_list;
		begin_list = begin_list->next;
		free(val);
	}
}

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	if (!(list = malloc(sizeof(t_list) * 100)))
		return (0);
	list->data = data;
	list->next = 0;
	return (list);
}

void	ft_list_push_back(t_list *begin_list, void *data)
{
	t_list *last;

	last = ft_create_elem(data);
	while (begin_list->next)
		begin_list = begin_list->next;
	begin_list->next = last;
}
