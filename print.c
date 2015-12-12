/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:37:28 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/08 10:58:33 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void		check_color_type(const char *titre, int *fd)
{
	char	c;

	c = get_file_type(titre);
	if (c == '-')
		ft_putstr_fd("\033[32m", *fd);
	else if (c == 'd')
		ft_putstr_fd("\033[36m", *fd);
	else if (c == 'c')
		ft_putstr_fd("\033[31m", *fd);
	else if (c == 'b')
		ft_putstr_fd("\033[33m", *fd);
	else if (c == 'p')
		ft_putstr_fd("\033[35m", *fd);
	else if (c == 'l')
		ft_putstr_fd("\033[34m", *fd);
	else if (c == 's')
		ft_putstr_fd("\033[37m", *fd);
	ft_putstr_fd(titre, *fd);
	ft_putstr_fd("\033[0m", *fd);
	(void)fd;
}

size_t			nb_per_line(const t_list *arg)
{
	size_t	i;
	size_t	size_v;
	size_t	nb_per_line;

	size_v = get_terminal_height();
	i = max_len_in_list(arg);
	i += 1;
	nb_per_line = size_v / i;
	return (nb_per_line);
}

static void		print_space(const size_t max_len, size_t len, int *fd)
{
	while (len < max_len + 1)
	{
		ft_putchar_fd(' ', *fd);
		len++;
	}
	(void)fd;
}

static	void	print_titre(const char *titre, bool active,
					bool select, int *fd)
{
	char	*res;

	if (active == true)
	{
		if ((res = tgetstr("us", NULL)) == NULL)
			return ;
		tputs(res, 0, ft_print);
	}
	if (select == true)
	{
		if ((res = tgetstr("mr", NULL)) == NULL)
			return ;
		tputs(res, 0, ft_print);
	}
	check_color_type(titre, fd);
	if (active == true || select == true)
	{
		if ((res = tgetstr("me", NULL)) == NULL)
			return ;
		tputs(res, 0, ft_print);
	}
}

void			print_in_shell(const t_list *arg, int *fd)
{
	size_t	i;
	size_t	cmp;
	size_t	nb_word_line;

	i = max_len_in_list(arg);
	nb_word_line = nb_per_line(arg);
	while (arg)
	{
		cmp = 1;
		while (cmp <= nb_word_line && arg)
		{
			print_titre(arg->titre, arg->is_active, arg->is_selected, fd);
			print_space(i, ft_strlen(arg->titre), fd);
			arg = arg->next;
			cmp++;
		}
		ft_putstr_fd("\n", *fd);
	}
	(void)fd;
}
