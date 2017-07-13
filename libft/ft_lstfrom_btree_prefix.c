/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfrom_btree_prefix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:39 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:41 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfrom_btree_prefix(t_btree *root)
{
	t_list	*lst;

	if (!root)
		return (NULL);
	lst = ft_lstnew(&root, sizeof(root));
	if (root->left && lst)
		lst->next = ft_lstfrom_btree_prefix(root->left);
	if (root->right && lst)
		ft_lstlast(lst)->next = ft_lstfrom_btree_prefix(root->right);
	return (lst);
}
