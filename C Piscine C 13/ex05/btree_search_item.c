/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:34:57 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/12 11:34:58 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void *ret;

	if (!root)
		return (0);
	if ((ret = btree_search_item(root->left, data_ref, cmpf)))
		return (ret);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	if ((ret = btree_search_item(root->right, data_ref, cmpf)))
		return (ret);
	return (0);
}
