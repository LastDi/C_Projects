/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:18:45 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/21 21:25:04 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *) s1;
	str2 = (char *) s2;
	if (n == 0)
		return (0);
	while (((unsigned char) *str1 == (unsigned char) *str2) && n-- > 0)
	{
		str1++;
		str2++;
		if (n == 0)
			return (0);
	}
	return ((unsigned char) *str1 - (unsigned char) *str2);
}
