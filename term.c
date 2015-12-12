/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:58:28 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/07 16:02:40 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		ft_print(int c)
{
	int		fd;

	fd = open("/dev/tty", O_RDWR);
	ft_putchar_fd(c, fd);
	close(fd);
	return (0);
}

int		init_terminal(int *fd)
{
	struct termios	term;
	const char		*name_term;
	char			*res;

	ft_putstr_fd("\033[?1049h\033[H", *fd);
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	if (globale_save(true) == NULL)
		return (-1);
	init_terminal_icanon(&term);
	if (tcsetattr(2, TCSADRAIN, &term) == -1)
		return (-1);
	if ((res = tgetstr("cl", NULL)) == NULL)
		return (-1);
	tputs(res, 0, ft_print);
	if ((res = tgetstr("vi", NULL)) == NULL)
		return (-1);
	tputs(res, 0, ft_print);
	return (0);
}

int		reset_terminal(void)
{
	char			*res;
	struct termios	*save;

	if ((res = tgetstr("ve", NULL)) == NULL)
		return (-1);
	tputs(res, 0, ft_print);
	if ((save = globale_save(false)) == NULL)
		return (-1);
	else
		tcsetattr(0, 0, save);
	return (0);
	(void)save;
}

int		condition_termcap(t_list **arg, char *buffer, int *fd)
{
	if (is_resize(buffer))
		;
	else if (is_right(buffer))
		change_active(RIGHT, arg);
	else if (is_left(buffer))
		change_active(LEFT, arg);
	else if (is_up(buffer))
		change_active(UP, arg);
	else if (is_down(buffer))
		change_active(DOWN, arg);
	else if (is_delete(buffer))
		return (delete_elem(arg, *fd));
	else if (is_space(buffer))
		selected(arg);
	else if (is_enter(buffer))
		return (quit_with_enter(fd, *arg));
	else
		condition_termcap_2(arg, buffer);
	if (is_alpha(buffer))
		search_catch(true, buffer, arg);
	else
		search_catch(false, buffer, arg);
	return (1);
}

int		read_termcaps(t_list **arg, int *fd)
{
	char	buffer[3];
	char	*res;

	while (1)
	{
		ft_bzero(buffer, 3);
		if (is_too_small(*arg) == false)
			print_in_shell(*arg, fd);
		else
			ft_putendl_fd("Too Small", *fd);
		read(0, buffer, 3);
		if (is_echap(buffer))
		{
			ft_putstr_fd("\033[?1049l", *fd);
			close(*fd);
			return (0);
		}
		if (condition_termcap(arg, buffer, fd) == 0)
			return (0);
		if ((res = tgetstr("cl", NULL)) == NULL)
			return (-1);
		tputs(res, 0, ft_print);
	}
	return (0);
}
