/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:38:32 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/12 12:38:35 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(char const *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	print_error(char *filename);
void	free_func(char **pathvar);
void	create_pipe(int fds[2]);
char	**ft_split(char const *s, char c);
int		not_blank(char *s);
char	*find_path(char *command, char **envp);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_variable(char *var, char **envp);

#endif
