/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeiter_suffix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:46:42 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:44 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeiter_suffix(t_btree *root, void (*f)(void *, size_t))
{
	if (!root || !f)
		return ;
	if (root->left)
		ft_btreeiter_suffix(root->left, f);
	if (root->right)
		ft_btreeiter_suffix(root->right, f);
	(*f)(root->content, root->content_size);
}
