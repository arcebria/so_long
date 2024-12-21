/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:31:34 by arcebria          #+#    #+#             */
/*   Updated: 2024/12/21 19:33:46 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc2(size_t num, size_t size)
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

size_t	ft_strlen2(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_calloc2(1, 1);
	if (!s1 || !s2)
		return (NULL);
	new_str = ft_calloc2((ft_strlen2(s1) + ft_strlen2(s2) + 1), sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_strchr2(char *s, int c)
{
	size_t	i;
	char	ch;

	ch = c;
	i = 0;
	if (ch == '\0')
		return ((char *)s + ft_strlen2(s));
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
