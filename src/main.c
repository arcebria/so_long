/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:02:09 by arcebria          #+#    #+#             */
/*   Updated: 2025/01/11 18:24:49 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_win	mlx;
	int		fd;
	int		fd1;

	fd1 = 0;
	srand(time(NULL));
	if (ac != 2)
		return (ft_printf(ERROR_ARG));
	if (check_arg(av[1]))
		return (ft_printf(ERROR_FORMAT));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf(ERROR_OPEN));
	ft_bzero(&mlx, sizeof(t_win));
	parsing(&mlx.map, fd, &mlx.p);
	if (!init_game(&mlx))
		return (ft_printf(ERROR_INIT), 1);
	free(mlx.txt);
	free(mlx.img);
	ft_free_array(mlx.map.map);
}
