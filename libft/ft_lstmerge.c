/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:52 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:49 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*other_before_lst(t_list **alst, t_list **other, t_list **i,
		int (*cmp)(const t_list *, const t_list *))
{
	t_list	*tmp;

	*i = *alst;
	if ((*cmp)(*i, *other) > 0)
	{
		*alst = *other;
		*other = (*other)->next;
		(*alst)->next = *i;
	}
	tmp = *alst;
	while (*other && (*cmp)(*i, *other) > 0)
	{
		tmp->next = *other;
		*other = (*other)->next;
		tmp = tmp->next;
	}
	if (*i == tmp)
		*i = (*i)->next;
	return (tmp);
}

static void		next_step(t_list **tmp, t_list **i)
{
	(*tmp)->next = *i;
	*i = (*i)->next;
}

void			ft_lstmerge(t_list **alst, t_list *other,
		int (*cmp)(const t_list *, const t_list *))
{
	t_list	*i;
	t_list	*tmp;

	if (!alst || !other || !cmp)
		return ((void)((alst && !*alst) ? (*alst = other) : 0));
	tmp = other_before_lst(alst, &other, &i, cmp);
	while (i && other)
	{
		if ((*cmp)(i, other) > 0)
		{
			if ((*cmp)(i, other) != 0)
				tmp->next = other;
			else
				next_step(&tmp, &i);
			other = other->next;
		}
		else
			next_step(&tmp, &i);
		tmp = tmp->next;
	}
	if (!i)
		while (other && (*cmp)(tmp, other) > 0)
			other = other->next;
	tmp->next = (!other) ? i : other;
}
