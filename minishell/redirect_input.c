/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:36:42 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:36:43 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_redirect_input_two(t_shell *shell)
{
	char	*str;
	char	*str1;
	char	*str2;
	char	*str3;
	int		j;

	if (shell->pipes[shell->i].fd_in != -1)
		close(shell->pipes[shell->i].fd_in);
	if (fd_file_not_exist(shell->str[shell->i], shell->j, 2))
		return (1);
	str = ft_find_file_name(shell->str[shell->i] + shell->j + 2, shell, 0);
	if (!str)
		return (1);
	j = ft_strlen(str);
	read_for_redirect(shell, str, j, 1);
	str1 = ft_substr(shell->str[shell->i], 0, shell->j);
	str2 = ft_strdup(shell->str[shell->i] + shell->n + 2);
	str3 = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	free(shell->str[shell->i]);
	shell->str[shell->i] = str3;
	return (0);
}

int	fd_redirect_input_one(t_shell *shell)
{
	char	*str;
	char	*str1;
	char	*str2;

	if (shell->pipes[shell->i].fd_in != -1)
		close(shell->pipes[shell->i].fd_in);
	if (fd_file_not_exist(shell->str[shell->i], shell->j, 1))
		return (1);
	str = ft_find_file_name(shell->str[shell->i] + shell->j + 1, shell, 0);
	if (!str)
		return (1);
	shell->pipes[shell->i].fd_in = open(str, O_RDONLY, 0777);
	if (shell->pipes[shell->i].fd_in < 0)
	{
		printf("No such file or directory\n");
		return (1);
	}
	str1 = ft_substr(shell->str[shell->i], 0, shell->j);
	str2 = ft_strdup(shell->str[shell->i] + shell->n + 1);
	free(shell->str[shell->i]);
	shell->str[shell->i] = ft_strjoin(str1, str2);
	free(str);
	free(str1);
	free(str2);
	return (0);
}

int	fd_redirect_input(t_shell *shell)
{
	int	i;
	int	j;

	i = 0;
	while (i < shell->pipe_count)
	{
		shell->pipes[i].fd_in = -1;
		j = 0;
		while (shell->str[i][j])
		{
			shell->i = i;
			shell->j = j;
			if (shell->str[i][j] == '<' && shell->str[i][j + 1] && \
			shell->str[i][j + 1] == '<' && fd_redirect_input_two(shell))
				return (1);
			else if (shell->str[i][j] == '<' && fd_redirect_input_one(shell))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
