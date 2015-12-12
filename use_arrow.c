/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_arrow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:27:44 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/02 17:30:52 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void			move_up(t_list **change, t_list **tmp, t_list **arg)
{
	size_t cmp;

	(*change)->is_active = false;
	cmp = nb_per_line(*arg);
	tmp = change;
	while (cmp != 0 && (*tmp)->prev)
	{
		*tmp = (*tmp)->prev;
		cmp--;
	}
	if (*tmp)
		(*tmp)->is_active = true;
	else
		(*change)->is_active = true;
}

void			move_left(t_list **change, int *marqueur)
{
	(*change)->is_active = false;
	if ((*change)->prev)
		(*change)->prev->is_active = true;
	else
		(*marqueur) = 1;
}

void			move_down(t_list **change, t_list **tmp, t_list **arg)
{
	size_t cmp;

	(*change)->is_active = false;
	cmp = nb_per_line(*arg);
	tmp = change;
	while (cmp != 0 && (*tmp)->next)
	{
		*tmp = (*tmp)->next;
		cmp--;
	}
	if (*tmp)
		(*tmp)->is_active = true;
	else
		(*change)->is_active = true;
}

void			move_right(t_list **change, int *marqueur)
{
	(*change)->is_active = false;
	if ((*change)->next)
		(*change)->next->is_active = true;
	else
		(*marqueur) = 2;
}
