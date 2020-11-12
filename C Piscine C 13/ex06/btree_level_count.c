/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelicio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:34:49 by cfelicio          #+#    #+#             */
/*   Updated: 2020/11/12 11:34:51 by cfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int l;
	int r;

	if (!root)
		return (0);
	l = btree_level_count(root->left);
	r = btree_level_count(root->right);
	if (l < r)
		return (r + 1);
	else
		return (l + 1);
}
