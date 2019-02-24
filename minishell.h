/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:53:34 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/24 05:47:27 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <dirent.h>
# include "libft/libft.h"
# include <sys/stat.h>
# include <errno.h>
# include <sys/wait.h>
# include <stdio.h>
# include <termios.h>
# define HIDE_CURSOR "\e[?25l"
# define SHOW_CURSOR "\e[?25h"
# define CLEAR_LINE "\33[2K\r"
# define MV_CURSOR "\033[D"
# define UP 'A'
# define DOWN 'B'
# define LEFT 'D'
# define RIGHT 'C'

int					g_waiting_child;
char				*g_line;
typedef char		t_bool;
typedef struct stat	t_stat;
typedef struct		s_env
{
	char			*key;
	char			*value;
}					t_env;
typedef struct		s_params
{
	t_list			*env;
	char			**args;
	struct termios	mode;
	t_list			*history;
	int				pos;
	int				history_pos;
	t_bool			preview_mode;
	char			*pwd;
}					t_params;
void				ft_parse_env(char **env, t_params *params);
void				ft_setenv(char *key, char *value, t_params *params);
void				ft_env(t_list *list);
char				**ft_getpaths(t_list *list);
char				*ft_pwd();
void				ft_cd(char *location, t_params *params);
t_stat				*ft_exist(char *file);
char				*ft_find_file(char *file, t_list *list);
void				ft_execute(char *cmd, t_params *params);
void				ft_parse(char *command, t_params *params);
void				ft_catch(int signal);
char				**ft_get_env(t_list *list);
char				*ft_get_env_key(char *key, t_list *list);
char				*ft_remove_wsapces(char *str);
int					ft_isbuilt_in(char *name);
void				ft_built_in(char *name, t_params *params, char **cmd);
void				ft_echo(t_params *params);
char				*ft_joinargs(char **str, char *result);
char				*ft_delchar(char **str, int index);
char				*ft_insertchar(char **str, char c, int index);
void				ft_unsetenv(char *key, t_params *params);
char				*ft_gethome(char *str, t_params *params);
char				*ft_strcut(char **str, int i0, int i1);
char				*ft_str_insert(char **str1, char *filler, int index);
char				*ft_getvars(char *str, t_params *params);
void				ft_getcommands(char *str, t_params *params);
t_stat				*ft_exist(char *file);
void				ft_setup_terminal(void);
char				*ft_getline(t_params *params);
char				*ft_autocomplete(char *str, t_params *params,
									t_bool preview_mode);
void				ft_putstr2(char *str, t_params *params,
									t_bool preview_mode);
void				ft_history(t_list *history);
void				ft_addhistory(char *str, t_list **history);
void				ft_atexit(t_params *params);
void				ft_browshistory(char **str, char direction,
									t_params *params);
int					ft_is_arrow(char c, char *last, t_params *params,
									char **str);
char				*ft_getprefix(char *str);
char				*ft_find_in_dir(char *path, char *part0);
char				*ft_find_in_path(char *part0, t_params *params);
char				*ft_complete_dir(char *fullpart, t_params *params);
char				*ft_find_in_builtins(char *tool);
int					ft_is_exec(char *file, char *path);
void				ft_put_to_stdin(char *str, t_params *params,
									t_bool preview_mode);
char				*ft_backspace(char *str, t_params *params);
char				*ft_remove_wsapces(char *str);
void				ft_reset_terminal(struct termios mode);
char				*ft_get_parent_dir(char *dir);
void				ft_init(t_params *params, char **env);
#endif
