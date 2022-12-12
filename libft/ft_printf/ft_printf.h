/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:34:09 by amuhleth          #+#    #+#             */
/*   Updated: 2021/12/07 15:23:16 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_flags
{
	int	width;
	int	dash;
	int	zero;
	int	dot;
	int	hashtag;
	int	space;
	int	plus;
	int	type;
	int	neg;
}	t_flags;

int		ft_printf(const char *input, ...);

char	*flags_parser(char *str, t_flags *flags);
void	parse_dash(t_flags *flags);
void	parse_width(char c, t_flags *flags);
char	*parse_dot(char *str, t_flags *flags);
void	parse_sign(char c, t_flags *flags);

int		deal_with_c(char c, t_flags *flags);
int		deal_with_s(char *str, t_flags *flags);
int		deal_with_i(int a, t_flags *flags);
int		deal_with_u(int a, t_flags *flags);
int		deal_with_percent(t_flags *flags);
int		deal_with_x(int a, t_flags *flags);
int		deal_with_p(void *p, t_flags *flags);

char	*ft_itoa_x(unsigned int n, char *base);
char	*ft_itoa_p(unsigned long long n, char *base);
char	*ft_itoa_d(int n);
char	*ft_uitoa(unsigned int n);

int		putchar_fd_ret(char c, int fd);
int		putstr_fd_ret(char *str, int fd);
int		print_sign(t_flags *flags);
int		print_hashtag(void);
int		print_nbr(char *str, t_flags *flags);
int		deal_with_width(int width, int printed, t_flags *flags);
int		print_s(char *str, int len);

int		is_type(int c);
int		is_flag(int c);
int		is_sign(t_flags *flags);
int		is_hexa(int c);

#endif
