/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:27:25 by amuhleth          #+#    #+#             */
/*   Updated: 2022/07/25 18:43:15 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	print_mem(t_mem **lst)
{
	t_mem	*p;

	if (!lst)
		return ;
	if (!*lst)
	{
		printf("Collector is empty!\n\n");
		return ;
	}
	p = *lst;
	while (p)
	{
		// to do ft_printf
		printf("Ptr: %p, prev: %p, next: %p\n", p->ptr, p->prev, p->next);
		p = p->next;
	}
	printf("\n");
}
