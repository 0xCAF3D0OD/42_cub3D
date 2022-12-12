/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:49:28 by amuhleth          #+#    #+#             */
/*   Updated: 2021/12/29 19:35:31 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	if (s == NULL)
		return (NULL);
	chr = (char) c;
	while (*s)
	{
		if (*s == chr)
			return ((char *) s);
		s++;
	}
	if (*s == chr)
		return ((char *) s);
	return (NULL);
}
