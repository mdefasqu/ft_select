/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:33:31 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/07 16:51:19 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		main(int argc, char **argv, const char **env)
{
	int					*fd;

	fd = globale_fd(true);
	if (!check_arg(argc, argv, env))
		return (0);
	init_terminal(fd);
	catch_signal();
	globale_arg(argv, argc, true);
	read_termcaps(globale_arg(NULL, 0, false), fd);
	reset_terminal();
	free_list(globale_arg(NULL, 0, false));
	return (0);
}
