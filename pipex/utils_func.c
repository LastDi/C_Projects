/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:38:32 by oalvera           #+#    #+#             */
/*   Updated: 2022/02/12 12:38:35 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	not_blank(char *s)
{
	while (*s)
	{
		if (*s != ' ')
			return (1);
		s++;
	}
	return (0);
}

void	create_pipe(int fds[2])
{
	int	status;

	status = pipe(fds);
	if (status == -1)
		exit(3);
}

int	str_start_with(char *str, char *start_str)
{
	int	i;

	i = 0;
	while (start_str[i])
	{
		if (str[i] != start_str[i])
			return (0);
		i++;
	}
	return (1);
}

char	*get_variable(char *var, char **envp)
{
	while (*envp)
	{
		if (str_start_with(*envp, var))
			return (*envp + ft_strlen(var));
		envp++;
	}
	return (0);
}
