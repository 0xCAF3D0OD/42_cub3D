/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:14:37 by amuhleth          #+#    #+#             */
/*   Updated: 2021/10/31 17:36:05 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	while (s1[i] && s2[i] && i < n && !result)
	{
		result = (unsigned char) s1[i] - (unsigned char) s2[i];
		i++;
	}
	if (!result && i < n && (!s1[i] || !s2[i]))
		result = (unsigned char) s1[i] - (unsigned char) s2[i];
	return (result);
}
