/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:37:27 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:37:29 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tmp_write(t_shell *shell, char c, int i)
{
	shell->tmp_split = c;
	shell->tmp_split2 = i;
}

void	set_count(int count, t_shell *shell, char c)
{
	if (c == ';')
		shell->func_count = count;
	if (c == '|')
	{
		shell->pipe_count = count;
		if (count > shell->pipe_count_max)
			shell->pipe_count_max = count;
	}
}

void	ft_freesplit_2(char **x)
{
	int	i;

	i = 0;
	printf("malloc error\n");
	while (x[i])
		free(x[i++]);
	free(x);
}
