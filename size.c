/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:52:40 by mdezitte          #+#    #+#             */
/*   Updated: 2015/12/02 15:52:53 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		get_terminal_width(void)
{
	struct winsize	w;
	int				ret;

	ioctl(0, TIOCGWINSZ, &w);
	ret = w.ws_row;
	return (ret);
}

int		get_terminal_height(void)
{
	struct winsize	w;
	int				ret;

	ioctl(0, TIOCGWINSZ, &w);
	ret = w.ws_col;
	return (ret);
}
