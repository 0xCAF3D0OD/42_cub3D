/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmalloc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:25:14 by amuhleth          #+#    #+#             */
/*   Updated: 2022/07/25 18:37:27 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct	s_mem t_mem;

typedef struct	s_mem
{
	void	*ptr;
	t_mem	*prev;
	t_mem	*next;
}				t_mem;

void	*mmalloc(t_mem **list, size_t size);
int		mfree(t_mem **lst, void *ptr);
int		mmalloc_free(void);
void	print_mem(t_mem **lst);
