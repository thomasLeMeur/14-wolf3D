/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfrom_btree_bylevel_up.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:36 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:38 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfrom_btree_bylevel_up(t_btree *root)
{
	t_list	*lst;

	lst = ft_lstfrom_btree_bylevel_down(root);
	ft_lstrev(&lst);
	return (lst);
}
