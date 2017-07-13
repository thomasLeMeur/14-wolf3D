/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedepth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:44:56 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:54:09 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_btreedepth(t_btree *node)
{
	if (!node || !node->parent)
		return (0);
	return (1 + ft_btreedepth(node->parent));
}
