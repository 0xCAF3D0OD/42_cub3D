/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoas2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:30:20 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/22 15:35:15 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_getlen(unsigned int nb)
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

char	*ft_itoa_d(int n)
{
	unsigned int	nb;
	char			*str;
	unsigned int	sign;
	unsigned int	len;

	sign = 0;
	if (n < 0)
		sign = 1;
	nb = n * ((sign * -2) + 1);
	str = (char *) ft_calloc(sizeof(char), ft_getlen(nb) + 1);
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
	ft_rev_str(str);
	return (str);
}
