/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:25:35 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/07 16:17:28 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	select_home(t_list **arg)
{
	t_list *tmp;

	tmp = *arg;
	tmp->is_active = true;
	if (tmp->next)
		tmp = tmp->next;
	while (tmp && len_list(*arg) > 1)
	{
		if (tmp->is_active == true)
			tmp->is_active = false;
		tmp = tmp->next;
	}
}

void	select_end(t_list **arg)
{
	t_list	*tmp;

	tmp = *arg;
	while (tmp->next)
	{
		if (tmp->is_active == true)
			tmp->is_active = false;
		tmp = tmp->next;
	}
	tmp->is_active = true;
}

void	clear_active(t_list **arg)
{
	t_list *tmp;

	tmp = *arg;
	while (tmp)
	{
		if (tmp->is_active == true)
			tmp->is_active = false;
		tmp = tmp->next;
	}
}

int		delete_elem(t_list **arg, int fd)
{
	if (len_list(*arg) > 1)
		del_to_list(arg);
	else
	{
		ft_putstr_fd("\033[?1049l", fd);
		close(fd);
		return (0);
	}
	return (1);
}
