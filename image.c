/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:56:54 by tle-meur          #+#    #+#             */
/*   Updated: 2016/06/01 15:54:56 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <pthread.h>
#include "wolf3d.h"

static void		fill_column(t_wolf *w, int id_column, double dist, int color)
{
	int		i;
	int		top;
	int		bottom;
	int		height;
	int		final_color;

	i = -1;
	height = round(W_WALL_HIG_MULTIPLIER / (dist * W_WALL_SIZE));
	bottom = FT_MIN(W_MIDY + ((height + 1) / 2), W_HEIGHT);
	top = FT_MAX(W_MIDY - (height / 2), 0);
	while (++i < top)
		//((int *)w->buf)[i * W_WIDTH + id_column] = W_SKY;
		w->pix[i * W_WIDTH + id_column] = W_SKY;
	i -= 1;
	dist *= W_SHADOW_FACTOR;
	height = (color >> 16) & 0xff;
	final_color = (int)FT_MAX(0, round(height - height * dist)) << 16;
	height = (color >> 8) & 0xff;
	final_color += (int)FT_MAX(0, round(height - height * dist)) << 8;
	height = (color >> 0) & 0xff;
	final_color += (int)FT_MAX(0, round(height - height * dist));
	while (++i < bottom)
		//((int *)w->buf)[i * W_WIDTH + id_column] = color;
		w->pix[i * W_WIDTH + id_column] = final_color;
	i -= 1;
	while (++i < W_HEIGHT)
		//((int *)w->buf)[i * W_WIDTH + id_column] = W_FLOOR;
		w->pix[i * W_WIDTH + id_column] = W_FLOOR;
}

static double	get_hdist(t_wolf *e, double angle, int *savex, int *savey)
{
	double	x;
	double	y;
	double	Xa;
	double	Ya;

	y = (angle <= W_PI) ? -(e->posy - (int)e->posy) \
		: 1 - (e->posy - (int)e->posy);
	x = fabs(y / tan(angle)) * ((fmod(angle + W_PI2, W_2PI) <= W_PI) ? 1 : -1);
	Ya = (angle <= W_PI) ? -1 : 1;
	Xa = fabs(Ya / tan(angle)) * ((fmod(angle + W_PI2, W_2PI) <= W_PI) ? 1 \
		: -1);
	y = (int)FT_MAX(0, FT_MIN(e->map_h, e->posy + y));
	x = FT_MAX(0, FT_MIN(e->map_w, e->posx + x));
	while (y > 0 && y < e->map_h && x > 0 && x < e->map_w
		&& e->map[(int)y - (angle <= W_PI)][(int)x] == 0)
	{
		y = FT_MAX(0, FT_MIN(e->map_h, y + Ya));
		x = FT_MAX(0, FT_MIN(e->map_w, x + Xa));
	}
	*savex = (int)x;
	*savey = (int)y;
	return (sqrt(pow(e->posx - x, 2) + pow(e->posy - y, 2)));
}

static double	get_vdist(t_wolf *e, double angle, int *savex, int *savey)
{
	double	x;
	double	y;
	double	Xa;
	double	Ya;

	x = (fmod(angle + W_PI2, W_2PI) <= W_PI) ? 1 - (e->posx - (int)e->posx) \
		: -(e->posx - (int)e->posx);
	y = fabs(x * tan(angle)) * ((angle <= W_PI) ? -1 : 1);
	Xa = (fmod(angle + W_PI2, W_2PI) <= W_PI) ? 1 : -1;
	Ya = fabs(Xa * tan(angle)) * ((angle <= W_PI) ? -1 : 1);
	y = FT_MAX(0, FT_MIN(e->map_h, e->posy + y));
	x = (int)FT_MAX(0, FT_MIN(e->map_w, e->posx + x));
	while (y > 0 && y < e->map_h && x > 0 && x < e->map_w
		&& e->map[(int)y][(int)x - !(fmod(angle + W_PI2, W_2PI) <= W_PI)] == 0)
	{
		y = FT_MAX(0, FT_MIN(e->map_h, y + Ya));
		x = FT_MAX(0, FT_MIN(e->map_w, x + Xa));
	}
	*savex = (int)x;
	*savey = (int)y;
	return (sqrt(pow(e->posx - x, 2) + pow(e->posy - y, 2)));
}

static void		*thread_image_function(void *a)
{
	double	d[3];
	int		x[3];
	int		y[3];
	double	ca[2];

	*ca = fmod(W_2PI + ((t_arg *)a)->angle - (((t_arg *)a)->id_column \
		* W_INTER_RAY_ANGLE), W_2PI);
	while (((t_arg *)a)->id_column < W_WIDTH && !(ca[1] = 0))
	{
		d[1] = get_hdist(((t_arg *)a)->w, *ca, &x[1], &y[1]);
		d[2] = get_vdist(((t_arg *)a)->w, *ca, &x[2], &y[2]);
		if (d[1] <= d[2] && ((*x = x[1]) || 1))
			ca[1] += (((*y = y[1]) || 1) && (*ca <= W_PI)) ? W_NORTH : W_SOUTH;
		else if ((*x = x[2]) || 1)
			ca[1] += (((*y = y[2]) || 1) && (fmod(*ca + W_PI2, W_2PI) \
				<= W_PI)) ? W_EAST : W_WEST;
		*d = FT_MIN(d[1], d[2]) * cos(fabs(((t_arg *)a)->w->view - *ca));
		if (*x <= 0 || *x >= ((t_arg *)a)->w->map_w || *y <= 0
				|| *y >= ((t_arg *)a)->w->map_h)
			ca[1] = W_OUT;
		fill_column(((t_arg *)a)->w, ((t_arg *)a)->id_column, *d, ca[1]);
		*ca = fmod(W_2PI + *ca - (W_NB_PTH * W_INTER_RAY_ANGLE), W_2PI);
		((t_arg *)a)->id_column += W_NB_PTH;
	}
	return (NULL);
}

int				compute_image(t_wolf *w)
{
	int		i;
	double	initial_angle;
	t_arg	args[W_NB_PTH];

	i = 0;
	initial_angle = fmod(W_2PI + w->view + 30. * W_PI / 180., W_2PI);
	while (++i < W_NB_PTH)
	{
		args[i].w = w;
		args[i].angle = initial_angle;
		args[i].id_column = i;
		pthread_create(&w->threads[i], NULL, &thread_image_function, &args[i]);
	}
	args[0].w = w;
	args[0].angle = initial_angle;
	args[0].id_column = i;
	thread_image_function(&args[0]);
	i = 0;
	while (++i < W_NB_PTH)
		pthread_join(w->threads[i], NULL);
	//mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	SDL_Flip(w->win);
	return (1);
}
