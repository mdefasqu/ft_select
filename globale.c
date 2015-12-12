/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:33:31 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/07 16:49:58 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

struct termios				*globale_save(bool set)
{
	static struct termios	save;

	if (set)
	{
		if (tcgetattr(0, &save) == -1)
			return (NULL);
		else
			return (&save);
	}
	else
		return (&save);
}

t_list						**globale_arg(char **argv, int argc, bool set)
{
	static t_list	*arg;

	if (set)
	{
		arg = get_list(argv, argc);
		arg->is_active = true;
		return (&arg);
	}
	else
		return (&arg);
}

int							*globale_fd(bool set)
{
	static int				fd;

	if (set)
	{
		fd = open("/dev/tty", O_RDWR);
		return (&fd);
	}
	else
		return (&fd);
}
