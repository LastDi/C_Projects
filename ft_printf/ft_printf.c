/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:00:24 by oalvera           #+#    #+#             */
/*   Updated: 2021/12/04 20:00:28 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	char	*tmp;
	int		len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	tmp = s;
	while (*tmp++)
		len++;
	write(1, s, len);
	return (len);
}

int	ft_match(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar((char) va_arg(ap, int)));
	else if (c == '%')
		return (ft_putchar(c));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_uns_putnbr(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putpointer(va_arg(ap, void *), "0123456789abcdef"));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		res;

	res = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
			res += ft_match(*(++s), ap);
		else
			res += ft_putchar(*s);
		s++;
	}
	va_end(ap);
	return (res);
}
