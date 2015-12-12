/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:17:23 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/07 16:19:55 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void			init_terminal_icanon(struct termios *term)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
}

int				quit_with_enter(int *fd, t_list *arg)
{
	ft_putstr_fd("\033[?1049l", *fd);
	close(*fd);
	print_selected(arg);
	return (0);
}

void			condition_termcap_2(t_list **arg, char *buffer)
{
	if (is_home(buffer))
		select_home(arg);
	else if (is_end(buffer))
		select_end(arg);
	else if (is_point_dexclamation(buffer))
		selected_all(arg, true);
	else if (is_arobase(buffer))
		selected_all(arg, false);
}

static bool		select_search(t_list **arg, char *cmd)
{
	t_list	*tmp;
	bool	is_finish;

	tmp = *arg;
	is_finish = false;
	while (tmp)
	{
		if (ft_strncmp(tmp->titre, cmd, ft_strlen(cmd)) == 0)
		{
			clear_active(arg);
			tmp->is_active = true;
			is_finish = true;
			break ;
		}
		tmp = tmp->next;
	}
	if (is_finish == false)
		return (false);
	return (true);
}

void			search_catch(bool param, char *buffer, t_list **arg)
{
	static char *cmd = NULL;
	char		*tmp;

	buffer[1] = '\0';
	if (param == true)
	{
		if (cmd == NULL)
		{
			cmd = (char *)malloc(sizeof(char) * 2);
			cmd[0] = buffer[0];
			cmd[1] = '\0';
		}
		else
		{
			tmp = ft_strdup(cmd);
			ft_strdel(&cmd);
			cmd = ft_strjoin(tmp, buffer);
			ft_strdel(&tmp);
		}
		if (select_search(arg, cmd) == false)
			ft_strdel(&cmd);
	}
	else
		ft_strdel(&cmd);
}
