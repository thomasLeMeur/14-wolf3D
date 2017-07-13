/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreesize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:27 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:52 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_btreesize(t_btree *root)
{
	int	x;
	int	y;

	if (!root || (!root->left && !root->right))
		return ((root) ? 1 : 0);
	x = (root->left) ? ft_btreesize(root->left) : 0;
	y = (root->right) ? ft_btreesize(root->right) : 0;
	return (1 + FT_MAX(x, y));
}
