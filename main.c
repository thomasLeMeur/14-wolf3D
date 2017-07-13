/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:56:54 by tle-meur          #+#    #+#             */
/*   Updated: 2016/06/01 18:32:46 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "wolf3d.h"

/*
static int	my_expose_function(t_wolf *w)
{
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	return (1);
}
*/

static int	my_keydown_function(int key, t_wolf *w, double x, double y)
{
	int		action;

	action = 0;
	if (w->over)
		return (1);
	/*w->up = (key == W_UP) ? 1 : w->up;
	w->down = (key == W_DOWN) ? 1 : w->down;
	w->left = (key == W_LEFT) ? 1 : w->left;
	w->right = (key == W_RIGHT) ? 1 : w->right;*/
	w->up = (key == SDLK_UP) ? 1 : w->up;
	w->down = (key == SDLK_DOWN) ? 1 : w->down;
	w->left = (key == SDLK_LEFT) ? 1 : w->left;
	w->right = (key == SDLK_RIGHT) ? 1 : w->right;
	if (w->left != w->right && (action = 1))
		w->view = (w->left) ? fmod(w->view + W_ANGLE_STEP, W_2PI) \
			: fmod(W_2PI + w->view - W_ANGLE_STEP, W_2PI);
	if (w->up != w->down)
	{
		if (w->up && ((x = w->posx + cos(w->view) * W_SPEED) || 1))
			y = w->posy - sin(w->view) * W_SPEED;
		else if ((x = w->posx - cos(w->view) * W_SPEED) || 1)
			y = w->posy + sin(w->view) * W_SPEED;
		if (x < 0 || y < 0 || x >= w->map_w || y >= w->map_h)
			return (wolf_win(w));
		else if (w->map[(int)y][(int)x] == 0 && ((w->posx = x) || 1))
			w->posy = y + (action -= action - 1) - 1;
	}
	return ((action) ? compute_image(w) : 1);
}

static int	my_keyup_function(int key, t_wolf *w)
{
	//if (key == W_ESC)
	if (key == SDLK_ESCAPE)
		return (wolf_quit(w));
	//else if (key == W_UP)
	else if (key == SDLK_UP)
		w->up = 0;
	//else if (key == W_DOWN)
	else if (key == SDLK_DOWN)
		w->down = 0;
	//else if (key == W_LEFT)
	else if (key == SDLK_LEFT)
		w->left = 0;
	//else if (key == W_RIGHT)
	else if (key == SDLK_RIGHT)
		w->right = 0;
	return (1);
}

int			main(int ac, char **av)
{
	t_wolf		w;
	//int			trash;
	SDL_Event	event;

	if (ac < 2)
		return (ft_printf("Usage : ./wolf3d mapfile\n") * 0);
	wolf_init(&w);
	wolf_parse(&w, av[1]);
	/*if (!(w.mlx = mlx_init()))
		return (wolf_error(&w, 2));
	if (!(w.win = mlx_new_window(w.mlx, W_WIDTH, W_HEIGHT, "Wolf3d")))
		return (wolf_error(&w, 4));
	if (!(w.img = mlx_new_image(w.mlx, W_WIDTH, W_HEIGHT)))
		return (wolf_error(&w, 6));
	w.buf = mlx_get_data_addr(w.img, &trash, &w.line, &trash);
	mlx_expose_hook(w.win, &my_expose_function, &w);
	mlx_hook(w.win, 2, 0, &my_keydown_function, &w);
	mlx_key_hook(w.win, &my_keyup_function, &w);
	mlx_hook(w.win, 17, 0, &wolf_quit, &w);
	mlx_do_key_autorepeaton(w.mlx);*/
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		return (wolf_error(&w, 11));
	if (!(w.win = SDL_SetVideoMode(W_WIDTH, W_HEIGHT, 32, \
			SDL_HWSURFACE | SDL_DOUBLEBUF)))
		return (wolf_error(&w, 13));
	SDL_WM_SetCaption("Wolf3d", NULL);
	w.pix = (Uint32 *)w.win->pixels;
	SDL_EnableKeyRepeat(100, 50);
	compute_image(&w);
	//mlx_loop(w.mlx);
	//return (0);
	while (1)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
			my_keydown_function(event.key.keysym.sym, &w, 0., 0.);
		if (event.type == SDL_KEYUP)
			my_keyup_function(event.key.keysym.sym, &w);
		else if (event.type == SDL_QUIT)
			break ;
	}
	return (wolf_quit(&w));
}
