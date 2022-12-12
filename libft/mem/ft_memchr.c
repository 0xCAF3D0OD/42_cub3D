/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:20:57 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/05 15:07:48 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	byte;

	byte = (unsigned char) c;
	p = (unsigned char *) s;
	while (n > 0)
	{
		if (*p == byte)
			return (p);
		p++;
		n--;
	}
	return (NULL);
}
