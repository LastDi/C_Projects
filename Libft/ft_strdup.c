/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:11:10 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/20 06:05:32 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		len;
	char	*tmp;
	char	*strdup;

	len = 0;
	tmp = src;
	while (*tmp++)
		len++;
	strdup = malloc((len + 1) * sizeof(char));
	tmp = strdup;
	if (strdup != NULL)
	{
		while (*src)
			*tmp++ = *src++;
		*tmp = '\0';
	}
	return (strdup);
}
