/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:32:50 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/20 06:07:11 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char *str, char *set)
{
	while (*set)
	{
		if (*str == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	res;
	size_t	len;
	char	*str;

	begin = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	str = (char *) s1;
	while (ft_check_set(str, (char *) set) && *str++)
		begin++;
	if (begin == len || len == 0)
		return (ft_strdup(""));
	res = len - begin - 1;
	while (ft_check_set((str + res), (char *) set))
		res--;
	return (ft_substr(str, 0, res + 1));
}
