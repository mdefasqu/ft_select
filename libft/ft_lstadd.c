/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:18:12 by mdezitte          #+#    #+#             */
/*   Updated: 2015/09/18 13:17:35 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstadd(t_list_libft **alst, t_list_libft *news)
{
	if (!news || !alst)
		return ;
	news->next = *alst;
	*alst = news;
}
