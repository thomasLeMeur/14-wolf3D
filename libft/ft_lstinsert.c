/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:45 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:45 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **alst, t_list *add,
		int (*cmp)(const t_list *, const t_list *))
{
	t_list	*i;
	t_list	*tmp;

	if (!alst || !add || !cmp)
		return ;
	if (!*alst)
		return ((void)(*alst = add));
	if ((*cmp)((i = *alst), add) >= 0)
	{
		*alst = add;
		while (add->next)
			add = add->next;
		return ((void)(add->next = i));
	}
	else
		while ((tmp = i->next))
		{
			if ((*cmp)(tmp, add) >= 0)
				break ;
			i = tmp;
		}
	i->next = add;
	while (add->next)
		add = add->next;
	add->next = tmp;
}
