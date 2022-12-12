/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:32:56 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/15 17:43:35 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else
		{
			j = 1;
			while (base[i + j])
			{
				if (base[i] == base[i + j])
					return (0);
				j++;
			}
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

static void	reverse_str(char *str, int minus)
{
	int		len;
	int		i;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i + minus];
		str[i + minus] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
}

static void	ft_switch_base(unsigned long long nb, char *base, char *nb_dest)
{
	unsigned int		len_base;
	int					i;

	i = 0;
	len_base = ft_strlen(base);
	if (nb == 0)
	{
		nb_dest[i] = base[0];
		i++;
	}
	while (nb > 0)
	{
		nb_dest[i] = base[nb % len_base];
		nb = nb / len_base;
		i++;
	}
	nb_dest[i] = 0;
	reverse_str(nb_dest, 0);
}

char	*ft_itoa_x(unsigned int n, char *base)
{
	char	*result;

	if (!base_is_valid(base))
		return (NULL);
	result = ft_calloc(sizeof(char), 34);
	ft_switch_base(n, base, result);
	return (result);
}

char	*ft_itoa_p(unsigned long long n, char *base)
{
	char	*result;

	if (!base_is_valid(base))
		return (NULL);
	result = ft_calloc(sizeof(char), 34);
	ft_switch_base(n, base, result);
	return (result);
}
