/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:03:56 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/04 16:17:58 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		free_item(t_list *list)
{
	free(list->titre);
	list->titre = NULL;
	free(list);
	list = NULL;
}

void		free_list(t_list **arg)
{
	t_list	*tmp;

	tmp = *arg;
	while (*arg)
	{
		*arg = (*arg)->next;
		free_item(tmp);
		tmp = *arg;
	}
}
