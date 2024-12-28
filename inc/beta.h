/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beta.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:02:11 by arcebria          #+#    #+#             */
/*   Updated: 2024/12/21 20:58:30 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BETA_H
# define BETA_H

# define ERROR_ARG "Error\nArchivo de mapa no proporcionado.\n"
# define ERROR_FORMAT "Error\nArchivo de mapa incorrecto.\n"
# define ERROR_OPEN "Error\nError al abrir el archivo de mapa.\n"
# define ERROR_CHAR "Error\nCarácteres incorrectos encontrados en el mapa.\n"
# define ERROR_LIMIT "Error\nLimites del mapa incorrectos.\n"
# define ERROR_WIDHT "Error\nAncho de mapa no constante.\n"
# define ERROR_ITEMS "Error\nElementos del mapa inesperados.\n"
# define ERROR_PATH "Error\nImposible alcanzar los objetivos.\n"
# define ERROR_MALLOC "Error\nFallo al asignar memoria.\n"
# define ERROR_MAP "Error\nFallo al cargar el mapa.\n"
# define ERROR_INIT "Error\nFallo al inicializar el juego\n"

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	void	*img;
	int		len;
	int		widht;
}	t_data;

typedef struct s_map
{
	int		height;
	int		widht;
	int		c_count;
	int		p_count;
	int		e_count;
	char	**map;
	t_data	*sprites;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		collect_counter;
	int		moves;
	int		sprite;
}	t_player;

typedef struct s_win
{
	void		*mlx;
	mlx_t		*win;
	int			event;
	t_player	player;
	t_map		map;
}	t_win;

void	parsing(t_map *map, int fd, t_player *p);
int		check_arg(char *line);
char	**get_map(int fd);
void	syntax_checker(t_map *map, char **tmp_map, t_player *p);
void	set_player(t_player *p, int x, int y, char **tmp_map);
int		sl_flood_fill(char **tmp_map, t_player p);
void	fill_map(char **tmp_map, int y, int x, char *path);
void	error_exit(char **map, int n);
int		add_map(t_map *map,  char **tmp_map);
int		init_game(t_win *mlx);

#endif
