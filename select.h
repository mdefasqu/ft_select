/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 18:31:41 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/07 17:19:56 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include "libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <stdio.h>
# include <fcntl.h>
# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <curses.h>
# include <signal.h>

# define UP 1
# define DOWN 3
# define LEFT 2
# define RIGHT 4

typedef struct		s_list
{
	char			*titre;
	bool			is_selected;
	bool			is_active;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

void				handler(int signo);

/*
** Action_in_list.c
*/
void				add_to_list(t_list **list, t_list *to_add);
void				del_to_list(t_list **list);
t_list				*new_list_item(const char *titre);
t_list				*find_is_active(t_list **list);

/*
** Action_in_list_2.c
*/
size_t				max_len_in_list(const t_list *list);
void				selected(t_list **arg);

/*
** Free_list.c
*/
void				free_item(t_list *list);
void				free_list(t_list **arg);

/*
** Use_arrow_2.c
*/
void				change_active(const int move, t_list **arg);

/*
** Use_arrow.c
*/
void				move_up(t_list **change, t_list **tmp, t_list **arg);
void				move_left(t_list **change, int *marqueur);
void				move_down(t_list **change, t_list **tmp, t_list **arg);
void				move_right(t_list **change, int *marqueur);

/*
** Size.c
*/
int					get_terminal_width(void);
int					get_terminal_height(void);

/*
** Tools.c
*/
void				selected_all(t_list **arg, const bool select);
int					len_list(const t_list *list);
void				print_selected(t_list *list);
bool				is_too_small(const t_list *arg);
t_list				*get_list(char **argv, int argc);

/*
** Tools_2.c
*/
void				select_end(t_list **arg);
void				select_home(t_list **arg);
void				clear_active(t_list **arg);
int					delete_elem(t_list **arg, int fd);

/*
** Print.c
*/
size_t				nb_per_line(const t_list *arg);
void				print_in_shell(const t_list *arg, int *fd);

/*
** Term.c
*/
int					ft_print(int c);
int					init_terminal(int *fd);
int					reset_terminal();
int					read_termcaps(t_list **arg, int *fd);

/*
** Terms_2.c
*/
void				init_terminal_icanon(struct termios *term);
void				condition_termcap_2(t_list **arg, char *buffer);
int					quit_with_enter(int *fd, t_list *arg);
void				search_catch(bool param, char *buffer, t_list **arg);

/*
** terms_values.c
*/
bool				is_echap(const char *buffer);
bool				is_up(const char *buffer);
bool				is_down(const char *buffer);
bool				is_left(const char *buffer);
bool				is_right(const char *buffer);

/*
** terms_values_2.c
*/
bool				is_space(const char *buffer);
bool				is_enter(const char *buffer);
bool				is_delete(const char *buffer);
bool				is_point_dexclamation(const char *buffer);
bool				is_arobase(const char *buffer);

/*
** terms_values_3.c
*/
bool				is_resize(const char *buffer);
bool				is_home(const char *buffer);
bool				is_end(const char *buffer);
bool				is_alpha(const char *buffer);

/*
** Error.c
*/
bool				check_env(const char **env);
bool				check_arg(int argc, char **argv, const char **env);

/*
** Globale.c
*/
struct termios		*globale_save(bool set);
t_list				**globale_arg(char **argv, int argc, bool set);
int					*globale_fd(bool set);

/*
** Signaux.c
*/
void				in_resize(int signo);
void				handler(int signo);
void				catch_signal(void);

#endif
