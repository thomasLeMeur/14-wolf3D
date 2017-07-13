/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:54 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:51 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	if (content && content_size)
		free(content);
}

void		ft_lstpop(t_list **alst)
{
	t_list	*i;
	t_list	*tmp;

	if (!alst || !*alst)
		return ;
	i = *alst;
	while (i->next)
	{
		tmp = i->next;
		if (!tmp->next)
		{
			i->next = NULL;
			ft_lstdelone(&tmp, &del);
		}
		else
			i = tmp;
	}
	if (i == *alst)
		ft_lstdelone(alst, &del);
}
