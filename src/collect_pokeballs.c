/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_pokeballs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:53:55 by arcebria          #+#    #+#             */
/*   Updated: 2025/01/12 00:32:39 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	collect_pokeballs(t_win *game)
{
	int		i;
	int		count;

	i = 0;
	count = game->map.c_count;
	while (i < count)
	{
		if (game->img->pb->instances[i].y == game->img->t4->instances->y \
		&& game->img->pb->instances[i].x == game->img->t4->instances->x \
		&& game->img->pb->instances[i].enabled == true)
		{
			game->img->pb->instances[i].enabled = false;
			game->p.collect_counter++;
			return ;
		}
		i++;
	}
	if (game->p.collect_counter == game->map.c_count)
		game->img->exo->instances->enabled = true;
}
