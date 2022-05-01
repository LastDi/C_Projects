/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:03:38 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/21 21:44:27 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *) s;
	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	while (i >= 0)
	{		
		if (*str == (unsigned char) c)
			return (str);
		str--;
		i--;
	}
	return (NULL);
}
