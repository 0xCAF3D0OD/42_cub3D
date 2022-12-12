/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:07:14 by amuhleth          #+#    #+#             */
/*   Updated: 2021/12/07 15:23:44 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	unsigned int	len;

	str = (char *) ft_calloc(sizeof(char), ft_getlen(n) + 1);
	if (!str)
		return (NULL);
	len = 0;
	if (!n)
		str[len] = '0';
	while (n)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len++;
	}
	ft_rev_str(str);
	return (str);
}
