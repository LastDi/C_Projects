/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:34:00 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:34:02 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_checker(char *str, t_shell *shell)
{
	int	i;
	int	e;

	i = 0;
	e = 1;
	while (str[i])
	{
		if ((str[i] == ';' || str[i] == '|') && shell->flags[i])
		{
			if (e == 1)
			{
				printf("syntax error near unexpected token `%c'\n", str[i]);
				return (1);
			}
			e = 1;
		}
		else if (str[i] != ' ')
			e = 0;
		i++;
	}
	return (0);
}
