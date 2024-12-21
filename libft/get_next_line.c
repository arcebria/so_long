/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:47:39 by arcebria          #+#    #+#             */
/*   Updated: 2024/12/21 19:33:47 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

char	*ft_free(char **buff, char **buff2)
{
	if (buff && *buff)
	{
		free(*buff);
		*buff = NULL;
	}
	if (buff2 && *buff2)
	{
		free(*buff2);
		*buff2 = NULL;
	}
	return (NULL);
}

char	*update_line(char *static_line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (static_line[i] && static_line[i] != '\n')
		i++;
	if (static_line[i] == '\0')
	{
		free(static_line);
		return (NULL);
	}
	tmp = ft_calloc2(ft_strlen2(static_line) - i + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i++;
	j = 0;
	while (static_line[i])
		tmp[j++] = static_line[i++];
	free(static_line);
	return (tmp);
}

char	*ft_get_line(char *static_line, char *line_def)
{
	int		i;

	i = 0;
	if (!static_line[i])
		return (NULL);
	while (static_line[i] && static_line[i] != '\n')
		i++;
	if (static_line[i] == '\n')
		i++;
	line_def = ft_calloc2(i + 1, sizeof(char));
	if (!line_def)
		return (NULL);
	i = 0;
	while (static_line[i] && static_line[i] != '\n')
	{
		line_def[i] = static_line[i];
		i++;
	}
	if (static_line[i] == '\n')
		line_def[i] = '\n';
	return (line_def);
}

char	*read_line(int fd, char *static_line)
{
	int		bytes_read;
	char	*buffer;

	buffer = ft_calloc2(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (ft_free(&buffer, &static_line));
	bytes_read = 1;
	while (bytes_read > 0 && (!ft_strchr2(buffer, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(&buffer, &static_line));
		buffer[bytes_read] = '\0';
		static_line = ft_strjoin2(static_line, buffer);
		if (!static_line)
			return (NULL);
	}
	free(buffer);
	return (static_line);
}

char	*get_next_line(int fd)
{
	static char	*static_line = NULL;
	char		*line_def;

	line_def = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (static_line == NULL || !ft_strchr2(static_line, '\n'))
		static_line = read_line(fd, static_line);
	if (!static_line)
		return (NULL);
	line_def = ft_get_line(static_line, line_def);
	static_line = update_line(static_line);
	return (line_def);
}
/*
int	main(int ac, char **av)
{
	int 	fd;
	char	*line;
	int		count; // line numbers

	count = 0;
	if (ac == 1)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			write(1, "Cannot read file.\n", 18);
		while (fd)
		{
			line = get_next_line(fd);
			if (line == NULL)
				break ;
			count++;
			printf("LINE [%d] =\n%s\n", count, line);
			printf("------------\n");
			free(line);
			line = NULL;
		}
		close(fd);
	}
	return (0);
}*/
