/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:34:44 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:34:45 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_env_lst(char **ev)
{
	t_list	*evl;
	int		i;

	i = 0;
	evl = NULL;
	while (ev[i])
	{
		ft_lstadd_front(&evl, ft_lstnew(ft_strdup(ev[i])));
		i++;
	}
	return (evl);
}

void	init_params(int argc, char **argv, char **env, t_shell *shell)
{
	(void)argc;
	(void)argv;
	signal(SIGINT, handler_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	shell->env = env;
	shell->error = 0;
	shell->longs = 4096;
	shell->flags_count = -1;
	shell->cycle = 0;
	shell->error_code = 0;
	shell->flags = NULL;
	shell->flags_for_prog = NULL;
	shell->start_flag_prog = NULL;
	shell->count_flag_prog = NULL;
	shell->pipes = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_shell	shell;
	t_com	com;
	t_list	*evl;

	init_params(argc, argv, envp, &shell);
	evl = get_env_lst(envp);
	while (1)
	{
		minishell(&shell, &com, &evl);
		i = 0;
		while (i < shell.func_count && shell.free)
		{
			free(shell.flags_for_prog[i]);
			i++;
		}
	}
}
