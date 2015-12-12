/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_in_list_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:09:14 by mdezitte          #+#    #+#             */
/*   Updated: 2015/12/03 17:34:33 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_list			*new_list_item(const char *titre)
{
	t_list	*item;

	item = (t_list *)malloc(sizeof(t_list));
	item->titre = ft_strdup(titre);
	item->is_selected = false;
	item->is_active = false;
	item->next = NULL;
	item->prev = NULL;
	return (item);
}

size_t			max_len_in_list(const t_list *list)
{
	size_t		i;

	i = 0;
	while (list)
	{
		if (i < ft_strlen(list->titre))
			i = ft_strlen(list->titre);
		list = list->next;
	}
	return (i);
}

void			selected(t_list **arg)
{
	t_list *change;

	change = *arg;
	while (change)
	{
		if (change->is_active == true)
		{
			change->is_selected = (change->is_selected) ? false : true;
			change_active(4, arg);
			break ;
		}
		change = change->next;
	}
}
