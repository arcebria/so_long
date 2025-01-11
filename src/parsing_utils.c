/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:02:02 by arcebria          #+#    #+#             */
/*   Updated: 2025/01/11 18:24:05 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	add_map(t_map *map, char **tmp_map)
{
	int		y;
	int		x;

	map->map = ft_calloc(sizeof(char *), map->height + 1);
	if (!map->map)
		error_exit(NULL, 6);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		map->map[y] = ft_calloc(sizeof(char), map->widht + 1);
		if (!map->map[y])
			error_exit(map->map, 6);
		while (++x < map->widht)
			map->map[y][x] = tmp_map[y][x];
	}
	return (0);
}

/*Estas dos funciones aseguran las rutas hacia los coleccionables y la salida*/

void	fill_map(char **tmp_map, int y, int x, char *path)
{
	if (!ft_strchr(path, tmp_map[y][x]))
		return ;
	if (tmp_map[y][x] == '0')
		tmp_map[y][x] = ' ';
	else if (tmp_map[y][x] == 'E')
		tmp_map[y][x] = 's';
	else if (tmp_map[y][x] == 'C')
		tmp_map[y][x] = 'c';
	fill_map(tmp_map, y + 1, x, path);
	fill_map(tmp_map, y, x + 1, path);
	fill_map(tmp_map, y - 1, x, path);
	fill_map(tmp_map, y, x - 1, path);
}

int	sl_flood_fill(char **tmp_map, t_player p)
{
	int		y;
	int		x;

	fill_map(tmp_map, p.y, p.x, "0EC");
	y = -1;
	while (tmp_map[++y])
	{
		x = -1;
		while (tmp_map[y][++x])
		{
			if (tmp_map[y][x] == 'C' || tmp_map[y][x] == 'E')
				return (1);
		}
	}
	return (0);
}

//checkea que el argumento acaba en .ber

int	check_arg(char *line)
{
	int	i;

	i = ft_strlen(line);
	if (!ft_strnstr(line + (i - 4), ".ber", 4))
		return (1);
	return (0);
}

/*fija la posicion del jugador y establece la posicion P como 0*/

void	set_player(t_player *p, int x, int y, char **tmp_map)
{
	p->x = x;
	p->y = y;
	tmp_map[y][x] = '0';
}
