/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:41:55 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:41:57 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_com_list(t_com *com)
{
	t_com	*l1;
	int		i;
	int		auf;

	auf = 0;
	while (com)
	{
		free(com->name);
		i = -1;
		while (com->flags[++i])
			free(com->flags[i]);
		free(com->flags);
		if (com->fd_in != -1)
			close(com->fd_in);
		if (com->fd_out != -1)
			close(com->fd_out);
		l1 = com;
		com = com->next;
		if (auf != 0)
			free(l1);
		auf++;
	}
	return (0);
}

void	free_split_str(char **str, int j)
{
	int	i;

	i = -1;
	while (++i < j)
		free(str[i]);
	free(str);
}
