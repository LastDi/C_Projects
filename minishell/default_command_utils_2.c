/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_command_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:29:13 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:29:15 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_change1(t_list **evl, t_list **l1)
{
	t_list	*l2;
	t_list	*l3;

	l2 = (*l1)->next;
	l3 = l2->next;
	*evl = l2;
	(*l1)->next = l3;
	l2->next = (*l1);
}

void	sort_change2(t_list **ll1)
{
	t_list	*l2;
	t_list	*l3;
	t_list	*l4;
	t_list	*l1;

	l1 = *ll1;
	l2 = l1->next;
	l3 = l2->next;
	l4 = l3->next;
	l1->next = l3;
	l2->next = l4;
	l3->next = l2;
}

void	ft_sort_easy(t_list **evl)
{
	t_list	*l1;
	char	*h;
	int		mas[5];

	mas[0] = sort_count(evl);
	while (mas[0] > 0)
	{
		mas[1] = mas[0] + 1;
		mas[3] = 0;
		while (mas[1] > 0)
		{
			l1 = *evl;
			mas[2] = 0;
			while (++mas[2] < mas[3])
				l1 = l1->next;
			h = (char *)(l1->next->content);
			if (mas[3] == 0 && who_is_more((char *)(l1->content), h) > 0)
				sort_change1(evl, &l1);
			else if (who_is_more(h, (char *)(l1->next->next->content)) > 0)
				sort_change2(&l1);
			mas[3]++;
			mas[1]--;
		}
		mas[0]--;
	}
}

void	print_export_error(char *str)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

int	parsing_export(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (!ft_isalpha(str[i]) && str[i] != '_')
	{
		print_export_error(str);
		return (0);
	}
	if (str[i] == '_' && (str[i + 1] == '\0' || str[i + 1] == '='))
		return (0);
	i++;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
		{
			print_export_error(str);
			return (0);
		}
		i++;
	}
	return (1);
}
