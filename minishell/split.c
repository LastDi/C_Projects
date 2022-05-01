/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:37:55 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:37:56 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_freesplit(char **x)
{
	int	i;

	i = 0;
	while (x[i])
		free(x[i++]);
	free(x);
}

int	ft_splitcounterword(char const*s, char c)
{
	int		i;
	char	pre;
	int		count;

	pre = c;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && pre == c)
			count++;
		pre = s[i];
		i++;
	}
	return (count);
}

int	ft_splitcounterchar(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

int	ft_splitwriterword(const char *s, char **x, int l, char c)
{
	int	h;
	int	count;

	count = ft_splitcounterchar (s, c);
	x[l] = (char *)malloc(count + 1);
	if (x[l] == 0)
	{
		ft_freesplit (x);
		return (0);
	}
	h = 0;
	while (s[h] && s[h] != c)
	{
		x[l][h] = s[h];
		h++;
	}
	x[l][h] = 0;
	l++;
	return (l);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	int		l;
	char	**x;
	char	pre;

	pre = c;
	i = 0;
	l = 0;
	if (!s)
		return (0);
	count = ft_splitcounterword(s, c);
	x = (char **) malloc(sizeof (char *) * (count + 1));
	if (!x)
		return (0);
	x[count] = 0;
	while (s[i])
	{
		if (s[i] != c && pre == c)
			l = ft_splitwriterword(s + i, x, l, c);
		pre = s[i];
		i++;
	}
	return (x);
}
