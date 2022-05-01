/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:34:23 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:34:24 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_choose_exec_com(t_com *com, t_list **evl)
{
	if (!ft_strncmp(com->name, "pwd", 5000000))
		return (ft_pwd());
	else if (!ft_strncmp(com->name, "echo", 5000000))
		return (ft_echo(com));
	else if (!ft_strncmp(com->name, "cd", 5000000))
		return (ft_cd(com, evl));
	else if (!ft_strncmp(com->name, "export", 5000000))
		return (ft_export(com, evl));
	else if (!ft_strncmp(com->name, "unset", 5000000))
		return (ft_unset(com, evl));
	else if (!ft_strncmp(com->name, "env", 5000000))
		return (ft_env(com, evl));
	else if (!ft_strncmp(com->name, "exit", 5000000))
		return (ft_exit(com, evl));
	return (-1);
}

int	ft_get_path_and_exec(t_com *com, char **ev, t_list *l)
{
	char	**paths;
	char	*path;
	int		j;

	j = 0;
	while (l)
	{
		if (ft_strnstr((char *)(l->content), "PATH", 4)
			&& ((char *)(l->content))[4] == '=')
			break ;
		l = l->next;
	}
	if (!l)
		return (2);
	paths = ft_split(((char *)(l->content)) + 5, ':');
	while (paths[j])
	{
		path = ft_strjoin(paths[j], "/");
		path = ft_strjoin(path, com->flags[0]);
		execve(path, com->flags, ev);
		free(path);
		j++;
	}
	return (1);
}

void	ft_exec_full_path(t_com *com, char **ev, t_list **evl)
{
	char	*path;
	t_list	*l;
	char	pwd[500];

	if (!ft_strncmp("NULL", com->path, 500000))
	{
		l = *evl;
		if (ft_get_path_and_exec(com, ev, l) == 2)
			return ;
	}
	else
	{
		if (com->path[0] == '.' && com->path[1] == '/')
		{
			getcwd(pwd, 500);
			path = ft_strjoin(pwd, com->path + 1);
			execve(path, com->flags, ev);
		}
		else
			execve(com->path, com->flags, ev);
	}
}

int	ft_exec_one_com(t_com *com, char **ev, t_list **evl)
{
	pid_t	pid;
	int		res;
	int		st;

	ft_duplicate_fd(com);
	if (ft_strchr(com->name, '/') && !directory_access(com))
		return (127);
	res = ft_choose_exec_com(com, evl);
	if (res >= 0)
		return (res);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			ft_exec_full_path(com, ev, evl);
			ft_exec_errors(com->name, ": command not found\n");
			exit(1);
		}
		waitpid(pid, &st, 0);
		if (WIFSIGNALED(st))
			write(2, "\n", 1);
	}
	return (127);
}

int	ft_exec_start(char **ev, t_com *com, t_list **evl)
{
	pid_t	pid;
	int		rez;

	rez = 0;
	if (com && com->name[0] == '\0')
		return (free_com_list(com));
	if (ft_lstcount(&com) == 1)
		rez = ft_exec_one_com(com, ev, evl);
	else if (ft_lstcount(&com) == 0)
		return (0);
	else if (ft_lstcount(&com) > 1)
	{
		pid = fork();
		if (!pid)
			ft_exec_pipe(&com, ev, evl);
		wait(0);
	}
	free_com_list(com);
	dup2(2, STDOUT_FILENO);
	dup2(1, STDOUT_FILENO);
	dup2(1, STDIN_FILENO);
	dup2(0, STDIN_FILENO);
	return (rez);
}
