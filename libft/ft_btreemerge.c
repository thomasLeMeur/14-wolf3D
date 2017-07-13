/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreemerge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:18 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:48 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreemerge(t_btree **root, t_btree *other,
		int (*cmp)(const t_btree*, const t_btree *))
{
	t_data	tmp;

	if (!root || !other || !cmp)
		return ;
	if (!*root)
		return ((void)(*root = other));
	if (other->left)
		ft_btreemerge(root, other->left, cmp);
	tmp.data = other->content;
	tmp.data_size = other->content_size;
	ft_btreeadd(root, &tmp, cmp);
	if (other->right)
		ft_btreemerge(root, other->right, cmp);
}
