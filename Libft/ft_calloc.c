/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:23:34 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/20 06:02:14 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t size_arr, size_t elem_size)
{
	void	*res_alloc;
	size_t	res;
	char	*tmp;

	res_alloc = malloc(size_arr * elem_size);
	if (res_alloc == NULL)
		return (NULL);
	tmp = (char *) res_alloc;
	res = size_arr * elem_size;
	while (res-- > 0)
		*tmp++ = 0;
	return (res_alloc);
}
