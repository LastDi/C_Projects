/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:28:29 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/22 21:23:12 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char *big, char *little, size_t len)
{
	while (*big && *big == *little && len > 0)
	{	
		len--;
		big++;
		little++;
	}
	if (*little == '\0')
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!*little)
		return ((char *) big);
	if (len == 0)
		return (NULL);
	while (*big && len > 0)
	{
		if (*big == *little)
		{
			if (ft_check((char *) big, (char *) little, len) == 1)
				return ((char *) big);
		}
		big++;
		len--;
	}
	return (NULL);
}
