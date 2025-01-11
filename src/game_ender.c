/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ender.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:31:08 by arcebria          #+#    #+#             */
/*   Updated: 2025/01/11 18:23:34 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	touch_enemy(t_win *g)
{
	if (g->img->t1->instances->x == g->img->e->instances->x
		&& g->img->t1->instances->y
		== g->img->e->instances->y)
		return (1);
	return (0);
}

void	manage_end(int i)
{
	if (i == 0)
		ft_printf(WIN_MESSAGE);
	else if (i == 1)
		ft_printf(LOSE_MESSAGE);
	else if (i == 2)
		ft_printf(ESC_MESSAGE);
	exit (0);
}

void	game_ender_w(t_win *game)
{
	if (game->p.collect_counter == game->map.c_count
		&& game->map.map[game->img->t4->instances->y / 32]
		[game->img->t4->instances->x / 32] == 's')
		manage_end (0);
}

void	game_ender_l(t_win *game)
{
	if (game->img->t1->instances->x == game->img->e->instances->x
		&& game->img->t1->instances->y == game->img->e->instances->y)
		manage_end (1);
}
