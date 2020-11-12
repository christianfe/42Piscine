/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 09:04:43 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/06 09:04:44 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*temp;
	t_list	*prec;
	t_list	*corr;

	if (!*begin_list || !(*begin_list)->next)
		return ;
	prec = *begin_list;
	corr = prec->next;
	prec->next = 0;
	while (corr->next)
	{
		temp = corr->next;
		corr->next = prec;
		prec = corr;
		corr = temp;
	}
	corr->next = prec;
	*begin_list = corr;
}
