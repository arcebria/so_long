/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:44:58 by arcebria          #+#    #+#             */
/*   Updated: 2025/01/11 18:24:00 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_win *moves)
{
	if (moves->map.map[moves->img->t4->instances->y / 32 - 1]
		[moves->img->t4->instances->x / 32] != '1')
	{
		moves->img->t1->instances->y -= 32;
		moves->img->t2->instances->y -= 32;
		moves->img->t3->instances->y -= 32;
		moves->img->t4->instances->y -= 32;
		moves->img->t1->instances->enabled = false;
		moves->img->t2->instances->enabled = false;
		moves->img->t3->instances->enabled = false;
		moves->img->t4->instances->enabled = true;
		if (touch_enemy(moves))
			game_ender_l(moves);
		move_enemy(moves);
	}
	moves->p.moves++;
	ft_printf("Movimientos: %d\n", moves->p.moves);
}

void	move_down(t_win *moves)
{
	if (moves->map.map[moves->img->t4->instances->y / 32 + 1]
		[moves->img->t4->instances->x / 32] != '1')
	{
		moves->img->t1->instances->y += 32;
		moves->img->t2->instances->y += 32;
		moves->img->t3->instances->y += 32;
		moves->img->t4->instances->y += 32;
		moves->img->t1->instances->enabled = true;
		moves->img->t2->instances->enabled = false;
		moves->img->t3->instances->enabled = false;
		moves->img->t4->instances->enabled = false;
		if (touch_enemy(moves))
			game_ender_l(moves);
		move_enemy(moves);
	}
	moves->p.moves++;
	ft_printf("Movimientos: %d\n", moves->p.moves);
}

void	move_right(t_win *moves)
{
	if (moves->map.map[moves->img->t4->instances->y / 32]
		[moves->img->t4->instances->x / 32 + 1] != '1')
	{
		moves->img->t1->instances->x += 32;
		moves->img->t2->instances->x += 32;
		moves->img->t3->instances->x += 32;
		moves->img->t4->instances->x += 32;
		moves->img->t1->instances->enabled = false;
		moves->img->t2->instances->enabled = false;
		moves->img->t3->instances->enabled = true;
		moves->img->t4->instances->enabled = false;
		if (touch_enemy(moves))
			game_ender_l(moves);
		move_enemy(moves);
	}
	moves->p.moves++;
	ft_printf("Movimientos: %d\n", moves->p.moves);
}

void	move_left(t_win *moves)
{
	if (moves->map.map[moves->img->t4->instances->y / 32]
		[moves->img->t4->instances->x / 32 - 1] != '1')
	{
		moves->img->t1->instances->x -= 32;
		moves->img->t2->instances->x -= 32;
		moves->img->t3->instances->x -= 32;
		moves->img->t4->instances->x -= 32;
		moves->img->t1->instances->enabled = false;
		moves->img->t2->instances->enabled = true;
		moves->img->t3->instances->enabled = false;
		moves->img->t4->instances->enabled = false;
		if (touch_enemy(moves))
			game_ender_l(moves);
		move_enemy(moves);
	}
	moves->p.moves++;
	ft_printf("Movimientos: %d\n", moves->p.moves);
}

void	moves(mlx_key_data_t keydata, void *param)
{
	t_win	*moves;

	moves = param;
	render_counter(moves);
	game_ender_w(moves);
	game_ender_l(moves);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) \
		&& keydata.action == MLX_PRESS)
		move_up(moves);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) \
		&& keydata.action == MLX_PRESS)
		move_down(moves);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) \
		&& keydata.action == MLX_PRESS)
		move_left(moves);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) \
		&& keydata.action == MLX_PRESS)
		move_right(moves);
	if ((keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS))
		manage_end(2);
	if (moves->map.map[moves->img->t4->instances->y / 32]
		[moves->img->t4->instances->x / 32] == 'c')
		collect_pokeballs(moves);
}
