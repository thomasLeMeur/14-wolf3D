/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:55 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:51 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *add)
{
	t_list	*i;

	if (!alst || !add)
		return ;
	if (!*alst)
		return ((void)(*alst = add));
	i = *alst;
	while (i->next)
		i = i->next;
	i->next = add;
}
