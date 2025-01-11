/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:07:43 by arcebria          #+#    #+#             */
/*   Updated: 2025/01/11 18:49:35 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_exit(t_win *g, int y, int x)
{
	mlx_image_to_window(g->mlx, g->img->exc, x * 32, y * 32);
	mlx_image_to_window(g->mlx, g->img->exo, x * 32, y * 32);
	g->img->exo->instances->enabled = false;
}

void	render_counter(t_win *g)
{
	char	*numbers;

	numbers = ft_itoa(g->p.moves);
	mlx_image_to_window(g->mlx, g->img->count, 0, 0);
	mlx_put_string(g->mlx, numbers, 25, 2);
	free (numbers);
}

void	render_enemy(t_win *g)
{
	int		y;
	int		x;

	y = rand() % (g->map.height / 32);
	x = rand() % (g->map.widht / 32);
	while (g->map.map[y][x] != ' ' || (x == g->p.x && y == g->p.y))
	{
		y = rand() % (g->map.height / 32);
		x = rand() % (g->map.widht / 32);
	}
	mlx_image_to_window(g->mlx, g->img->e, x * 32, y * 32);
}

void	render_player(t_win *g)
{
	mlx_image_to_window(g->mlx, g->img->t1, g->p.x * 32, g->p.y * 32);
	mlx_image_to_window(g->mlx, g->img->t2, g->p.x * 32, g->p.y * 32);
	mlx_image_to_window(g->mlx, g->img->t3, g->p.x * 32, g->p.y * 32);
	mlx_image_to_window(g->mlx, g->img->t4, g->p.x * 32, g->p.y * 32);
	g->img->t1->instances->enabled = false;
	g->img->t2->instances->enabled = false;
	g->img->t3->instances->enabled = false;
}

void	render_map(t_win *g)
{
	int		x;
	int		y;

	y = -1;
	while (g->map.map[++y])
	{
		x = -1;
		while (g->map.map[y][++x])
		{
			if (g->map.map[y][x] == ' ' ||
			g->map.map[y][x] == 'c' || g->map.map[y][x] == 'P')
				mlx_image_to_window(g->mlx, g->img->fl, x * 32, y * 32);
			if (g->map.map[y][x] == '1')
				mlx_image_to_window(g->mlx, g->img->wl, x * 32, y * 32);
			if (g->map.map[y][x] == 'c')
				mlx_image_to_window(g->mlx, g->img->pb, x * 32, y * 32);
			if (g->map.map[y][x] == 's')
				render_exit(g, y, x);
		}
	}
	render_player(g);
	render_enemy(g);
	render_counter(g);
}
