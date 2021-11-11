/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:00:16 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/22 21:10:13 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;
	int		res;

	i = 0;
	str1 = (char *) s1;
	str2 = (char *) s2;
	while ((*str1 || *str2) && (i++ < n))
	{
		if (*str1 != *str2)
		{
			res = (unsigned char) *str1 - (unsigned char) *str2;
			return (res);
		}
		str1++;
		str2++;
	}
	return (0);
}
