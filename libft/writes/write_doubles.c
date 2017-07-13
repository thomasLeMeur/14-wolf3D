/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:38:13 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/30 15:02:09 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writes.h"

static int	initexp_roundnb(double *nb, int *isneg, double *toten,
			t_printf_arg *arg)
{
	int		i;
	t_nb	dl;
	int		exp;
	double	tmp;

	dl.d = *nb;
	*isneg = (dl.l >> 63) ? 1 : 0;
	dl.d = (*isneg) ? -*nb : *nb;
	*nb = (*isneg) ? -*nb : *nb;
	arg->prec.right = (arg->prec.right == -1) ? 6 : arg->prec.right;
	arg->prec.left = (arg->prec.left == -1) ? 0 : arg->prec.left;
	i = 0;
	tmp = 0.5;
	while (i++ < arg->prec.right)
		tmp *= 0.1;
	if (*nb >= tmp)
		*nb += tmp;
	*toten = 10;
	exp = ((dl.l >> 52) - 1023) * 0.30102999566398119802;
	return (exp);
}

static void	fill_endbuf(t_printf_arg *a, double *vard, int *i, int *vari)
{
	vari[3] = (vari[3]) ? 1 : 0;
	if (vari[0] && (*i += 3))
		ft_memcpy(a->buf + *i - 3, (a->conv & f) ? "nan" : "NAN", 3);
	else if (vari[1] && (*i += 3))
		ft_memcpy(a->buf + *i - 3, (a->conv & f) ? "inf" : "INF", 3);
	else
	{
		vari[4] = FT_MAX(vari[2] + vari[3], (a->prec.left - (a->prec.right
		|| a->flags & conv) - a->prec.right) * !(a->flags & less));
		while (*i < vari[4])
		{
			a->buf[(*i)++] = (int)(vard[0] / (vard[1] /= 10)) + '0';
			vard[0] -= (int)(vard[0] / vard[1]) * vard[1];
		}
		if ((a->prec.right || a->flags & conv) && (a->buf[(*i)++] = '.'))
			while (*i < (int)a->size)
			{
				a->buf[(*i)++] = (int)(vard[0] / (vard[1] /= 10)) + '0';
				vard[0] -= (int)(vard[0] / vard[1]) * vard[1];
			}
	}
}

static void	fill_beginbuf(t_printf_arg *a, double *vd, int *vi, int isneg)
{
	int		i;

	vi[3] = (isneg || a->flags & plus) * !vi[0] + (a->flags & space || 0);
	a->size = FT_MAX(a->prec.left, vi[2] + (vi[3] || 0) + ((a->prec.right
	|| a->flags & conv) + a->prec.right) * !vi[1] + 3 * vi[1]);
	if (!(a->buf = ft_strnew(a->size)))
		return ((void)(a->size = 0));
	if (!(i = 0) && a->flags & space && !isneg && !vi[0])
		a->buf[i++] = ' ';
	vi[4] = a->prec.left - vi[2] - (vi[3] - (a->flags & space || 0)) - 3 *
	vi[1] - ((a->prec.right + (a->prec.right || a->flags & conv)) * !vi[1]);
	if (!(a->flags & less || (a->flags & zero && !vi[1] && (isneg
		|| a->flags & plus))))
		while (i < vi[4])
			a->buf[i++] = (a->flags & zero && !vi[1]) ? '0' : ' ';
	if ((isneg || a->flags & plus) && !vi[0])
		a->buf[i++] = (isneg) ? '-' : '+';
	if (!(a->flags & less) && a->flags & zero && !vi[1])
		while (i < a->prec.left - vi[2])
			a->buf[i++] = '0';
	fill_endbuf(a, vd, &i, vi);
	if (a->flags & less)
		while (i < (int)a->size)
			a->buf[(i)++] = ' ';
	a->size = i;
}

void		writes_double(double nb, t_printf_arg *a)
{
	int		i;
	t_nb	dl;
	int		isneg;
	int		vari[5];
	double	vard[2];

	vard[0] = nb;
	i = initexp_roundnb(&vard[0], &isneg, &vard[1], a);
	dl.d = FT_ABS(vard[0]);
	dl.l >>= 52;
	vari[1] = ((dl.l & 0x7FF) == 0x7FF) ? 1 : 0;
	dl.d = FT_ABS(vard[0]);
	dl.l <<= 12;
	vari[0] = (vari[1] && dl.l) ? 1 : 0;
	vari[2] = (vari[1]) ? 0 : 1;
	if (!vari[1] && i > 0)
		while (i--)
			vard[1] *= 10 + (vari[2]++ && 0);
	fill_beginbuf(a, vard, vari, isneg);
}
