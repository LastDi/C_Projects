/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:36:52 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:36:53 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_file_not_exist(char *str, int j, int n)
{
	if (!str[j + n])
	{
		printf("syntax error near unexpected token newline\n");
		return (1);
	}
	return (0);
}

int	gnl_light(char **str)
{
	char	s[4096];
	char	r;
	int		i;
	int		x;

	i = 0;
	x = 1;
	ft_bzero(s, 4096);
	while (x > 0)
	{
		x = read(0, &r, 1);
		if (x > 0 && r != '\n')
			s[i] = r;
		if (x > 0 && r == '\n')
		{
			*str = s;
			return (1);
		}
		i++;
	}
	*str = s;
	return (0);
}

int	read_for_redirect(t_shell *shell, char *str, int j, int x)
{
	int		l;
	int		y;
	int		pipefd[2];
	char	*gnl;

	if (pipe(pipefd) == -1)
		printf ("pipe error\n");
	if (pipe(pipefd) == -1)
		return (1);
	while (x)
	{
		l = 0;
		y = gnl_light(&gnl);
		write(pipefd[1], gnl, ft_strlen(gnl));
		write(pipefd[1], &"\n", 1);
		l = ft_strlen(gnl);
		if (j > l)
			l = j;
		if (!ft_strncmp(gnl, str, l))
			x = 0;
	}
	close(pipefd[1]);
	shell->pipes[shell->i].fd_in = pipefd[0];
	return (0);
}

char	*ft_find_file_name(char *str, t_shell *shell, int l)
{
	int		i;
	int		j;
	char	*str2;

	while (str[l] == ' ')
		l++;
	i = l;
	j = 0;
	while (str[i] && str[i++] != ' ')
		j++;
	shell->n = i + shell->j;
	str2 = malloc(j + 1);
	if (!str2)
		printf("malloc error\n");
	if (!str2)
		return (NULL);
	ft_bzero(str2, (j + 1));
	i = l;
	l = 0;
	while (str[i] && str[i] != ' ')
		str2[l++] = str[i++];
	return (str2);
}
