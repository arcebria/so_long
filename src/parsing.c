/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:02:05 by arcebria          #+#    #+#             */
/*   Updated: 2025/01/11 19:36:05 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*Esta funcion checkea que el mapa cumpla con las siguientes especificaciones
- solo contiene "10CEP"
- limitado por 1
- ancho constante*/

void	syntax_checker(t_map *map, char **tmp_map, t_player *p)
{
	int	x;

	x = 0;
	while (tmp_map[map->height][x])
	{
		if (!ft_strchr("10PEC", tmp_map[map->height][x]))
			error_exit(tmp_map, 1);
		if ((!map->height || !x || !tmp_map[map->height + 1] || \
		!tmp_map[map->height][x + 1]) && tmp_map[map->height][x] != '1')
			error_exit(tmp_map, 2);
		map->e_count += (tmp_map[map->height][x] == 'E');
		map->c_count += (tmp_map[map->height][x] == 'C');
		map->p_count += (tmp_map[map->height][x] == 'P');
		if (tmp_map[map->height][x++] == 'P')
			set_player(p, x - 1, map->height, tmp_map);
	}
	if (map->height == 0)
		map->widht = x;
	else if (map->widht != x)
		error_exit(tmp_map, 3);
}

/*esta funcion convierte el .ber en un array de strings*/

char	*join_lines(char *all_in_one, char *current_line)
{
	char	*tmp_line;

	if (current_line[0] == '\n')
		error_exit(NULL, 8);
	tmp_line = all_in_one;
	all_in_one = ft_strjoin(tmp_line, current_line);
	free(current_line);
	current_line = NULL;
	free(tmp_line);
	return (all_in_one);
}

char	**get_map(int fd)
{
	char	*current_line;
	char	*all_in_one;
	char	**map;

	all_in_one = NULL;
	current_line = get_next_line(fd);
	if (!current_line)
		error_exit(NULL, 8);
	while (current_line)
	{
		all_in_one = join_lines(all_in_one, current_line);
		current_line = get_next_line(fd);
	}
	map = ft_split(all_in_one, '\n');
	if (!map)
		ft_free_array(map);
	free (all_in_one);
	return (map);
}

void	parsing(t_map *map, int fd, t_player *p)
{
	char	**tmp_map;

	tmp_map = get_map(fd);
	ft_bzero(map, sizeof(t_map));
	ft_bzero(p, sizeof(t_player));
	while (tmp_map[map->height])
	{
		syntax_checker(map, tmp_map, p);
		map->height++;
	}
	if (map->c_count < 1 || map->e_count != 1 || map->p_count != 1)
		error_exit(tmp_map, 4);
	if (sl_flood_fill(tmp_map, *p))
		error_exit(tmp_map, 5);
	if (add_map(map, tmp_map))
		error_exit(map->map, 7);
	ft_free_array(tmp_map);
	map->height *= 32;
	map->widht *= 32;
}
