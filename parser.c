/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:56:54 by tle-meur          #+#    #+#             */
/*   Updated: 2016/06/01 15:43:40 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <fcntl.h>
#include "wolf3d.h"

static void	init_first_pos(t_wolf *w)
{
	int	i;
	int	x;
	int	y;
	int number;

	i = 0;
	y = 0;
	x = 0;
	srand(w->time);
	number = (rand() % 5000) + 1;
	while (i != number && (y = -1))
	{
		while (i != number && ++y < w->map_h && (x = -1))
		{
			while (i != number && ++x < w->map_w)
				if (w->map[y][x] == 0)
					i++;
		}
		if (i == 0)
			return ((void)wolf_error(w, 7));
	}
	w->posx = x + 0.5;
	w->posy = y + 0.5;
	w->view = (rand() % 360) / 180. * W_PI;
}

static int	fill_map_with_offset(t_wolf *w)
{
	int		i;
	int		len;
	int		*tmp;

	if (w->map_w < 1)
		return (wolf_error(w, 7));
	i = -1;
	while (++i < w->map_h)
	{
		len = 0;
		while (w->map[i][len] != -1)
			len++;
		if (len != w->map_w)
		{
			if (!(tmp = (int *)ft_memrealloc(w->map[i], len * sizeof(int), \
					(w->map_w + 1) * sizeof(int))))
				return (wolf_error(w, 1000000 + i * 2));
			w->map[i] = tmp;
			while (len < w->map_w)
				w->map[i][len++] = 1;
			w->map[i][len] = -1;
		}
	}
	init_first_pos(w);
	return (1);
}

static char	**get_line_split(t_wolf *w, char *line, int *len)
{
	int		i;
	//int		val;
	char	**split;

	i = -1;
	while (line[++i])
		if (line[i] == '\t')
			line[i] = ' ';
	if (((i -= i + 1) || 1) && !(split = ft_strsplit(line, ' ')))
	{
		free(line);
		close(w->line);
		wolf_error(w, 8);
	}
	//while (split[++i] && ((val = ft_atoi(split[i])) || 1))
	//	if (!ft_isnumber(split[i]) || val < 0)
	while (split[++i])
		if (strlen(split[i]) > 1
				|| (*split[i] != W_EMPTY_CASE && *split[i] != W_WALL_CASE))
		{
			free(line);
			close(w->line);
			ft_tabdel((void ***)&split);
			wolf_error(w, 7);
		}
	if ((*len = i) > w->map_w)
		w->map_w = i;
	return (split);
}

static void	add_to_map(t_wolf *w, char **split, int len, char *line)
{
	int	i;
	int	**tmp;

	if (!(tmp = (int **)ft_memrealloc(w->map, w->map_h * sizeof(int *), \
			(w->map_h + 2) * sizeof(int *))))
	{
		free(line);
		close(w->line);
		ft_tabdel((void ***)&split);
		wolf_error(w, 100 + w->map_h * 2);
	}
	w->map = tmp;
	if (!(w->map[w->map_h++] = (int *)ft_memalloc((len + 1) * sizeof(int))))
	{
		free(line);
		close(w->line);
		ft_tabdel((void ***)&split);
		wolf_error(w, 10000 + w->map_h * 2);
	}
	i = -1;
	while (++i < len)
		w->map[w->map_h - 1][i] = ft_atoi(split[i]);
	w->map[w->map_h - 1][len] = -1;
}

int			wolf_parse(t_wolf *w, char *file)
{
	int		ret;
	int		len;
	char	*line;
	char	**split;

	line = NULL;
	if ((w->line = open(file, O_RDWR)) == -1)
		return (wolf_error(w, 1));
	if (!(w->map = (int **)ft_memalloc((w->map_h + 1) * sizeof(int *))))
	{
		close(w->line);
		return (wolf_error(w, 100 + w->map_h * 2));
	}
	while ((ret = ft_gnl(w->line, &line)) > 0)
	{
		split = get_line_split(w, line, &len);
		add_to_map(w, split, len, line);
		ft_tabdel((void ***)&split);
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	if (close(w->line) == -1)
		return (wolf_error(w, 3));
	return ((ret == -1) ? wolf_error(w, 5) : fill_map_with_offset(w));
}
