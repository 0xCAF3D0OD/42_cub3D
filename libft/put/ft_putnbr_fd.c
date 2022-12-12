/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:01:25 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/01 17:12:02 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	unsigned int	sign;

	sign = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		sign = 1;
	}
	nb = n * ((sign * -2) + 1);
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	else
	{
		ft_putchar_fd(nb + '0', fd);
		return ;
	}
	ft_putnbr_fd(nb % 10, fd);
}
