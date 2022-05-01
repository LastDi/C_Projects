/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:35:35 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:35:36 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parser_dollar(char *str, int *i, t_shell *shell)
{
	int		j;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	j = *i;
	*i = *i + 1;
	while (str[*i] == '_' || (str[*i] >= 65 && str[*i] <= 90) || (str[*i] >= 97 \
	&& str[*i] <= 122) || (str[*i] >= 48 && str[*i] <= 57) || str[*i] == '?')
		*i += 1;
	str1 = ft_substr(str, j + 1, *i - j - 1);
	str2 = find_key(shell, str1);
	free(str1);
	str1 = ft_substr(str, 0, j);
	str3 = ft_strdup(str + *i);
	str4 = ft_strjoin(str1, str2);
	multiple_free(str1, str2, NULL, NULL);
	str1 = ft_strjoin(str4, str3);
	multiple_free(str, str3, str4, NULL);
	*i = j + shell->lenght;
	return (str1);
}

char	*parser_slash(char *str, int *i)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = ft_substr(str, 0, *i);
	str2 = ft_strdup(str + *i + 1);
	str3 = ft_strjoin(str1, str2);
	multiple_free(str, str1, str2, NULL);
	*i += 1;
	return (str3);
}

char	*parser_dub_quotes(char *str, int *i, t_shell *shell, int limiter)
{
	char	*str1;
	char	*str2;
	char	*str3;

	shell->tmp_split2 = *i;
	while (str[++*i] && limiter)
	{
		if (str[*i] == '\"')
			limiter = 0;
		if (str[*i] == '\\' && str[*i + 1] \
		&& (str[*i + 1] == '\\' || str[*i + 1] == '\"' \
		|| str[*i + 1] == '$'))
			str = parser_slash(str, i);
		if (str[*i] == '$')
			str = parser_dollar(str, i, shell);
	}
	str1 = ft_substr(str, 0, shell->tmp_split2);
	str2 = ft_substr(str, shell->tmp_split2 + 1, *i - shell->tmp_split2 - 2);
	str3 = ft_strjoin(str1, str2);
	multiple_free(str1, str2, NULL, NULL);
	str1 = ft_strdup(str + *i);
	str2 = ft_strjoin(str3, str1);
	multiple_free(str, str1, str3, NULL);
	*i -= 2;
	return (str2);
}

char	*parser_quotes(char *str, int *i, int limiter)
{
	int		j;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	j = *i;
	while (str[++*i] && limiter)
	{
		if (str[*i] == '\'')
			limiter = 0;
	}
	str1 = ft_substr(str, 0, j);
	str2 = ft_substr(str, j + 1, *i - j - 2);
	str3 = ft_strdup(str + *i);
	str4 = ft_strjoin(str1, str2);
	multiple_free(str1, str2, NULL, NULL);
	str1 = ft_strjoin(str4, str3);
	multiple_free(str, str3, str4, NULL);
	*i -= 2;
	return (str1);
}

char	*parser(char *s, t_shell *shell)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] && s[i] == '\'')
			s = parser_quotes(s, &i, 1);
		if (s[i] && s[i] == '\\')
			s = parser_slash(s, &i);
		if (s[i] && s[i] == '\"')
			s = parser_dub_quotes(s, &i, shell, 1);
		if (s[i] && s[i] == '$')
			s = parser_dollar(s, &i, shell);
		if (s[i] && (s[i] == ';' || s[i] == '|' ))
			shell->flags[i] = 1;
	}
	return (s);
}
