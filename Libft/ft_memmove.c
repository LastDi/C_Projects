/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 05:16:18 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/23 19:51:58 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*dst;
	char	*sorc;

	dst = (char *) dest;
	sorc = (char *) src;
	if (!dest && !src)
		return (NULL);
	if (sorc < dst)
	{
		i = len;
		while (i-- > 0)
			dst[i] = sorc[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst[i] = sorc[i];
			i++;
		}
	}
	return (dest);
}
