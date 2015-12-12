/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:00:19 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/02 16:06:24 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

bool	check_env(const char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "TERM=", 5) == 0)
			return (true);
		i++;
	}
	return (false);
}

bool	check_arg(int argc, char **argv, const char **env)
{
	if (!argv || argc == 1)
		return (false);
	if (argc == 2)
	{
		ft_putstr(argv[1]);
		return (false);
	}
	if (check_env(env) == false)
	{
		ft_putendl("TERM non valide");
		return (false);
	}
	return (true);
}
