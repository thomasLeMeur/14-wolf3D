/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeiter_prefix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:46:38 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:41 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeiter_prefix(t_btree *root, void (*f)(void *, size_t))
{
	if (!root || !f)
		return ;
	(*f)(root->content, root->content_size);
	if (root->left)
		ft_btreeiter_prefix(root->left, f);
	if (root->right)
		ft_btreeiter_prefix(root->right, f);
}
