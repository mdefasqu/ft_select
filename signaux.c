/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:33:31 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/07 17:20:06 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	in_resize(int signo)
{
	char	buffer[2];

	buffer[0] = -62;
	buffer[1] = '\0';
	ioctl(2, TIOCSTI, buffer);
	(void)signo;
}

void	handler(int signo)
{
	if (signo == SIGTSTP)
	{
		ft_putstr_fd("\033[?1049l", *globale_fd(false));
		reset_terminal();
		close(*globale_fd(true));
		signal(SIGTSTP, SIG_DFL);
		raise(signo);
		return ;
	}
	if (signo == SIGCONT)
	{
		signal(SIGTSTP, handler);
		init_terminal(globale_fd(true));
		print_in_shell(*globale_arg(NULL, 0, false), globale_fd(false));
	}
	(void)signo;
}

void	catch_signal(void)
{
	signal(3, handler);
	signal(SIGTSTP, handler);
	signal(SIGCONT, handler);
	signal(SIGINT, handler);
	signal(SIGWINCH, &in_resize);
}
