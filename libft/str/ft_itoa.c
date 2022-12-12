/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:50:49 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/01 16:52:45 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

static unsigned int	ft_getlen(unsigned int nb, unsigned int sign)
{
	unsigned int	i;

	i = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	if (sign)
		i++;
	return (i);
}

static void	ft_rev_str(char *str)
{
	size_t	len;
	size_t	i;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*str;
	unsigned int	sign;
	unsigned int	len;

	sign = 0;
	if (n < 0)
		sign = 1;
	nb = n * ((sign * -2) + 1);
	str = (char *) ft_calloc(sizeof(char), ft_getlen(nb, sign) + 1);
	if (!str)
		return (NULL);
	len = 0;
	if (!nb)
		str[len] = '0';
	while (nb)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
		len++;
	}
	if (sign)
		str[len] = '-';
	ft_rev_str(str);
	return (str);
}
