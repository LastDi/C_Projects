/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:59:59 by oalvera           #+#    #+#             */
/*   Updated: 2021/12/04 20:24:59 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		dc;
	int		tmp;
	char	c;

	dc = 1;
	tmp = n;
	while (tmp / 10 != 0)
	{
		dc *= 10;
		tmp /= 10;
	}
	tmp = 0;
	if (n < 0)
	{
		dc = -dc;
		tmp += ft_putchar('-');
	}
	while (dc != 0)
	{
		c = n / dc + '0';
		tmp += ft_putchar(c);
		n %= dc;
		dc /= 10;
	}
	return (tmp);
}

int	ft_uns_putnbr(unsigned int n)
{
	unsigned int		dc;
	unsigned int		tmp;
	char				c;

	dc = 1;
	tmp = n;
	while (tmp / 10 != 0)
	{
		dc *= 10;
		tmp /= 10;
	}
	tmp = 0;
	while (dc != 0)
	{
		c = n / dc + '0';
		tmp += ft_putchar(c);
		n %= dc;
		dc /= 10;
	}
	return (tmp);
}

int	ft_puthex(unsigned int n, char *s)
{
	unsigned int		dc;
	unsigned int		tmp;
	int					c;

	dc = 1;
	tmp = n;
	while (tmp / 16 != 0)
	{
		dc *= 16;
		tmp /= 16;
	}
	tmp = 0;
	while (dc != 0)
	{
		c = n / dc;
		tmp += ft_putchar(s[c]);
		n %= dc;
		dc /= 16;
	}
	return (tmp);
}

int	ft_putpointer(void *p, char *s)
{
	unsigned long int	dc;
	unsigned long int	tmp;
	int					c;
	int					res;

	dc = 1;
	tmp = (unsigned long int) p;
	res = ft_putstr("0x");
	while (tmp / 16 != 0)
	{
		dc *= 16;
		tmp /= 16;
	}
	tmp = (unsigned long int) p;
	while (dc != 0)
	{
		c = tmp / dc;
		res += ft_putchar(s[c]);
		tmp %= dc;
		dc /= 16;
	}
	return (res);
}
