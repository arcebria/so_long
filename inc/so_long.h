/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:02:11 by arcebria          #+#    #+#             */
/*   Updated: 2025/01/12 00:30:27 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
# define EMPTY_MAP "Error\nLínea vacía encontrada.\n"
# define ERROR_INIT "Error\nFallo al inicializar el juego.\n"
# define WIN_MESSAGE "Enhorabuena!! Has atrapado a todos.\n"
# define LOSE_MESSAGE "Que pena!! El Clefairy salvaje te atrapó.\n"
# define ESC_MESSAGE "Has salido del juego.\n"

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <time.h>

typedef struct s_line
{
	char	*current_line;
	char	*all_in_one;
	char	*tmp_line;
	char	**map;
	int		flag;
}	t_line;

typedef struct s_txt
{
	mlx_texture_t	*fl;
	mlx_texture_t	*wl;
	mlx_texture_t	*zubat1;
	mlx_texture_t	*zubat2;
	mlx_texture_t	*zubat3;
	mlx_texture_t	*exo;
	mlx_texture_t	*pb;
	mlx_texture_t	*e;
	mlx_texture_t	*t1;
	mlx_texture_t	*t2;
	mlx_texture_t	*t3;
	mlx_texture_t	*t4;
	mlx_texture_t	*count;
}	t_txt;

typedef struct s_img
{
	mlx_image_t	*fl;
	mlx_image_t	*wl;
	mlx_image_t	*zubat1;
	mlx_image_t	*zubat2;
	mlx_image_t	*zubat3;
	mlx_image_t	*exo;
	mlx_image_t	*pb;
	mlx_image_t	*e;
	mlx_image_t	*t1;
	mlx_image_t	*t2;
	mlx_image_t	*t3;
	mlx_image_t	*t4;
	mlx_image_t	*count;
}	t_img;

typedef struct s_map
{
	int		height;
	int		widht;
	int		c_count;
	int		p_count;
	int		e_count;
	char	**map;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		collect_counter;
	int		moves;
}	t_player;

typedef struct s_win
{
	mlx_t		*mlx;
	t_player	p;
	t_map		map;
	t_txt		*txt;
	t_img		*img;
}	t_win;

void	parsing(t_map *map, int fd, t_player *p);
int		check_arg(char *line);
char	**get_map(int fd);
void	syntax_checker(t_map *map, char **tmp_map, t_player *p);
void	set_player(t_player *p, int x, int y, char **tmp_map);
int		sl_flood_fill(char **tmp_map, t_player p);
void	fill_map(char **tmp_map, int y, int x, char *path);
void	error_exit(char **map, int n);
int		add_map(t_map *map, char **tmp_map);
int		init_game(t_win *mlx);
void	set_textures(t_win *mlx);
void	set_images(t_win *mlx);
void	render_map(t_win *g);
void	moves(mlx_key_data_t keydata, void *param);
void	collect_pokeballs(t_win *game);
void	move_enemy(t_win *game);
void	game_ender_w(t_win *game);
void	game_ender_l(t_win *game);
void	render_counter(t_win *game);
void	manage_end(int i);
int		touch_enemy(t_win *g);
void	hook_loop(void *param);

#endif
