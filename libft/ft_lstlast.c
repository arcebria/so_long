/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:40:53 by arcebria          #+#    #+#             */
/*   Updated: 2024/11/25 18:53:45 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
/*
#include <stdio.h>
int main(void)
{
    t_list  *node = ft_lstnew("hola");
    t_list  *node2 = ft_lstnew("adios");

    node->next = node2;
    node2->next = NULL;
    printf("%s\n", (char *)ft_lstlast(node)->content);
    return (0);
}*/
