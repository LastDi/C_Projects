/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:46:45 by oalvera           #+#    #+#             */
/*   Updated: 2021/12/07 15:46:50 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_create_line(char *save_str)
{
	char	*new_line;
	int		len;
	int		i;

	if (!*save_str)
		return (NULL);
	len = 0;
	while (save_str[len] != '\n' && save_str[len] != '\0')
		len++;
	new_line = (char *)malloc(sizeof(char) * (len + 2));
	if (!new_line)
		return (NULL);
	i = 0;
	while (save_str[i] != '\n' && save_str[i] != '\0')
	{
		new_line[i] = save_str[i];
		i++;
	}
	if (save_str[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_del_line_from_save(char *save_str)
{
	char	*new_str;
	int		len;
	int		i;

	len = 0;
	while (save_str[len] != '\n' && save_str[len] != '\0')
		len++;
	if (!save_str[len])
	{
		free(save_str);
		return (NULL);
	}
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(save_str) - len + 1));
	i = 0;
	len++;
	while (save_str[len] != '\0')
		new_str[i++] = save_str[len++];
	new_str[i] = '\0';
	free(save_str);
	return (new_str);
}

char	*ft_read(int fd, char *save_str)
{
	char	*buf;
	int		read_bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_check_nl(save_str))
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buf[read_bytes] = '\0';
		save_str = ft_strjoin(save_str, buf);
	}
	free(buf);
	return (save_str);
}

int	ft_check_nl(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (1);
			str++;
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*save_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save_str = ft_read(fd, save_str);
	if (!save_str)
		return (NULL);
	line = ft_create_line(save_str);
	save_str = ft_del_line_from_save(save_str);
	return (line);
}
