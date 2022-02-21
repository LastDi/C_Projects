/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:38:32 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/12 12:38:35 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_access(char *command, char *path)
{
	path = ft_strjoin(path, "/");
	if (path == 0)
		exit(2);
	command = ft_strjoin(path, command);
	if (command == 0)
		exit(2);
	free(path);
	if (access(command, X_OK) == 0)
		return (command);
	free(command);
	return (0);
}

void	print_error_errno(char *command, int err)
{
	if (err != 2)
		ft_putstr_fd(strerror(err), 2);
	else
		ft_putstr_fd("command not found", 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

char	*find_path_in_pathvar(char *command, char **pathvar, int *err)
{
	char	*path;

	while (*pathvar)
	{
		path = check_access(command, *(pathvar++));
		if (errno != 2)
			*err = errno;
		if (path)
			return (path);
	}
	return (0);
}

char	*check_root(char *command)
{
	char	*path;

	if (access(command, X_OK) == 0)
	{
		path = ft_strdup(command);
		if (path == 0)
			exit(2);
		return (path);
	}
	else
	{
		print_error_errno(command, errno);
		return (0);
	}
}

char	*find_path(char *command, char **envp)
{
	char	*path;
	char	**pathvar;
	int		err;

	if (command[0] == '/')
		return (check_root(command));
	path = 0;
	if (get_variable("PWD=", envp))
	{
		path = check_access(command, get_variable("PWD=", envp));
		err = errno;
		if (path != 0)
			return (path);
	}
	if (get_variable("PATH=", envp))
	{
		pathvar = ft_split(get_variable("PATH=", envp), ':');
		if (pathvar == 0)
			exit(2);
		path = find_path_in_pathvar(command, pathvar, &err);
		free_func(pathvar);
	}
	if (path == 0)
		print_error_errno(command, err);
	return (path);
}
