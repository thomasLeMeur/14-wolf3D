/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreesort_prefix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:33 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:56 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreesort_prefix(t_btree *root,
		int (*cmp)(const t_btree *, const t_btree *))
{
	t_btree	*t;

	if (!root || !cmp)
		return ;
	if ((t = root->left))
		if ((*cmp)(t, root))
			FT_SWAP(t->content, root->content, void *);
	if ((t = root->right))
		if ((*cmp)(root, t))
			FT_SWAP(root->content, t->content, void *);
	if (root->left)
		ft_btreesort_prefix(root->left, cmp);
	if (root->right)
		ft_btreesort_prefix(root->right, cmp);
}
