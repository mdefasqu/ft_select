/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_in_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:10:01 by mdezitte          #+#    #+#             */
/*   Updated: 2015/12/04 16:09:01 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void			add_to_list(t_list **list, t_list *to_add)
{
	t_list	*begin;

	if (!list || !to_add)
		return ;
	begin = *list;
	if (!begin)
		*list = to_add;
	else
	{
		while (begin->next)
			begin = begin->next;
		begin->next = to_add;
		to_add->prev = begin;
	}
}

t_list			*find_is_active(t_list **list)
{
	t_list	*find;

	find = *list;
	if (list == NULL)
		return (NULL);
	while (find->next)
	{
		if (find->is_active == true)
			return (find);
		find = find->next;
	}
	return (NULL);
}

static void		del_to_list_three(t_list **list, const t_list *begin)
{
	*list = begin->next;
	(*list)->prev = NULL;
	(*list)->is_active = true;
}

static void		del_to_list_two(t_list **begin, t_list **next)
{
	(*begin)->next = (*next)->next;
	if ((*next)->next)
		(*next)->next->prev = (*next)->prev;
	free_item(*next);
	*next = (*begin)->next;
	if ((*next) != NULL)
		(*next)->is_active = true;
	else
		(*begin)->is_active = true;
}

void			del_to_list(t_list **list)
{
	t_list *begin;
	t_list *next;

	if (!list)
		return ;
	begin = *list;
	next = begin->next;
	if (begin->is_active == true)
	{
		if (begin->next != NULL)
			del_to_list_three(list, begin);
		free_item(begin);
		return ;
	}
	while (next)
	{
		if (next->is_active == true)
			return (del_to_list_two(&begin, &next));
		else
		{
			next = next->next;
			begin = begin->next;
		}
	}
}
