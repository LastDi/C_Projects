/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:38:32 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/12 12:38:35 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *filename)
{
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	free_func(char **pathvar)
{
	char	**tmp;

	tmp = pathvar;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(pathvar);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*tmp;
	char	*strdup;

	len = 0;
	tmp = src;
	while (*tmp++)
		len++;
	strdup = malloc((len + 1) * sizeof(char));
	tmp = strdup;
	if (strdup != NULL)
	{
		while (*src)
			*tmp++ = *src++;
		*tmp = '\0';
	}
	return (strdup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	char	*result;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	res = malloc((length + 1) * sizeof(char));
	if (!res)
		return (NULL);
	result = res;
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = '\0';
	return (result);
}
