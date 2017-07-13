/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:11:24 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/15 13:20:23 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reads.h"
#include "../writes/writes.h"

static void	check_c(t_printf_arg *arg, va_list *ap)
{
	if (arg->flags & l)
		writes_wintt(va_arg(*ap, wint_t), arg);
	else
		writes_uchar((unsigned char)va_arg(*ap, int), arg);
}

static void	check_s(t_printf_arg *arg, va_list *ap)
{
	if (arg->flags & l)
		writes_wstr(va_arg(*ap, wchar_t *), arg);
	else
		writes_str(va_arg(*ap, char *), arg);
}

void		check_cs(t_printf_arg *arg, va_list *ap)
{
	if (arg->conv & c)
		check_c(arg, ap);
	else if (arg->conv & s)
		check_s(arg, ap);
}
