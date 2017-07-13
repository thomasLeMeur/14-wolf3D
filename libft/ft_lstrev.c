/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:57 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:52 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*i;
	t_list	*j;
	t_list	*tmp;

	if (!alst || !*alst)
		return ;
	i = *alst;
	tmp = NULL;
	while (i->next)
	{
		j = i->next;
		i->next = tmp;
		tmp = i;
		if (j)
		{
			i = j->next;
			j->next = tmp;
			tmp = j;
		}
	}
	i->next = tmp;
	*alst = i;
}
