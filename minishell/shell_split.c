/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:37:06 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:37:07 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_words(char const*s, char c, t_shell *shell)
{
	int		i;
	char	pre;
	int		count;

	pre = c;
	shell->preflag = 1;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (((s[i] != c) || (s[i] == c && !shell->flags[i])) \
		&& pre == c && shell->preflag)
			count++;
		pre = s[i];
		shell->preflag = shell->flags[i];
		i++;
	}
	shell->preflag = 1;
	return (count);
}

static int	counter_chars(char const *s, char c, t_shell *shell)
{
	int	i;

	i = 0;
	while ((s[i] != c && s[i]) || (s[i] == c && \
	!shell->flags[shell->tmp_split2 + i]))
		i++;
	return (i);
}

static int	write_word(const char *s, char **x, int l, t_shell *shell)
{
	int	h;
	int	count;

	count = counter_chars (s, shell->tmp_split, shell);
	x[l] = (char *)malloc(count + 1);
	if (x[l] == 0)
		ft_freesplit_2 (x);
	if (x[l] == 0)
		return (0);
	h = 0;
	while ((s[h] && s[h] != shell->tmp_split) || (s[h] == \
	shell->tmp_split && !shell->flags[shell->tmp_split2 + h]))
	{
		x[l][h] = s[h];
		h++;
	}
	if (shell->tmp_split_on_off)
	{
		shell->start_flag_prog[shell->tmp_split_p] = shell->tmp_split2;
		shell->count_flag_prog[shell->tmp_split_p] = h;
		shell->tmp_split_p++;
	}
	x[l][h] = 0;
	l++;
	return (l);
}

char	**ft_split_shell(char const *s, char c, int i, t_shell *shell)
{
	int		count;
	int		l;
	char	**x;
	char	pre;

	pre = c;
	l = 0;
	if (!s)
		return (0);
	count = count_words(s, c, shell);
	set_count(count, shell, c);
	x = (char **) malloc(sizeof (char *) * (count + 1));
	if (!x)
		return (0);
	x[count] = 0;
	while (s[++i])
	{
		tmp_write(shell, c, i);
		if (((s[i] != c) || (s[i] != c && !shell->flags[i])) \
		&& pre == c && shell->preflag)
			l = write_word(s + i, x, l, shell);
		shell->preflag = shell->flags[i];
		pre = s[i];
	}
	return (x);
}
