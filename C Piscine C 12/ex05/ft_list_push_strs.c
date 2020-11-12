/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 09:06:26 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/06 09:06:27 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*temp;
	t_list	*first;

	i = 0;
	first = 0;
	while (i < size)
	{
		temp = first;
		first = ft_create_elem(strs[i]);
		first->next = temp;
		i++;
	}
	return (first);
}
