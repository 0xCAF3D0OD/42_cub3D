/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:47:41 by amuhleth          #+#    #+#             */
/*   Updated: 2021/10/27 19:04:22 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	long	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	if (*str == '+' && sign == 1)
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (nb > LONG_MAX / 10 || (nb == LONG_MAX / 10 && *str - '0' > 7))
			return ((((sign + 1) / 2) * -1));
		nb = (*str - '0') + (nb * 10);
		str++;
	}
	return (nb * sign);
}

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

/*int	main(int argc, char **argv)
{
	(void) argc;
	printf("Lib : %d\n", atoi(argv[1]));
	printf("Cust : %d\n", ft_atoi(argv[1]));
	return (0);
} */
