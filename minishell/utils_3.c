/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:38:16 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:38:17 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	r;
	int	ccpy;

	i = 0;
	r = 0;
	ccpy = (char) c;
	while (s[r])
		r++;
	while (i <= r)
	{
		if (s[i] == ccpy)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

int	ft_lstcount(t_com **com)
{
	t_com	*l;
	int		i;

	l = *com;
	i = 0;
	while (l)
	{
		i++;
		l = l->next;
	}
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	z;

	i = 0;
	z = 0;
	if (needle[0] == 0)
		return ((char *)(haystack));
	while (needle[z])
		z++;
	while (haystack[i] && i < len)
	{
		l = 0;
		while (haystack[i + l] == needle[l] && haystack[i + l] && i + l < len)
		{
			l++;
			if (l == z)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}

t_com	*ft_lstgive(t_com **com, int i)
{
	t_com	*l;

	l = *com;
	while (i > 0)
	{
		l = l->next;
		i--;
	}
	return (l);
}

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
