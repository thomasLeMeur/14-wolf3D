/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:22 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:32 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*i;
	t_list	*j;

	if (alst && *alst && del)
	{
		i = *alst;
		while (i)
		{
			j = i;
			i = i->next;
			ft_lstdelone(&j, del);
		}
		*alst = NULL;
	}
}
