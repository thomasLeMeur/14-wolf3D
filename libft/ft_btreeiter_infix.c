/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeiter_infix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:46:35 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:39 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeiter_infix(t_btree *root, void (*f)(void *, size_t))
{
	if (!root || !f)
		return ;
	if (root->left)
		ft_btreeiter_infix(root->left, f);
	(*f)(root->content, root->content_size);
	if (root->right)
		ft_btreeiter_infix(root->right, f);
}
