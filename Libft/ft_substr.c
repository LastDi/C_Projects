/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:21:32 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/23 19:55:56 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*substr;
	char	*tmp;
	size_t	i;

	str = (char *) s;
	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= len)
		len = ft_strlen(s) - start;
	while (start-- != 0 && *str)
		str++;
	if (*str == '\0')
		return (ft_strdup(""));
	substr = (char *) malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	tmp = substr;
	while (i++ < len && *str)
		*tmp++ = *str++;
	*tmp = '\0';
	return (substr);
}
