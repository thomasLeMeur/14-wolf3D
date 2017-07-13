/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:16:33 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/22 15:00:54 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reads.h"
#include "../writes/writes.h"

static int	do_work_for_star(t_printf_arg *arg, va_list *ap, char *text,
			size_t *len)
{
	int star;

	star = va_arg(*ap, int);
	if (arg->flags & deci)
	{
		arg->prec.right = FT_ABS(star);
		if (star < 0)
		{
			if (arg->prec.left > arg->prec.right)
				arg->flags |= less;
			else
				arg->prec.right = arg->prec.left;
		}
		(text[++(*len)] == 'c') ? (void)create_wrongbuf(text, *len, arg) :
		(void)read_arg(text + *len, arg, ap, 0);
	}
	else
	{
		arg->prec.left = FT_ABS(star);
		arg->flags |= (star < 0) ? less : arg->flags;
		*len += 1;
		*len += read_arg(text + *len, arg, ap, 0) - 1;
	}
	return (1);
}

int			fill_buf(t_printf_arg *arg, va_list *ap, char *text, size_t *len)
{
	if (text[*len] == '*')
		return (do_work_for_star(arg, ap, text, len));
	else if (arg->conv & di || arg->conv & u || arg->conv & o || arg->conv & x
			|| arg->conv & X)
	{
		if (arg->flags & b)
			check_bin(arg, ap);
		else
			check_dioux(arg, ap);
	}
	else if (arg->conv & e || arg->conv & E || arg->conv & f || arg->conv & F)
	{
		if (arg->flags & b)
			check_bin(arg, ap);
		else if (arg->conv & f || arg->conv & F)
			writes_double(va_arg(*ap, double), arg);
		else if (arg->conv & e || arg->conv & E)
			writes_double_sc(va_arg(*ap, double), arg);
	}
	else if (arg->conv & c || arg->conv & s)
		check_cs(arg, ap);
	else if (arg->conv & Y)
		writes_extra(arg);
	return (1);
}
