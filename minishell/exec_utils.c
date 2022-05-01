/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:34:32 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:34:34 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_duplicate_fd(t_com *com)
{
	if (com->fd_in != -1)
		dup2(com->fd_in, STDIN_FILENO);
	if (com->fd_out != -1)
		dup2(com->fd_out, STDOUT_FILENO);
}

int	ft_exec_errors(char *s1, char *s2)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	return (0);
}
