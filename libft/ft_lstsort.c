/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:01 by tle-meur          #+#    #+#             */
/*   Updated: 2016/01/14 18:17:25 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list *lst, int (*cmp)(const t_list *, const t_list *))
{
	t_list	*i;
	t_list	*j;

	if (!lst || !cmp)
		return ;
	i = lst;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if ((*cmp)(i, j) > 0)
			{
				FT_SWAP(i->content, j->content, void *);
			}
			j = j->next;
		}
		i = i->next;
	}
}
