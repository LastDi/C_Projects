/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:37:21 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:37:22 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	name_flags_parser(t_com *com, t_shell *shell, int i)
{
	int		start;
	int		end;

	start = 0;
	while (shell->str[i][start] && shell->str[i][start] == ' ')
		start++;
	end = start;
	while (shell->str[i][end] && shell->str[i][end] != ' ')
		end++;
	com->name = ft_substr(shell ->str[i], start, end - start);
	com->flags = ft_split(shell->str[i], ' ');
	if (ft_strchr(com->name, '/'))
		com->path = com->name;
	else
		com->path = ft_strdup("NULL");
}

void	init_com(t_shell *shell, t_com *com)
{
	int		i;
	t_com	*com2;

	com->next = NULL;
	com->fd_in = shell->pipes[0].fd_in;
	com->fd_out = shell->pipes[0].fd_out;
	name_flags_parser(com, shell, 0);
	i = 1;
	while (i < shell->pipe_count)
	{
		com2 = malloc(sizeof (t_com));
		com->next = com2;
		com = com2;
		com->next = NULL;
		com->fd_in = shell->pipes[i].fd_in;
		com->fd_out = shell->pipes[i].fd_out;
		name_flags_parser(com, shell, i);
		i++;
	}
}

void	tmp_changer(t_shell *shell)
{
	shell->tmp_split_p = 0;
	shell->tmp_split_on_off = 1;
}

void	malloc_part(t_shell *shell, int i)
{
	if (i == 111)
	{
		shell->pipe_count_max = 0;
		shell->tmp_split_on_off = 0;
		shell->free = 1;
	}
	if (i == 222)
	{
		if (shell->pipes != NULL)
			free(shell->pipes);
		if (shell->flags_for_prog != NULL)
			free(shell->flags_for_prog);
		if (shell->start_flag_prog != NULL)
			free(shell->start_flag_prog);
		if (shell->count_flag_prog != NULL)
			free(shell->count_flag_prog);
		shell->pipes = malloc(sizeof(t_pipes) * shell->func_count);
		shell->flags_for_prog = malloc(sizeof(void **) * shell->func_count);
		shell->start_flag_prog = malloc(sizeof(int) * shell->func_count);
		shell->count_flag_prog = malloc(sizeof(int) * shell->func_count);
	}
}
