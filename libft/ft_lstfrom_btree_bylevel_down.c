/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfrom_btree_bylevel_down.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:35 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:37 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfrom_btree_bylevel_down(t_btree *root)
{
	t_list	*beg;
	t_list	*lst;
	t_btree	*tmp;
	t_btree	*child;
	int		is_empty;

	lst = NULL;
	is_empty = 0;
	ft_lstpush(&lst, ft_lstnew(root, sizeof(*root)));
	beg = lst;
	while (lst && (lst->next || !is_empty))
	{
		is_empty = 1;
		tmp = (t_btree*)lst->content;
		if ((child = tmp->left)
			&& !(is_empty = 0))
			ft_lstpush(&lst, ft_lstnew(child, sizeof(*child)));
		if ((child = tmp->right)
			&& !(is_empty = 0))
			ft_lstpush(&lst, ft_lstnew(child, sizeof(*child)));
		lst = lst->next;
	}
	return (beg);
}
