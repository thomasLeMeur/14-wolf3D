/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdequeue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:31 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:35 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	if (content && content_size)
		free(content);
}

void		ft_lstdequeue(t_list **alst)
{
	t_list	*tmp;

	if (!alst || !*alst)
		return ;
	tmp = *alst;
	*alst = tmp->next;
	ft_lstdelone(&tmp, &del);
}
