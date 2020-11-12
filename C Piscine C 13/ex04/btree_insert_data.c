/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:35:09 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/12 11:35:10 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *new;

	new = (t_btree*)malloc(sizeof(t_btree));
	new->item = item;
	new->left = 0;
	new->right = 0;
	return (new);
}

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *,	void *))
{
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
	{
		if (!(*root)->left)
		{
			(*root)->left = btree_create_node(item);
			return ;
		}
		btree_insert_data(&(*root)->left, item, cmpf);
	}
	else
	{
		if (!(*root)->right)
		{
			(*root)->right = btree_create_node(item);
			return ;
		}
		btree_insert_data(&(*root)->right, item, cmpf);
	}
}
