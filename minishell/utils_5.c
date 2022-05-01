/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:38:33 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:38:35 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	x;
	int	sign;
	int	max;

	max = 19;
	sign = 1;
	i = 0;
	x = 0;
	while (((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)) && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (!max--)
			return ((1 + sign) / (-2));
		x = x * 10 + str[i] - '0';
		i++;
	}
	return (x * sign);
}

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
