/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 02:00:17 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/21 23:04:15 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char *str, char c)
{
	int	count;

	count = 0;
	while (*str == c)
		str++;
	while (*str)
	{
		if (*str == c)
		{
			while (*str == c)
				str++;
		}
		else
		{
			while (*str != c && *str != '\0')
				str++;
			count++;
		}
	}
	return (count);
}

static size_t	ft_delim_len(char *str, char c)
{
	size_t	delim_len;

	delim_len = 0;
	while (*str == c)
	{
		str++;
		delim_len++;
	}
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str == c)
			return (delim_len);
		delim_len++;
		str++;
	}
	return (delim_len);
}

static char	*ft_make_word(char *src, char c)
{
	char	*tmp;
	char	*strdup;
	int		length;

	length = 0;
	while (*src == c)
		src++;
	tmp = src;
	while (*tmp != c && *tmp != '\0')
	{
		length++;
		tmp++;
	}
	strdup = malloc((length + 1) * sizeof(char));
	tmp = strdup;
	if (strdup != NULL)
	{
		while (length-- != 0)
			*tmp++ = *src++;
		*tmp = '\0';
	}
	return (strdup);
}

static char	**ft_free_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	delim_len;
	int		count_word;
	char	**array;
	int		i;

	if (!s)
		return (NULL);
	count_word = ft_count((char *) s, c);
	array = malloc((count_word + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (*s && count_word-- != 0)
	{
		delim_len = ft_delim_len((char *) s, c);
		array[i] = ft_make_word((char *) s, c);
		if (array[i] == NULL)
			return (ft_free_arr(array));
		s = s + delim_len;
		i++;
	}
	array[i] = NULL;
	return (array);
}
