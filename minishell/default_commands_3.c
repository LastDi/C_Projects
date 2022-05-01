/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_commands_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:31:53 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:31:55 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export_unset_help(char *arg, t_list **evl)
{
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;
	char	*help[100];

	l1 = *evl;
	while (l1 && l1->next)
	{
		l2 = l1->next;
		l3 = l2->next;
		help[1] = (char *)(l1->content);
		help[2] = (char *)(l2->content);
		if (export_unset_help_1(arg, evl, help[1], l1) == 1)
			return (export_unset1(arg, &l1, &l2, evl));
		else if (export_unset_help_2(arg, help[2]) == 1)
			return (export_unset2(arg, &l1, &l3, &l2));
		l1 = l1->next;
	}
	return (0);
}

int	export_unset(char *arg, t_list **evl)
{
	t_list	*l1;
	char	*help;

	l1 = *evl;
	if (l1 && !l1->next)
	{
		help = (char *)(l1->content);
		if (ft_strncmp(help, arg, ft_strlen_sym(help, '=')) == 0
			&& (arg[ft_strlen_sym(help, '=')] == '\0'
				|| arg[ft_strlen_sym(help, '=')] == '='))
		{
			if (!ft_strchr(arg, '='))
				return (1);
			*evl = NULL;
			free(l1);
		}
	}
	else
		return (export_unset_help(arg, evl));
	return (0);
}

void	print_simple_export(char *str)
{
	int	i;

	i = 0;
	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	while (str[i] && str[i] != '=')
	{
		ft_putchar_fd(str[i], STDOUT_FILENO);
		i++;
	}
	if (!str[i])
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		return ;
	}
	ft_putchar_fd('=', STDOUT_FILENO);
	ft_putchar_fd('"', STDOUT_FILENO);
	while (str[++i] && str[i] != '=')
		ft_putchar_fd(str[i], STDOUT_FILENO);
	ft_putchar_fd('"', STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	export_print_sim(t_list **evl)
{
	t_list	*l1;
	char	*help;

	l1 = *evl;
	while (l1)
	{
		help = (char *)(l1->content);
		if (help[0] == '_' && help[1] == '=')
			ft_putstr_fd("", 1);
		else
			print_simple_export(help);
		l1 = l1->next;
	}
}

int	ft_export(t_com *com, t_list **evl)
{
	int		i;

	ft_sort_easy(evl);
	if (!com->flags[1])
		export_print_sim(evl);
	else
	{
		i = 1;
		while (com->flags[i])
		{
			if (com->flags[i] && parsing_export(com->flags[i]))
			{
				if (export_unset(com->flags[i], evl) == 0)
					ft_lstadd_back(evl, ft_lstnew(ft_strdup(com->flags[i])));
			}
			else
				return (1);
			i++;
		}
	}
	return (0);
}
