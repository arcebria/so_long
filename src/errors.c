/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:45:04 by arcebria          #+#    #+#             */
/*   Updated: 2025/01/11 18:23:26 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_exit(char **map, int n)
{
	if (n == 1)
		ft_putstr_fd(ERROR_CHAR, 2);
	else if (n == 2)
		ft_putstr_fd(ERROR_LIMIT, 2);
	else if (n == 3)
		ft_putstr_fd(ERROR_WIDHT, 2);
	else if (n == 4)
		ft_putstr_fd(ERROR_ITEMS, 2);
	else if (n == 5)
		ft_putstr_fd(ERROR_PATH, 2);
	else if (n == 6)
		ft_putstr_fd(ERROR_MALLOC, 2);
	else if (n == 7)
		ft_putstr_fd(ERROR_MAP, 2);
	else if (n == 8)
		ft_putstr_fd(EMPTY_MAP, 2);
	ft_free_array(map);
	exit (1);
}
