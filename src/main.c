/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:02:09 by arcebria          #+#    #+#             */
/*   Updated: 2024/12/21 20:58:26 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/beta.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_win	mlx;
	int		fd;

	if (ac != 2)
		return (ft_printf(ERROR_ARG));
	if (check_arg(av[1]))
		return (ft_printf(ERROR_FORMAT));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf(ERROR_OPEN));
	ft_bzero(&mlx, sizeof(t_win));
	parsing(&mlx.map, fd, &mlx.p);
	ft_free_array(mlx.map.map); //ESTO SOBRA, SOLO PARA NO TENER LEAKS
}
