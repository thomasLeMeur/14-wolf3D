/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreefind_suffix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:46:23 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:34 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreefind_suffix(t_btree *root, const void *ptr,
		size_t size,
		int (*cmp)(const t_btree *, const void*, size_t))
{
	t_btree	*tmp;

	if (!root || !cmp)
		return (NULL);
	if (root->left)
		if ((tmp = ft_btreefind_suffix(root->left, ptr, size, cmp)))
			return (tmp);
	if (root->right)
		if ((tmp = ft_btreefind_suffix(root->right, ptr, size, cmp)))
			return (tmp);
	if ((*cmp)(root, ptr, size))
		return (root);
	return (NULL);
}
