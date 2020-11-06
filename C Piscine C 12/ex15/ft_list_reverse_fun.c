/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:58:24 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/06 10:58:26 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*begin;
	t_list	*end;
	void	*tmp;

	end = 0;
	while (begin_list != end)
	{
		begin = begin_list;
		while (begin->next != end)
		{
			tmp = begin->data;
			begin->data = begin->next->data;
			begin->next->data = tmp;
			begin = begin->next;
		}
		end = begin;
	}
}
