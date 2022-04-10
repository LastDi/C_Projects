/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:31:34 by bbayard           #+#    #+#             */
/*   Updated: 2022/02/05 13:31:36 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <mlx.h>

# define COIN "./img/c.xpm"
# define OBSTACLE "./img/0.xpm"
# define EXIT "./img/e.xpm"
# define WALL "./img/1.xpm"
# define PLAYER "./img/p.xpm"

typedef struct s_t
{
	int		pos_s_x;
	int		pos_s_y;
	int		x_max;
	int		y_max;
	char	**map;
	void	*mlx;
	void	*window;
	void	*i_obstacle;
	void	*i_wall;
	void	*i_collect;
	void	*i_exit;
	void	*i_pos;
	int		img_size;
	int		move_counter;
	int		c;
}	t_p;

char	**ft_split(char const *s, char c);
char	**create_init_map(char *file, t_p *s, int len);
char	**map_border_validation(char **map, int len, t_p *s);
void	map_content_validation(char **map, int len, t_p *s);
void	find_player_position(char **map, int len, t_p *s);
void	count_collect_coins(char **map, int len, t_p *s);
void	validate_move(t_p *s, int x, int y);
int		key_hook(int keycode, t_p *s);
int		ft_strlen(char const *str);
void	ft_putstr_fd(char *s, int fd);
void	initialization(t_p *s);
void	put_img_to_wdw(t_p *s);
void	put_on_map(t_p *s, int x, int y);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	free_map(char **map, int len, char *s);
void	exit_with_msg(char *msg);

#endif
