/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreerev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:25 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:51 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreerev(t_btree *root)
{
	if (!root)
		return ;
	FT_SWAP((root->left), (root->right), void *);
	if (root->left)
		ft_btreerev(root->left);
	if (root->right)
		ft_btreerev(root->right);
}
