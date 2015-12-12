/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terms_values_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:42:27 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/07 16:16:31 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

bool	is_resize(const char *buffer)
{
	if (buffer[0] == -62)
		return (true);
	else
		return (false);
}

bool	is_home(const char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 72)
		return (true);
	else
		return (false);
}

bool	is_end(const char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 70)
		return (true);
	else
		return (false);
}

bool	is_alpha(const char *buffer)
{
	if (buffer[0] > 96 && buffer[0] < 123 && buffer[1] == 0 && buffer[2] == 0)
		return (true);
	else
		return (false);
}
