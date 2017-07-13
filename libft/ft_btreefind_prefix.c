/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreefind_prefix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:46:19 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:33 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreefind_prefix(t_btree *root, const void *ptr,
		size_t size,
		int (*cmp)(const t_btree *, const void*, size_t))
{
	t_btree	*tmp;

	if (!root || !cmp)
		return (NULL);
	if ((*cmp)(root, ptr, size))
		return (root);
	if (root->left)
		if ((tmp = ft_btreefind_prefix(root->left, ptr, size, cmp)))
			return (tmp);
	if (root->right)
		if ((tmp = ft_btreefind_prefix(root->right, ptr, size, cmp)))
			return (tmp);
	return (NULL);
}
