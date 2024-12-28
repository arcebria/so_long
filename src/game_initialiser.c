#include"../inc/beta.h"

int		init_game(t_win *mlx)
{
	mlx->player.moves = 0;
	mlx->player.collect_counter = 0;
	//mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx->mlx = mlx_init(mlx->map.widht, mlx->map.height, "BETA", true);
	if (!mlx->mlx)
		return (0);
	return (1);
}