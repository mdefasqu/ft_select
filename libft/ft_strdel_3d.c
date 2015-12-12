/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 14:50:13 by mdezitte          #+#    #+#             */
/*   Updated: 2015/10/30 14:50:14 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strdel_3d(char ****tab)
{
	int i;
	int y;

	i = 0;
	while ((*tab)[i])
	{
		y = 0;
		while ((*tab)[i][y])
		{
			ft_strdel(&(*tab)[i][y]);
			y++;
		}
		i++;
	}
}
