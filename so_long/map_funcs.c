/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:38:32 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/18 22:21:33 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collect_coins(char **map, int len, t_p *s)
{
	int	y;
	int	x;
	int	len_str;

	x = 0;
	s->c = 0;
	len_str = ft_strlen(map[0]);
	while (++x < len)
	{
		y = -1;
		while (++y < len_str)
		{
			if (map[x][y] == 'C')
				s->c++;
		}
	}
	if (s->c == 0)
		free_map(s->map, len, "Wrong map");
	s->x_max = len + 1;
	s->y_max = len_str;
}

void	find_player_position(char **map, int len, t_p *s)
{
	int	y;
	int	x;
	int	len_str;
	int	c;

	x = 0;
	c = 0;
	len_str = ft_strlen(map[0]);
	while (++x < len)
	{
		y = -1;
		while (++y < len_str)
		{
			if (map[x][y] == 'P')
			{
				s->pos_s_x = y;
				s->pos_s_y = x;
				c++;
			}
		}
	}
	if (c != 1)
		free_map(s->map, len, "Wrong map");
	count_collect_coins(map, len, s);
}

void	map_content_validation(char **map, int len, t_p *s)
{
	int	i;
	int	c;
	int	e;
	int	p;

	c = 0;
	e = 0;
	p = 0;
	i = 0;
	while (i < len)
	{
		if (ft_strrchr(map[i], 'C') != NULL)
			c = 1;
		if (ft_strrchr(map[i], 'E') != NULL)
			e = 1;
		if (ft_strrchr(map[i], 'P') != NULL)
			p++;
		i++;
	}
	if (!p || !c || !e || p > 1)
		free_map(map, len, "Wrong map");
	find_player_position(map, len, s);
}

char	**map_border_validation(char **map, int len, t_p *s)
{
	int	i;
	int	len_str;
	int	y;

	len_str = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) != len_str || (map[i][0] != '1'
			|| map[i][len_str - 1] != '1'))
			len = -1;
	}
	i--;
	y = -1;
	while (map[0][++y])
	{
		if (map[0][y] != '1' || map[i][y] != '1')
			len = -1;
	}
	if (len == -1)
		free_map(map, i, "Wrong map");
	map_content_validation(map, i, s);
	return (map);
}

char	**create_init_map(char *file, t_p *s, int len)
{
	char	**map;
	char	*line;
	char	buf[2];
	int		fd;

	map = NULL;
	line = NULL;
	len = ft_strlen(file);
	if (len < 5 || file[len - 1] != 'r' || file[len - 2] != 'e'
		|| file[len - 3] != 'b' || file[len - 4] != '.')
		exit_with_msg("Wrong extension");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_with_msg("No such file or directory");
	len = 0;
	buf[1] = '\0';
	while (read(fd, buf, 1) > 0)
		line = ft_strjoin(line, buf);
	close(fd);
	map = ft_split(line, '\n');
	free(line);
	map_border_validation(map, len, s);
	return (map);
}
