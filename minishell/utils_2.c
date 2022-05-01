/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:38:10 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:38:12 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	ss;
	char	*x;

	if (!s)
		return (0);
	i = 0;
	l = 0;
	ss = ft_strlen(s);
	if (ss > start)
	{
		while (s[start + i] && i < len)
			i++;
	}
	x = malloc(i + 1);
	if (x == 0)
		return (0);
	while (l < i)
	{
		x[l] = s[start + l];
		l++;
	}
	x[l] = 0;
	return (x);
}

int	ft_strlen(const char *c)
{
	int	x;

	x = 0;
	while (c[x])
		x++;
	return (x);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write (fd, &c, 1);
}

void	ft_bzero(void *b, size_t len)
{
	size_t	i;
	char	*d;

	i = 0;
	d = (char *) b;
	while (i < len)
	{
		d[i] = 0;
		i++;
	}
}
