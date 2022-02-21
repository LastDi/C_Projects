/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:38:32 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/12 12:38:35 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	command_exec(char *command, char **envp)
{
	char	**cmd_args;
	char	*path;
	char	buf;

	if (not_blank(command))
	{
		cmd_args = ft_split(command, ' ');
		if (cmd_args == 0)
			exit(2);
		path = find_path(cmd_args[0], envp);
		if (!path)
			exit(1);
		free(cmd_args[0]);
		cmd_args[0] = path;
		execve(path, cmd_args, envp);
	}
	else
	{
		while (read(0, &buf, 1))
			write(1, &buf, 1);
		close(1);
	}
}

void	wait_pid(int pid, int *status, char *cmd)
{
	waitpid(pid, status, 0);
	if (!WIFEXITED(*status))
	{
		ft_putnbr_fd(pid, 2);
		ft_putstr_fd(" ERROR", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd("\n", 2);
	}
}

void	open_dup(int dp_1, int dp_2, int cls_1, int cls_2)
{
	if (dup2(dp_1, 0) == -1)
		exit(3);
	if (dup2(dp_2, 1) == -1)
		exit(3);
	close(cls_1);
	close(cls_2);
}

void	pipex(int fd_in, int fd_out, char **cmd, char **envp)
{
	int		pids[2];
	int		status;

	create_pipe(pids);
	if (fork() == 0)
	{
		open_dup(fd_in, pids[1], fd_out, pids[0]);
		command_exec(cmd[0], envp);
	}
	else
	{
		wait_pid(1, &status, cmd[0]);
		close(pids[1]);
		if (fork() == 0)
		{
			open_dup(pids[0], fd_out, fd_in, pids[1]);
			command_exec(cmd[1], envp);
		}
		else
			wait_pid(1, &status, cmd[1]);
	}
	close(pids[0]);
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd[2];
	int		fd[2];

	if (argc != 5)
	{
		ft_putstr_fd("Pipex works with 4 arguments", 2);
		exit(1);
	}
	cmd[0] = argv[2];
	cmd[1] = argv[3];
	fd[0] = open(argv[1], O_RDONLY, 0);
	if (fd[0] < 0)
		print_error(argv[1]);
	fd[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd[1] < 0)
		print_error(argv[4]);
	pipex(fd[0], fd[1], cmd, envp);
}
