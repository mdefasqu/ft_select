/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_arrow_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:14:57 by mdezitte          #+#    #+#             */
/*   Updated: 2015/12/02 17:33:49 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void		check_active_2(int *marqueur, const int move, t_list **change)
{
	if (move == LEFT)
		move_left(change, marqueur);
}

static void		check_active(t_list **change, const int move,
					t_list **arg, int *marqueur)
{
	t_list *tmp;

	while (*change)
	{
		if ((*change)->is_active == true)
		{
			check_active_2(marqueur, move, change);
			if (move == RIGHT)
			{
				move_right(change, marqueur);
				break ;
			}
			if (move == UP)
				move_up(change, &tmp, arg);
			if (move == DOWN)
			{
				move_down(change, &tmp, arg);
				break ;
			}
		}
		if ((*change)->next)
			*change = (*change)->next;
		else
			break ;
	}
}

void			change_active(const int move, t_list **arg)
{
	t_list	*change;
	int		marqueur;

	change = *arg;
	marqueur = 0;
	check_active(&change, move, arg, &marqueur);
	if (marqueur == 1)
		change->is_active = true;
	else if (marqueur == 2)
		(*arg)->is_active = true;
}
