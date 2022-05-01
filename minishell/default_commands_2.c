/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_commands_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:31:47 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:31:48 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	dir[500];

	getcwd(dir, 500);
	ft_putstr_fd(dir, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}

void	make_cd_pwd_help(t_list **evl, char *oldpwd)
{
	t_list	*l1;
	char	*help1;

	l1 = *evl;
	while (l1)
	{
		if (!ft_strncmp((char *)(l1->content), "OLDPWD", 6)
			&& (((char *)(l1->content))[6] == '\0'
				|| ((char *)(l1->content))[6] == '='))
		{
			help1 = ft_strjoin("OLDPWD=", oldpwd);
			l1->content = (void *)help1;
		}
		l1 = l1->next;
	}
}

int	make_cd_pwd(t_list **evl, char *oldpwd)
{
	t_list	*l1;
	char	*help;
	char	str[500];

	l1 = *evl;
	while (l1)
	{
		if (!ft_strncmp((char *)(l1->content), "PWD", 3)
			&& (((char *)(l1->content))[3] == '\0'
				|| ((char *)(l1->content))[3] == '='))
		{
			getcwd(str, 200);
			help = ft_strjoin("PWD=", str);
			l1->content = (void *)help;
		}
		l1 = l1->next;
	}
	make_cd_pwd_help(evl, oldpwd);
	return (0);
}

void	ft_cd_help(t_com *com, char *oldpwd, t_list **evl)
{
	char	*path;
	char	*path_h;

	path = malloc(500);
	getcwd(path, 500);
	path_h = ft_strjoin(path, "/");
	free(path);
	path = ft_strjoin(path_h, com->flags[1]);
	free(path_h);
	if (chdir(path) == -1)
	{
		free(path);
		path = ft_strjoin("minishell: cd: ", com->flags[1]);
		perror(path);
	}
	else
		make_cd_pwd(evl, oldpwd);
	free(path);
}

int	ft_cd(t_com *com, t_list **evl)
{
	char	*path;
	char	oldpwd[500];

	getcwd(oldpwd, 500);
	if (!com->flags[1])
		return (0);
	if (com->flags[1][0] == '/')
	{
		if (chdir(com->flags[1]) == -1)
		{
			path = ft_strjoin("minishell: cd: ", com->flags[1]);
			perror(path);
			free(path);
			return (1);
		}
		else
			make_cd_pwd(evl, oldpwd);
	}
	else
		ft_cd_help(com, oldpwd, evl);
	return (0);
}
