/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:54:28 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/05 14:44:28 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	chaaar;

	chaaar = (char) c;
	p = NULL;
	while (*s)
	{
		if (*s == chaaar)
			p = (char *) s;
		s++;
	}
	if (*s == chaaar)
		p = (char *) s;
	return (p);
}
