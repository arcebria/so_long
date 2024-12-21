/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <arcebria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:51:26 by arcebria          #+#    #+#             */
/*   Updated: 2024/12/21 19:33:49 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin2(char *s1, char *s2);
void	*ft_calloc2(size_t nmemb, size_t size);
size_t	ft_strlen2(const char *str);
void	*ft_memcpy2(void *dest, const void *src, size_t n);
char	*ft_strchr2(char *s, int c);

#endif
