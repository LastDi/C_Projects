/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:35:44 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:35:45 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	multiple_free(void *s1, void *s2, void *s3, void *s4)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	if (s4)
		free(s4);
}

char	*find_key(t_shell *shell, char *str1)
{
	int		i;
	int		n;
	char	*key_line;

	n = ft_strlen(str1);
	if (n == 1 && str1[0] == '?')
		return (ft_itoa(shell->error_code));
	i = 0;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], str1, n) == 0 \
		&& shell->env[i][n] == '=')
		{
			key_line = ft_strdup(shell->env[i] + n + 1);
			shell->lenght = ft_strlen(key_line);
			return (key_line);
		}
		i++;
	}
	key_line = malloc(2);
	key_line[0] = ' ';
	key_line[1] = '\0';
	return (key_line);
}
