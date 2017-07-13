/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:11:33 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/22 14:59:15 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reads.h"

int			attr_chars(char c, t_printf_arg *arg)
{
	if (c == '#')
		return ((arg->flags |= conv));
	else if (c == '0')
		return ((arg->flags |= zero));
	else if (c == '-')
	{
		if (arg->flags & zero)
			arg->flags -= zero;
		return ((arg->flags |= less));
	}
	else if (c == ' ')
		return ((arg->flags |= space));
	else if (c == '+')
	{
		if (arg->flags & space)
			arg->flags -= space;
		return ((arg->flags |= plus));
	}
	else if (c == '\'')
		return ((arg->flags |= quote));
	return (0);
}

int			long_modif(char c, char next, t_printf_arg *arg)
{
	if (c == 'z')
		return ((arg->flags |= z));
	else if (c == 'j')
		return ((arg->flags |= j));
	else if (c == 'l')
	{
		if (next == 'l')
			return ((arg->flags |= ll));
		return ((arg->flags |= l));
	}
	else if (c == 'h')
	{
		if (next == 'h')
			return ((arg->flags |= hh));
		return ((arg->flags |= h));
	}
	else if (c == 'b')
		return ((arg->flags |= b));
	return (0);
}

static int	conv_ind2(char ci, t_printf_arg *arg)
{
	if (ci == 'S')
		return ((arg->conv = s) && (arg->flags |= l));
	else if (ci == 'U')
		return ((arg->conv = u) && (arg->flags |= l));
	else if (ci == 'p')
		return ((arg->conv = x) && (arg->flags |= conv) && (arg->flags |= l)
				&& (arg->flags |= p));
	else if (ci == 'c')
		return ((arg->conv = c));
	else if (ci == 's')
		return ((arg->conv = s));
	else if (ci == 'Y')
		return ((arg->conv = Y));
	return (0);
}

int			conv_ind1(char ci, t_printf_arg *arg)
{
	if (ci == 'd' || ci == 'i')
		return ((arg->conv = di));
	else if (ci == 'D')
		return ((arg->conv = di) && (arg->flags |= l));
	else if (ci == 'o')
		return ((arg->conv = o));
	else if (ci == 'O')
		return ((arg->conv = o) && (arg->flags |= l));
	else if (ci == 'u')
		return ((arg->conv = u));
	else if (ci == 'x')
		return ((arg->conv = x));
	else if (ci == 'X')
		return ((arg->conv = X));
	else if (ci == 'e')
		return ((arg->conv = e));
	else if (ci == 'E')
		return ((arg->conv = E));
	else if (ci == 'f')
		return ((arg->conv = f));
	else if (ci == 'F')
		return ((arg->conv = F));
	else if (ci == 'C')
		return ((arg->conv = c) && (arg->flags |= l));
	return (conv_ind2(ci, arg));
}

int			width_and_prec(char c, char *text, t_printf_arg *arg, int len)
{
	if (c >= '1' && c <= '9' && (arg->prec.left = ft_atoi(text)))
		while (ft_isdigit((c = text[len])))
			len++;
	if (c == '.')
	{
		arg->flags |= deci;
		arg->prec.right = ft_atoi(&text[++len]);
		while (ft_isdigit((c = text[len])))
			len++;
	}
	return (len);
}
