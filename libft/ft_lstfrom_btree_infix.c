/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfrom_btree_infix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:38 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:39 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfrom_btree_infix(t_btree *root)
{
	t_list	*lst;
	t_list	*last;

	if (!root)
		return (NULL);
	lst = NULL;
	if (root->left)
		lst = ft_lstfrom_btree_infix(root->left);
	if ((last = ft_lstlast(lst)))
	{
		if ((last->next = ft_lstnew(&root, sizeof(root))))
			last = last->next;
	}
	else
	{
		lst = ft_lstnew(&root, sizeof(root));
		last = lst;
	}
	if (root->right && last)
		last->next = ft_lstfrom_btree_infix(root->right);
	return (lst);
}
