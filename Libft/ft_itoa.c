/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 05:15:22 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/23 19:32:51 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_str(int n, int kdiv, size_t len)
{
	int		res;
	char	*str;
	char	*tmp;

	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	tmp = str;
	if (n < 0)
		*tmp++ = '-';
	while (kdiv != 0)
	{
		res = n / kdiv;
		*tmp++ = res + '0';
		n %= kdiv;
		kdiv /= 10;
	}
	*tmp = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		kdiv;
	int		tmp;
	size_t	len;
	char	*res;

	kdiv = 1;
	len = 0;
	tmp = n;
	if (n < 0)
	{
		kdiv = -1;
		len++;
	}
	while (tmp / 10 != 0)
	{
		kdiv *= 10;
		tmp /= 10;
		len++;
	}
	len++;
	res = ft_create_str(n, kdiv, len);
	return (res);
}
