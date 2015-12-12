/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terms_values_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:58:28 by mdezitte          #+#    #+#             */
/*   Updated: 2015/12/07 11:12:09 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

bool	is_space(const char *buffer)
{
	if (buffer[0] == 32 && buffer[1] == 0 && buffer[2] == 0)
		return (true);
	else
		return (false);
}

bool	is_enter(const char *buffer)
{
	if (buffer[0] == 10 && buffer[1] == 0 && buffer[2] == 0)
		return (true);
	else
		return (false);
}

bool	is_delete(const char *buffer)
{
	if ((buffer[0] == 127 && buffer[1] == 0 && buffer[2] == 0) ||
		(buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 51))
		return (true);
	else
		return (false);
}

bool	is_point_dexclamation(const char *buffer)
{
	if (buffer[0] == 33 && buffer[1] == 0 && buffer[2] == 0)
		return (true);
	else
		return (false);
}

bool	is_arobase(const char *buffer)
{
	if (buffer[0] == 64 && buffer[1] == 0 && buffer[2] == 0)
		return (true);
	else
		return (false);
}
