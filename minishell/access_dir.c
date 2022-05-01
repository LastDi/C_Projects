/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:28:44 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:28:48 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*make_name_after_slash(char *str)
{
	int		i;
	int		c_s;
	char	*new;

	i = 0;
	c_s = 0;
	if (str[i] == '.')
		return (str);
	while (str[i])
	{
		if (str[i] == '/')
			c_s = i;
		i++;
	}
	new = malloc(1000);
	i = 0;
	while (str[c_s])
	{
		new[i] = str[c_s];
		i++;
		c_s++;
	}
	free(str);
	return (new);
}

char	*delete_slash_from_name(char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (str[i] == '/')
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

int	check_access_dir_help(t_com *com, DIR *dir, int iden)
{
	if (access(com->name, 1) == 0 && iden == 0)
	{
		if (com->name[ft_strlen(com->name) - 1] == '/')
			return (ft_exec_errors(com->flags[0], ": Not a directory\n"));
		com->name = make_name_after_slash(com->name);
		com->flags[0] = make_name_after_slash(com->flags[0]);
		return (1);
	}
	else if (dir)
	{
		ft_exec_errors(com->flags[0], ": is a directory\n");
		closedir(dir);
	}
	else
		ft_exec_errors(com->flags[0], ": Not a directory\n");
	return (2);
}

int	directory_access(t_com *com)
{
	int		iden;
	int		ch;
	DIR		*dir;

	if (com->name[ft_strlen(com->name) - 1] == '/' && com->name[1] != '\0')
	{
		iden = 1;
		com->name = delete_slash_from_name(com->name);
		com->flags[0] = delete_slash_from_name(com->flags[0]);
	}
	else
		iden = 0;
	dir = opendir(com->name);
	if (dir)
		iden = 1;
	if (access(com->name, 0) == 0)
	{
		ch = check_access_dir_help(com, dir, iden);
		if (ch != 2)
			return (ch);
	}
	else
		return (ft_exec_errors(com->flags[0], ": No such file or directory\n"));
	return (0);
}
