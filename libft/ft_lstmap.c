/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:51 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:48 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	if (content && content_size)
		free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*add;
	t_list	*tmp;

	if (!f)
		return (NULL);
	add = NULL;
	begin = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		if (!(tmp = (*f)(tmp)))
		{
			if (begin)
				ft_lstdel(&begin, &del);
			break ;
		}
		(!add) ? (begin = tmp) : 0;
		(add) ? (add->next = tmp) : 0;
		add = tmp;
	}
	return (begin);
}
