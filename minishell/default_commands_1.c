/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_commands_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:31:41 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:31:42 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo_help(t_com *com)
{
	int	i;

	i = 3;
	ft_putstr_fd(com->flags[2], STDOUT_FILENO);
	while (com->flags[i] != NULL)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putstr_fd(com->flags[i], STDOUT_FILENO);
		i++;
	}
}

int	ft_echo(t_com *com)
{
	int	i;

	if (!com->flags[1])
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		return (0);
	}
	if (ft_strnstr(com->flags[1], "-n", ft_strlen(com->name)))
	{
		if (!com->flags[2])
			return (0);
		ft_echo_help(com);
	}
	else
	{
		i = 1;
		ft_putstr_fd(com->flags[1], STDOUT_FILENO);
		while (com->flags[++i] != NULL)
		{
			ft_putchar_fd(' ', STDOUT_FILENO);
			ft_putstr_fd(com->flags[i], STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	return (0);
}

int	ft_env(t_com *com, t_list **evl)
{
	t_list	*l;
	char	*help;

	l = *evl;
	if (com->flags[1] == NULL)
	{
		while (l)
		{
			if (ft_strchr((char *)(l->content), '='))
			{
				help = (char *)(l->content);
				env_help(help);
			}
			l = l->next;
		}
	}
	else
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(com->flags[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (127);
	}
	return (0);
}
