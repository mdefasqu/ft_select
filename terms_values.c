/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terms_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:58:28 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/07 11:12:18 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

bool	is_echap(const char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 0 && buffer[2] == 0)
		return (true);
	else
		return (false);
}

bool	is_up(const char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65)
		return (true);
	else
		return (false);
}

bool	is_down(const char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66)
		return (true);
	else
		return (false);
}

bool	is_left(const char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68)
		return (true);
	else
		return (false);
}

bool	is_right(const char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67)
		return (true);
	else
		return (false);
}
