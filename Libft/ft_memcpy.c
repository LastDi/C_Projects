/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 04:59:00 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/23 19:50:55 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;
	char	*source;
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	str = (char *) dest;
	source = (char *) src;
	while (i++ < n)
		*str++ = *source++;
	return (dest);
}
