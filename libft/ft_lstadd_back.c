/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:35:59 by arcebria          #+#    #+#             */
/*   Updated: 2024/11/25 15:39:11 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_node;

	if (!alst || !new)
		return ;
	last_node = ft_lstlast(*alst);
	if (last_node)
		last_node->next = new;
	else
		*alst = new;
}
/*
#include <stdio.h>
int main(void)
{
    t_list   *node1 = ft_lstnew("hola ");
    t_list   *node2 = ft_lstnew("primo");
    t_list   *node3 = ft_lstnew("!");

    node1->next = node2;
    ft_lstadd_back(&node1, node3);
    ft_lstadd_back(&node1, NULL);
    while (node1)
    {
        printf("%s", node1->content);
        node1 = node1->next;
    }
    return (0);
}*/
