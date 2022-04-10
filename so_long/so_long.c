/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:38:32 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/18 22:21:33 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_on_map(t_p *s, int x, int y)
{
	if (s->map[x][y] == '0')
		mlx_put_image_to_window(s->mlx, s->window, s->i_obstacle, y * 50,
			x * 50);
	else if (s->map[x][y] == '1')
		mlx_put_image_to_window(s->mlx, s->window, s->i_wall,
			y * 50, x * 50);
	else if (s->map[x][y] == 'C')
		mlx_put_image_to_window(s->mlx, s->window, s->i_collect,
			y * 50, x * 50);
	else if (s->map[x][y] == 'P')
		mlx_put_image_to_window(s->mlx, s->window, s->i_pos,
			y * 50, x * 50);
	else
		mlx_put_image_to_window(s->mlx, s->window, s->i_exit,
			y * 50, x * 50);
}

void	put_img_to_wdw(t_p *s)
{
	int	x;
	int	y;

	x = 0;
	while (x < s->x_max)
	{
		y = -1;
		while (++y <= s->y_max)
			put_on_map(s, x, y);
		x++;
	}
}

void	initialization(t_p *s)
{
	s->mlx = mlx_init();
	if (!s->mlx)
		free_map(s->map, s->x_max, "Wrong initialization");
	s->window = mlx_new_window(s->mlx, 50 * s->y_max,
			50 * s->x_max, "So long");
	s->i_obstacle = mlx_xpm_file_to_image(s->mlx, OBSTACLE,
			&s->img_size, &s->img_size);
	s->i_wall = mlx_xpm_file_to_image(s->mlx, WALL,
			&s->img_size, &s->img_size);
	s->i_collect = mlx_xpm_file_to_image(s->mlx, COIN,
			&s->img_size, &s->img_size);
	s->i_exit = mlx_xpm_file_to_image(s->mlx, EXIT,
			&s->img_size, &s->img_size);
	s->i_pos = mlx_xpm_file_to_image(s->mlx, PLAYER,
			&s->img_size, &s->img_size);
	s->move_counter = 0;
	put_img_to_wdw(s);
}

int	main(int argc, char **argv)
{
	t_p	s;

	if (argc != 2)
		exit_with_msg("Wrong number of argument!");
	s.map = create_init_map(argv[1], &s, 0);
	initialization(&s);
	mlx_key_hook(s.window, key_hook, &s);
	mlx_hook(s.window, 0, 1, key_hook, &s);
	mlx_loop(s.mlx);
	return (0);
}
