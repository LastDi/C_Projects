/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:38:25 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:38:28 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nlist;

	if (!new)
		return ;
	nlist = *lst;
	if (nlist == 0)
		*lst = new;
	else
	{
		while (nlist->next != 0)
			nlist = nlist->next;
		nlist->next = new;
	}
}

int	ft_strlen_sym(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nlist;

	nlist = *lst;
	while (*lst)
	{
		del((*lst)->content);
		nlist = *lst;
		*lst = (*lst)->next;
		free(nlist);
	}
	*lst = 0;
}
