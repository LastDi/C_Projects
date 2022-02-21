/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:38:32 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/15 22:21:33 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(char const *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s)
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
}

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
