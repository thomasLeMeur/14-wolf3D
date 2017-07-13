/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfrom_btree_suffix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:40 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:42 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfrom_btree_suffix(t_btree *root)
{
	t_list	*lst;
	t_list	*last;

	if (!root)
		return (NULL);
	lst = NULL;
	if (root->left)
		lst = ft_lstfrom_btree_suffix(root->left);
	if (root->right)
	{
		if ((last = ft_lstlast(lst)))
			last->next = ft_lstfrom_btree_suffix(root->right);
		else
		{
			last = ft_lstfrom_btree_suffix(root->right);
			lst = last;
		}
	}
	if ((last = ft_lstlast(lst)))
		last->next = ft_lstnew(&root, sizeof(root));
	else
		lst = ft_lstnew(&root, sizeof(root));
	return (lst);
}
