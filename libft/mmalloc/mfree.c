/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:04:24 by amuhleth          #+#    #+#             */
/*   Updated: 2022/07/25 18:38:18 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*get_elem_location(void	*ptr)
{
	char	*p;

	p = ptr;
	return (p - sizeof(t_mem));
}

void	mfree(t_mem **lst, void *ptr)
{
	t_mem	*elem;

	if (ptr == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
		return ;
	elem = get_elem_location(ptr);
	if (elem->prev == NULL && elem->next == NULL)
		*lst = NULL;
	else if (elem->prev == NULL)
		*lst = elem->next;
	if (elem->prev != NULL)
		elem->prev->next = elem->next;
	if (elem->next != NULL)
		elem->next->prev = elem->prev;
	free(elem);
}
