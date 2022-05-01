/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 03:27:54 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/20 06:04:42 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_kdiv(int n)
{
	int	kdiv;

	kdiv = 1;
	if (n < 0)
		kdiv = -1;
	while (n / 10 != 0)
	{
		kdiv *= 10;
		n /= 10;
	}
	return (kdiv);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		kdiv;
	char	c;

	kdiv = ft_kdiv(n);
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (kdiv != 0)
	{
		c = n / kdiv + '0';
		ft_putchar_fd(c, fd);
		n %= kdiv;
		kdiv /= 10;
	}
}
