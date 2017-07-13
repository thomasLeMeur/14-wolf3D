/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:11:19 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/09 21:39:08 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reads.h"
#include "../writes/writes.h"

static void	init_arg(t_printf_arg *arg)
{
	arg->buf = NULL;
	arg->size = 0;
	arg->conv = 0;
	arg->flags = 0;
	arg->prec.left = -1;
	arg->prec.right = -1;
	arg->prec.id_arg = 0;
}

size_t		eval_arg(char *text, t_printf_arg *a)
{
	int	i;
	int hhll;
	int	tmp;

	i = -1;
	hhll = 0;
	while (text[++i])
	{
		if (conv_ind1(text[i], a))
			break ;
		else if ((tmp = width_and_prec(text[i], &text[i], a, 0)))
			i += tmp - 1;
		else if (text[i] == '%')
			break ;
		else if (attr_chars(text[i], a))
			;
		else if (text[i] == '*' && (a->flags |= any))
			break ;
		else if (long_modif(text[i], text[i + 1], a))
			i += ((a->flags & ll || a->flags & hh) && !hhll) ? (hhll = 1) : 0;
		else
			break ;
	}
	return (i);
}

size_t		read_arg(char *text, t_printf_arg *arg, va_list *ap, int first)
{
	size_t	len;
	int		ret;

	if (first)
		init_arg(arg);
	len = eval_arg(text, arg);
	if (!arg->conv && !(arg->flags & any))
	{
		if ((ret = create_wrongbuf(text, len, arg)) == -1)
			return (-1);
		if (ret == 0)
			len--;
	}
	else
	{
		if (!fill_buf(arg, ap, text, &len))
			return (-1);
	}
	return (len + 1);
}
