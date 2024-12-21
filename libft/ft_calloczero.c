/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloczero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:32:20 by arcebria          #+#    #+#             */
/*   Updated: 2024/12/21 19:33:45 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloczero(size_t num, size_t size)
{
	void	*memory;
	size_t	i;

	i = 0;
	memory = malloc(num * size);
	if (!memory)
		return (NULL);
	while (i < (num * size))
	{
		((char *)memory)[i] = '\0';
		i++;
	}
	return (memory);
}
