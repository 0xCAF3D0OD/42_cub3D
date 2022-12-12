/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:28:16 by amuhleth          #+#    #+#             */
/*   Updated: 2021/10/31 17:05:26 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;

	p = (char *) haystack;
	if (*needle == '\0')
		return (p);
	i = 0;
	while (p[i] && i < len)
	{
		if (p[i] == *needle)
		{
			j = 0;
			while (p[i + j] && p[i + j] == needle[j] && (i + j) < len)
				j++;
			if (needle[j] == '\0')
				return (&p[i]);
		}
		i++;
	}
	return (NULL);
}
