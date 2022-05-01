/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:38:05 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:38:06 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nlist;

	nlist = malloc(sizeof(t_list));
	if (nlist == 0)
		return (0);
	nlist->content = content;
	nlist->next = 0;
	return (nlist);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (s1[i] == 0 || s2[i] == 0)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	while (s1[i] && s2[i] && n > i)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (n > i)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		l;
	char	*x;

	i = 0;
	l = 0;
	while (s1[i])
		i++;
	x = malloc(i + 1);
	x[i] = 0;
	if (x != 0)
	{
		while (l < i)
		{
			x[l] = s1[l];
			l++;
		}
	}
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i[3];
	char	*x;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!s1 || !s2)
		return (0);
	i[1] = ft_strlen(s1);
	i[2] = ft_strlen(s2);
	x = malloc(i[1] + i[2] + 2);
	if (x == 0)
		return (0);
	while (i[0] <= i[1])
	{
		x[i[0]] = s1[i[0]];
		i[0]++;
	}
	i[0] = -1;
	while (++i[0] <= i[2])
		x[i[1] + i[0]] = s2[i[0]];
	x[i[1] + i[0]] = 0;
	return (x);
}
