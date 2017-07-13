/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datadup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:43 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:02 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	*ft_datadup(t_data *other)
{
	t_data *add;

	add = NULL;
	if (other)
		add = ft_datanew(other->data, other->data_size);
	return (add);
}
