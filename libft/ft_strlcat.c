/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:49:17 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/23 19:35:23 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	char	*dest;

	i = 0;
	dest = dst;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= n)
		return (n + src_len);
	while (*dest != '\0' && i++ < n - 1)
		dest++;
	while (*src != '\0' && i < n - 1)
	{
		*dest++ = *src++;
		i++;
	}
	if (i < n)
		*dest = '\0';
	return (dst_len + src_len);
}
