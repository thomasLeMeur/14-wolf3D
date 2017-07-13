/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:56:54 by tle-meur          #+#    #+#             */
/*   Updated: 2016/06/01 18:29:25 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <SDL/SDL.h>
# include <pthread.h>
# include "libft.h"

/*
# define W_ESC					53
# define W_LEFT					123
# define W_RIGHT				124
# define W_DOWN					125
# define W_UP					126
*/

# define W_PI					3.1415926535897931159979634685441851615905761718
# define W_PI2					1.5707963267948965579989817342720925807952880859
# define W_2PI					6.2831853071795862319959269370883703231811523437

# define W_NB_PTH				8
# define W_SHADOW_FACTOR		0.05
# define W_WIN_FACTOR			0.6
# define W_EMPTY_CASE			'0'
# define W_WALL_CASE			'1'

# define W_FLOOR				0xc7c69c
# define W_OUT					0xffffff
# define W_SKY					0x30dfec
# define W_NORTH				0xc70056
# define W_WEST					0x0a0095
# define W_EAST					0x018e4c
# define W_SOUTH				0xb0cb00

# define W_HEIGHT				940
# define W_WIDTH				1280
# define W_MIDX					( ( ( W_WIDTH ) + 1) / 2 )
# define W_MIDY					( ( ( W_HEIGHT ) + 1) / 2 )

# define W_SPEED				0.1
# define W_WALL_SIZE			64
# define W_PLAYER_SIZE			( ( W_WALL_S ) / 2 )
# define W_VISUAL_FIELD			60
# define W_DIST_FROM_CAM		( ( W_MIDX ) / tan( ( W_VISUAL_FIELD * ( W_PI) / 180. ) / 2. ) )
# define W_INTER_RAY_ANGLE		( ( ( W_VISUAL_FIELD ) / (float)( W_WIDTH ) ) * ( W_PI ) / 180. )
# define W_WALL_HIG_MULTIPLIER	( ( W_WALL_SIZE ) * ( W_DIST_FROM_CAM ) )

# define W_ANGLE_STEP			( 2. * ( W_PI ) / 100. )

typedef struct	s_wolf
{
	//void		*mlx;
	/*void*/SDL_Surface	*win;
	//void		*img;
	//void		*buf;
	Uint32		*pix;
	int			line;
	double		posx;
	double		posy;
	double		view;
	int			over;
	int			**map;
	int			map_h;
	int			map_w;
	int			up;
	int			down;
	int			left;
	int			right;
	pthread_t	threads[W_NB_PTH];
	time_t		time;
}				t_wolf;

typedef struct	s_arg
{
	t_wolf	*w;
	double	angle;
	int		id_column;
}				t_arg;

/*
**	init_and_quit.c
*/
int				wolf_win(t_wolf *w);
int				wolf_init(t_wolf *w);
int				wolf_quit(t_wolf *w);
int				wolf_error(t_wolf *w, int code);

/*
**	parser.c
*/
int				wolf_parse(t_wolf *w, char *file);

/*
**	image.c
*/
int				compute_image(t_wolf *w);

#endif
