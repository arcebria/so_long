/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:55:46 by arcebria          #+#    #+#             */
/*   Updated: 2025/01/11 18:23:54 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_e_up(t_win *game)
{
	if (game->map.map[game->img->e->instances->y / 32 - 1]
		[game->img->e->instances->x / 32] != '1')
		game->img->e->instances->y -= 32;
}

void	move_e_down(t_win *game)
{
	if (game->map.map[game->img->e->instances->y / 32 + 1]
		[game->img->e->instances->x / 32] != '1')
		game->img->e->instances->y += 32;
}

void	move_e_right(t_win *game)
{
	if (game->map.map[game->img->e->instances->y / 32]
		[game->img->e->instances->x / 32 + 1] != '1')
		game->img->e->instances->x += 32;
}

void	move_e_left(t_win *game)
{
	if (game->map.map[game->img->e->instances->y / 32]
		[game->img->e->instances->x / 32 - 1] != '1')
		game->img->e->instances->x -= 32;
}

void	move_enemy(t_win *game)
{
	int		num;

	num = rand() % 4;
	if (num == 0)
		move_e_up(game);
	else if (num == 1)
		move_e_down(game);
	else if (num == 2)
		move_e_right(game);
	else if (num == 3)
		move_e_left(game);
}
