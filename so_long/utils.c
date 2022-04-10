/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:38:32 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/18 22:21:33 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_with_msg(char *msg)
{
	if (msg != 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(1);
}

void	free_map(char **map, int len, char *s)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(map[i]);
		i++;
	}
	free(map);
	exit_with_msg(s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sum_s;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[i] = '\0';
	}
	sum_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!sum_s || !s2)
		return (NULL);
	while (s1[c])
		sum_s[i++] = s1[c++];
	c = 0;
	while (s2[c])
		sum_s[i++] = s2[c++];
	sum_s[i] = '\0';
	free(s1);
	return (sum_s);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *) s) + 1;
	while (i--)
	{
		if (*(s + i) == c)
			return ((char *)(s + i));
	}
	return (NULL);
}
