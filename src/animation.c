/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:01:33 by arcebria          #+#    #+#             */
/*   Updated: 2025/01/13 16:13:59 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	animate_exit(t_win *game)
{
	static double	last_time = 0;
	static int		state = 0;
	double			current_time;

	current_time = mlx_get_time();
	if (current_time - last_time > 0.1)
	{
		game->img->zubat1->instances->enabled = false;
		game->img->zubat2->instances->enabled = false;
		game->img->zubat3->instances->enabled = false;
		if (state == 0)
			game->img->zubat1->instances->enabled = true;
		else if (state == 1)
			game->img->zubat2->instances->enabled = true;
		else if (state == 2)
			game->img->zubat3->instances->enabled = true;
		state = (state + 1) % 3;
		last_time = current_time;
	}
}

void	hook_loop(void *param)
{
	t_win	*game;

	game = param;
	animate_exit(game);
}
