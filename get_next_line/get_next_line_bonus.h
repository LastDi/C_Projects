/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:51:14 by oalvera           #+#    #+#             */
/*   Updated: 2021/12/07 15:53:49 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_create_line(char *save_str);
size_t	ft_strlen(char *str);
int		ft_check_nl(char *str);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *save_str);
char	*ft_strjoin(char *save_str, char *buf);
char	*ft_del_line_from_save(char *save_str);

#endif
