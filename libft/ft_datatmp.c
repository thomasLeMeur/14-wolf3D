/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datatmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:47 by tle-meur          #+#    #+#             */
/*   Updated: 2015/11/23 14:55:05 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	ft_datatmp(void *data, size_t data_size)
{
	t_data	tmp;

	tmp.data = data;
	tmp.data_size = data_size;
	return (tmp);
}
