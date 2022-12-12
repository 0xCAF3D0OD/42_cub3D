/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:18:34 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/05 15:10:12 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_end(const char *s1, const char *set)
{
	int	len;
	int	i;

	len = ft_strlen(s1);
	i = 0;
	while (set[i])
	{
		if (set[i] == s1[len - 1])
		{
			len--;
			i = 0;
		}
		else
			i++;
	}
	return (len);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*result;
	int		i;
	int		end;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (set[i])
	{
		if (set[i] == *s1)
		{
			s1++;
			i = 0;
		}
		else
			i++;
	}
	if (*s1 == '\0')
		return (ft_calloc(sizeof(char), 1));
	end = ft_get_end(s1, set);
	result = (char *) ft_calloc(sizeof(char), end + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, end + 1);
	return (result);
}
