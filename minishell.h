/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:53:34 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/19 05:16:01 by sid-bell         ###   ########.fr       */
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

int					g_waiting;
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
char				*ft_delchar(char *str, int index);
int					ft_isbuilt_in(char *name);
void				ft_built_in(char *name, t_params *params);
void				ft_echo(t_params *params);
char				*ft_joinargs(char *str);
char				*ft_delchar(char *str, int index);
char				*ft_insertchar(char *str, char c, int index);
void				ft_unsetenv(char *key, t_params *params);
char				*ft_gethome(char *str, t_params *params);
char				*ft_strcut(char *str, int i0, int i1);
char				*ft_str_insert(char *str1, char *filler, int index);
char				*ft_getvars(char *str, t_params *params);
void				ft_getcommands(char *str, t_params *params);
t_stat				*ft_exist(char *file);
void				ft_setup_terminal(void);
char				*ft_getline(t_params *params);
char				*ft_autocomplete(char *str, t_params *params);
void				ft_putstr2(char *str);
#endif
