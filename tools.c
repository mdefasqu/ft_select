/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:15:54 by mdezitte          #+#    #+#             */
/*   Updated: 2015/12/07 11:14:59 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		selected_all(t_list **arg, bool select)
{
	t_list *change;

	change = *arg;
	while (change)
	{
		if (select == true)
			change->is_selected = true;
		if (select == false)
			change->is_selected = false;
		change = change->next;
	}
}

t_list		*get_list(char **argv, int argc)
{
	t_list	*list;
	t_list	*to_add;
	int		i;

	i = 1;
	list = NULL;
	while (i < argc)
	{
		to_add = new_list_item(argv[i]);
		add_to_list(&list, to_add);
		i++;
	}
	return (list);
}

void		print_selected(t_list *list)
{
	bool	preums;

	preums = true;
	while (list)
	{
		if (list->is_selected == true)
		{
			if (preums == false)
				ft_putstr(" ");
			else
				preums = false;
			ft_putstr(list->titre);
		}
		list = list->next;
	}
}

int			len_list(const t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

bool		is_too_small(const t_list *arg)
{
	size_t	i;
	size_t	size_h;
	size_t	size_v;
	size_t	nb_per_line;
	size_t	lengh_list;

	size_v = get_terminal_height();
	size_h = get_terminal_width();
	i = max_len_in_list(arg);
	if (((size_v - 1) / i) < 1)
		return (false);
	i += 1;
	nb_per_line = size_v / i;
	lengh_list = len_list(arg);
	if (lengh_list < nb_per_line * (size_h - 1))
		return (false);
	return (true);
}
