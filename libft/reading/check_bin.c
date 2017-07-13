/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:11:28 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/29 11:42:06 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reads.h"
#include "../writes/writes.h"

static void	check_bdi(t_printf_arg *arg, va_list *ap)
{
	if (arg->flags & j)
		writes_itoa_base_binary(arg, va_arg(*ap, intmax_t), sizeof(intmax_t));
	else if (arg->flags & ll)
		writes_itoa_base_binary(arg, va_arg(*ap, long long), sizeof(long long));
	else if (arg->flags & l)
		writes_itoa_base_binary(arg, va_arg(*ap, long), sizeof(long));
	else if (arg->flags & z)
		writes_itoa_base_binary(arg, va_arg(*ap, ssize_t), sizeof(ssize_t));
	else if (arg->flags & h)
		writes_itoa_base_binary(arg, (short)va_arg(*ap, int), sizeof(short));
	else if (arg->flags & hh)
		writes_itoa_base_binary(arg, (char)va_arg(*ap, int), sizeof(char));
	else
		writes_itoa_base_binary(arg, va_arg(*ap, int), sizeof(int));
}

static void	check_bu(t_printf_arg *arg, va_list *ap)
{
	if (arg->flags & j)
		writes_itoa_base_binary(arg, va_arg(*ap, uintmax_t), sizeof(uintmax_t));
	else if (arg->flags & ll)
		writes_itoa_base_binary(arg, va_arg(*ap, unsigned long long),
				sizeof(unsigned long long));
	else if (arg->flags & l)
		writes_itoa_base_binary(arg, va_arg(*ap, unsigned long),
				sizeof(unsigned long));
	else if (arg->flags & z)
		writes_itoa_base_binary(arg, va_arg(*ap, size_t), sizeof(size_t));
	else if (arg->flags & h)
		writes_itoa_base_binary(arg, (unsigned short)va_arg(*ap, unsigned int),
				sizeof(unsigned short));
	else if (arg->flags & hh)
		writes_itoa_base_binary(arg, (unsigned char)va_arg(*ap, unsigned int),
				sizeof(unsigned char));
	else
		writes_itoa_base_binary(arg, va_arg(*ap, unsigned int),
				sizeof(unsigned int));
}

void		check_bin(t_printf_arg *arg, va_list *ap)
{
	t_nb	nb;

	if (arg->conv & di)
		check_bdi(arg, ap);
	else if (arg->conv & e || arg->conv & E || arg->conv & f || arg->conv & F)
	{
		nb.d = va_arg(*ap, double);
		writes_itoa_base_binary(arg, nb.l, sizeof(double));
	}
	else
		check_bu(arg, ap);
}
