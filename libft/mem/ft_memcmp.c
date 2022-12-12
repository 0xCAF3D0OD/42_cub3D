/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:27:03 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/01 16:53:32 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;
	int				result;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	result = 0;
	i = 0;
	while (!result && i < n)
	{
		result = (unsigned char) p1[i] - (unsigned char) p2[i];
		i++;
	}
	return (result);
}
