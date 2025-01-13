/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialiser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:44:14 by arcebria          #+#    #+#             */
/*   Updated: 2025/01/12 00:32:37 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_textures(t_win *g)
{
	g->txt = ft_calloc(1, sizeof(t_txt));
	g->txt->fl = mlx_load_png("./sp/fl.png");
	g->txt->wl = mlx_load_png("./sp/wl.png");
	g->txt->zubat1 = mlx_load_png("./sp/ex/zubat1.png");
	g->txt->zubat2 = mlx_load_png("./sp/ex/zubat2.png");
	g->txt->zubat3 = mlx_load_png("./sp/ex/zubat3.png");
	g->txt->exo = mlx_load_png("./sp/ex/exo.png");
	g->txt->pb = mlx_load_png("./sp/it/pb.png");
	g->txt->e = mlx_load_png("./sp/e/e.png");
	g->txt->t1 = mlx_load_png("./sp/ch/t1.png");
	g->txt->t2 = mlx_load_png("./sp/ch/t2.png");
	g->txt->t3 = mlx_load_png("./sp/ch/t3.png");
	g->txt->t4 = mlx_load_png("./sp/ch/t4.png");
	g->txt->count = mlx_load_png("./sp/count/count.png");
}

void	delete_textures(t_win *g)
{
	mlx_delete_texture(g->txt->fl);
	mlx_delete_texture(g->txt->wl);
	mlx_delete_texture(g->txt->zubat1);
	mlx_delete_texture(g->txt->zubat2);
	mlx_delete_texture(g->txt->zubat3);
	mlx_delete_texture(g->txt->exo);
	mlx_delete_texture(g->txt->pb);
	mlx_delete_texture(g->txt->e);
	mlx_delete_texture(g->txt->t1);
	mlx_delete_texture(g->txt->t2);
	mlx_delete_texture(g->txt->t3);
	mlx_delete_texture(g->txt->t4);
	mlx_delete_texture(g->txt->count);
}

void	set_images(t_win *g)
{
	g->img = ft_calloc(1, sizeof(t_img));
	g->img->fl = mlx_texture_to_image(g->mlx, g->txt->fl);
	g->img->wl = mlx_texture_to_image(g->mlx, g->txt->wl);
	g->img->zubat1 = mlx_texture_to_image(g->mlx, g->txt->zubat1);
	g->img->zubat2 = mlx_texture_to_image(g->mlx, g->txt->zubat2);
	g->img->zubat3 = mlx_texture_to_image(g->mlx, g->txt->zubat3);
	g->img->exo = mlx_texture_to_image(g->mlx, g->txt->exo);
	g->img->pb = mlx_texture_to_image(g->mlx, g->txt->pb);
	g->img->e = mlx_texture_to_image(g->mlx, g->txt->e);
	g->img->t1 = mlx_texture_to_image(g->mlx, g->txt->t1);
	g->img->t2 = mlx_texture_to_image(g->mlx, g->txt->t2);
	g->img->t3 = mlx_texture_to_image(g->mlx, g->txt->t3);
	g->img->t4 = mlx_texture_to_image(g->mlx, g->txt->t4);
	g->img->count = mlx_texture_to_image(g->mlx, g->txt->count);
	delete_textures(g);
}

int	init_game(t_win *game)
{
	game->p.moves = 0;
	game->p.collect_counter = 0;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->map.widht, game->map.height, "So_long", true);
	if (!game->mlx)
		return (0);
	set_textures(game);
	set_images(game);
	render_map(game);
	mlx_key_hook(game->mlx, &moves, game);
	mlx_loop_hook(game->mlx, &hook_loop, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (1);
}
