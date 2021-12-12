/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:53:01 by oalvera           #+#    #+#             */
/*   Updated: 2021/12/07 15:53:23 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strjoin(char *save_str, char *buf)
{
	char	*join_str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!save_str)
	{
		save_str = malloc(sizeof(char) * 1);
		if (!save_str)
			return (NULL);
		save_str[0] = '\0';
	}
	join_str = malloc((ft_strlen(save_str) + ft_strlen(buf) + 2));
	if (!join_str || !buf)
		return (NULL);
	while (save_str[++i])
		join_str[i] = save_str[i];
	while (buf[j])
		join_str[i++] = buf[j++];
	join_str[i] = '\0';
	free(save_str);
	return (join_str);
}
