/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_quit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:56:54 by tle-meur          #+#    #+#             */
/*   Updated: 2016/06/01 16:48:06 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "wolf3d.h"

int	wolf_win(t_wolf *w)
{
	int	i;
	int	j;
	int	tmp;
	//int	*col;
	Uint32	*col;

	i = -1;
	while (++i < W_HEIGHT)
	{
		j = -1;
		while (++j < W_WIDTH)
		{
			//col = &((int *)w->buf)[i * W_WIDTH + j];
			col = &w->pix[i * W_WIDTH + j];
			tmp = (int)round((*col >> 16 & 0xff) * W_WIN_FACTOR) << 16;
			tmp += (int)round((*col >> 8 & 0xff) * W_WIN_FACTOR) << 8;
			tmp += (int)round((*col & 0xff) * W_WIN_FACTOR);
			*col = tmp;
		}
	}
	/*mlx_string_put(w->mlx, w->win, W_WIDTH / 2 - 60, W_HEIGHT / 2 - 20, \
		0xff0000, "YOU WIN !!!");*/
	SDL_Flip(w->win);
	tmp = time(NULL) - w->time;
	fprintf(stderr, "Il t'a fallu %dm%ds.\n", tmp / 60, tmp % 60);
	return ((w->over = 1));
}

int	wolf_init(t_wolf *w)
{
	w->up = 0;
	w->down = 0;
	w->left = 0;
	w->over = 0;
	w->right = 0;
	w->map_h = 0;
	w->map_w = 0;
	//w->buf = NULL;
	//w->img = NULL:
	w->map = NULL;
	//w->mlx = NULL;
	w->pix = NULL;
	w->win = NULL;
	w->time = time(NULL);
	return (1);
}

int	wolf_quit(t_wolf *w)
{
	int	i;

	if (w->map)
	{
		i = -1;
		while (w->map[++i])
			free(w->map[i]);
		free(w->map);
	}
	/*if (w->img)
		mlx_destroy_image(w->mlx, w->img);
	if (w->win)
		mlx_destroy_window(w->mlx, w->win);
	if (w->mlx)
		free(w->mlx);*/
	SDL_Quit();
	exit(0);
	return (0);
}

int	wolf_error(t_wolf *w, int code)
{
	SDL_Quit();
	if (code % 2 == 0)
		ft_printf_fd(2, "wolf3d: %d: Malloc error\n", code);
	else if (code == 1)
		ft_printf_fd(2, "wolf3d: %d: Can't open map file\n", code);
	else if (code == 3)
		ft_printf_fd(2, "wolf3d: %d: Can't close map file\n", code);
	else if (code == 5)
		ft_printf_fd(2, "wolf3d: %d: Error during the map reading\n", code);
	else if (code == 7)
		ft_printf_fd(2, "wolf3d: %d: Only '%c' and '%c', as characters, are " \
			"exepected (at least one '%c' in the map)\n", code, W_EMPTY_CASE, \
			W_WALL_CASE, W_EMPTY_CASE);
	else if (code == 11)
		ft_printf_fd(2, "wolf3d: %d: Didn't succeed to init SDL\n", code);
	else if (code == 13)
		ft_printf_fd(2, "wolf3d: %d: Didn't succeed to create window\n", code);
	return (wolf_quit(w));
}
