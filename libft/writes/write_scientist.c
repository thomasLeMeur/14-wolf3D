/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_scientist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:38:13 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/30 15:14:31 by tle-meur         ###   ########.fr       */
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

static void	fill_endbuf(t_printf_arg *a, double *vd, int *i, int *vi)
{
	vi[3] = (vi[3]) ? 1 : 0;
	if (vi[0] && (*i += 3))
		ft_memcpy(a->buf + *i - 3, (a->conv & e) ? "nan" : "NAN", 3);
	else if (vi[1] && (*i += 3))
		ft_memcpy(a->buf + *i - 3, (a->conv & e) ? "inf" : "INF", 3);
	else if (!(vi[0] = 0))
	{
		while ((int)(vd[0] / (vd[1] / 10)) < 1 && vi[0]-- > -37)
			vd[0] *= 10.;
		a->buf[(*i)++] = (int)(vd[0] / (vd[1] /= 10)) + '0';
		vd[0] -= (int)(vd[0] / vd[1]) * vd[1];
		if ((a->prec.right || a->flags & conv) && (a->buf[(*i)++] = '.'))
			while (*i < (int)a->size - 4)
			{
				a->buf[(*i)++] = (int)(vd[0] / (vd[1] /= 10)) + '0';
				vd[0] -= (int)(vd[0] / vd[1]) * vd[1];
			}
		a->buf[(*i)++] = (a->conv & e) ? 'e' : 'E';
		vi[0] = (vi[0] == -38 || !vi[0]) ? vi[2] - 1 : vi[0];
		a->buf[(*i)++] = (vi[0] >= 0) ? '+' : '-';
		vi[1] = (vi[0] >= 100) ? 10000 : 1000;
		while ((vi[1] /= 10) > 1)
			a->buf[(*i)++] = FT_ABS((vi[0] %= vi[1])) / (vi[1] / 10) + '0';
	}
}

static void	fill_beginbuf(t_printf_arg *a, double *d, int *i, int neg)
{
	int		j;

	i[3] = (((neg || a->flags & plus) * !i[0]) + (a->flags & space || 0));
	a->size = FT_MAX(a->prec.left, ((a->prec.right + (a->prec.right || 0) + 5) *
	!i[1] + 3 * i[1] + (((neg || a->flags & plus) * !*i) || a->flags & space)));
	if (!(a->buf = ft_strnew(a->size)))
		return ((void)(a->size = 0));
	if (!(j = 0) && a->flags & space && !neg && !i[0])
		a->buf[j++] = ' ';
	i[4] = a->prec.left - 5 * !i[1] - (i[3] - (a->flags & space || 0)) - 3 *
	i[1] - ((a->prec.right + (a->prec.right || a->flags & conv)) * !i[1]);
	if (!(a->flags & less || (a->flags & zero && !i[1] && (neg
		|| a->flags & plus))))
		while (j < i[4])
			a->buf[j++] = (a->flags & zero && !i[1]) ? '0' : ' ';
	if ((neg || a->flags & plus) && !i[0])
		a->buf[j++] = (neg) ? '-' : '+';
	if (!(a->flags & less) && a->flags & zero && !i[1])
		while (j < (int)a->size - a->prec.right - 6)
			a->buf[j++] = '0';
	fill_endbuf(a, d, &j, i);
	if (a->flags & less)
		while (j < (int)a->size)
			a->buf[(j)++] = ' ';
	a->size = j;
}

void		writes_double_sc(double nb, t_printf_arg *a)
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
