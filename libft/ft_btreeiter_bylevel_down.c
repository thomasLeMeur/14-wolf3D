/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeiter_bylevel_down.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:46:30 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:37 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeiter_bylevel_down(t_btree *root,
		void (*f)(void *, size_t, int))
{
	t_btree	*tmp;
	t_list	*lst;

	if (!root || !f)
		return ;
	lst = ft_lstfrom_btree_bylevel_down(root);
	while (lst)
	{
		tmp = (t_btree*)lst->content;
		(*f)(tmp->content, tmp->content_size, ft_btreedepth(tmp));
		ft_lstdequeue(&lst);
	}
}
