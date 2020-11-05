/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:45:11 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/05 14:45:12 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_create_elem(void *data)
{
	t_list *list;

	list = malloc (sizeof(t_list));
	list->data = data;
	list->next = 0;
	return (list);
}