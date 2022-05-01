/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <oalvera@student.21-school.r       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 01:13:48 by oalvera           #+#    #+#             */
/*   Updated: 2021/10/23 20:57:50 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*begin;
	int		flag;
	void	*cont;

	if (!lst || !f)
		return (NULL);
	flag = 0;
	while (lst)
	{
		cont = f(lst->content);
		new = ft_lstnew(cont);
		if (!new)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		if (flag++ == 0)
			begin = new;
		else
			ft_lstadd_back(&begin, new);
		lst = lst->next;
	}
	return (begin);
}
