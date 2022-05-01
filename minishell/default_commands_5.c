/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_commands_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:32:16 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:32:18 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit_error(t_com *com, t_list **evl)
{
	int	i;

	i = 0;
	while (com->flags[1][i])
	{
		if (!ft_isdigit(com->flags[1][i]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(com->flags[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			ft_lstclear(evl, free);
			free_com_list(com);
			exit(1);
		}
		i++;
	}
}

int	ft_exit(t_com *com, t_list **evl)
{
	if (!com->flags[1])
	{
		ft_lstclear(evl, free);
		free_com_list(com);
		exit(0);
	}
	else
	{
		if (com->flags[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments", 2);
			return (1);
		}
		else
		{
			ft_exit_error(com, evl);
			ft_lstclear(evl, free);
			exit(ft_atoi(com->flags[1]));
		}
	}
}
