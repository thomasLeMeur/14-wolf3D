/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreesort_bylevel_down.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:29 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:53 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*sort_level(t_list *begin, size_t level,
		int (*cmp)(const t_btree *, const t_btree *))
{
	t_list	*other;
	t_btree	*a;
	t_btree	*b;

	a = (t_btree*)begin->content;
	while (ft_btreedepth(a) == (int)level)
	{
		other = begin->next;
		b = (t_btree*)other->content;
		while (ft_btreedepth(b) == (int)level)
		{
			if ((*cmp)(a, b) > 0)
				FT_SWAP(a->content, b->content, void *);
			other = other->next;
			b = (t_btree*)other->content;
		}
		begin = begin->next;
		a = (t_btree*)begin->content;
	}
	return (begin);
}

void			ft_btreesort_bylevel_down(t_btree *root,
		int (*cmp)(const t_btree *, const t_btree *))
{
	t_list	*lst;
	t_list	*next;
	size_t	level;

	if (!root || !cmp)
		return ;
	level = 0;
	lst = ft_lstfrom_btree_bylevel_down(root);
	while (lst)
	{
		next = sort_level(lst, level++, cmp);
		while (lst != next)
			ft_lstdequeue(&lst);
	}
}
