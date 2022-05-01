/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_command_utils_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:29:05 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:29:08 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_arg_unset(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	unset_help1(t_com *com, int i)
{
	ft_putstr_fd("minishell: unset: `", 2);
	ft_putstr_fd(com->flags[i], 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

void	env_help(char *help)
{
	if (help[0] == '_' && help[1] == '=')
	{
		ft_putstr_fd("_=/usr/bin/env", STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	else
	{
		ft_putstr_fd(help, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}

int	sort_count(t_list **evl)
{
	int		i;
	t_list	*l1;

	i = -2;
	l1 = *evl;
	while (l1)
	{
		l1 = l1->next;
		i++;
	}
	return (i);
}

int	who_is_more(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}
